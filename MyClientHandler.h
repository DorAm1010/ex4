//
// Created by dor on 1/15/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <cstring>
#include <sstream>
#include <sys/socket.h>
#include "ClientHandler.h"
#include "MatrixProblem.h"
#include "Solver.h"
#include "CacheManager.h"

template <class P, class S>
class MyClientHandler : public ClientHandler<P,S> {
    Solver<P,S>* solver;
    CacheManager<P, S>* cacheManager;

public:

    MyClientHandler(CacheManager<P, S>* cacheManager1, Solver<P,S>* solver1) {
        solver = solver1;
        cacheManager = cacheManager1;
    }

    /**
    * handle client request, solve a matrix by input from client.
    **/
    void handleClient(int socket) override  {
        Matrix matrix;
        int startX = 0, startY = 0, endX = 0, endY = 0;
        char input[65536] = {0};
        // check if starting point was defined
        bool startP_defined = false;

        int valread = read(socket, input, 1024);
        if (valread == -1)
            throw "Could Not Read Client Input";


        while (true) {
            char buffer[1024] = {0};

            valread = read(socket, buffer, 1024);
            if (valread == -1)
                throw "Could Not Read Client Input";

            std::string helper(buffer);

            // keyword end indicates client entered all specified inputs
            if(helper.find("end") != std::string::npos) {
                strcat(input, buffer);
                break;
            }
            // concatenate to one input char array
            strcat(input, buffer);
            helper = "";
        }

        std::stringstream stream(input);
        std::string helper, stringNumber;
        size_t size;

        while(getline(stream, helper)) {
            std::vector<int> matrix_rows;

            if(helper.find("end") != std::string::npos)
                continue;

            size = helper.size();

            // iterate current line of input
            for(int i = 0; i < size; i++){
                // while helper.at(i) points to a number
                while(helper.at(i) != ' ' && helper.at(i) != ',' && helper.at(i) != '\r' && helper.at(i) != '\n'){
                    // concatente to a string dummy
                    stringNumber += helper.at(i);
                    i++;
                    if(i >= size) {
                        break;
                    }
                }
                // to avoid errors check if stringNumber actually contains something
                if(!stringNumber.empty()) {
                    matrix_rows.push_back(stoi(stringNumber));
                }
                stringNumber = "";
            }

            if (matrix_rows.size() > 2) {
                // add another row to matrix
                matrix.addRow(matrix_rows);
            } else if (!startP_defined){

                // set starting point
                startX = matrix_rows.at(0);
                startY = matrix_rows.at(1);
                startP_defined = true;

            } else {
                // set end point
                endX = matrix_rows.at(0);
                endY = matrix_rows.at(1);


                // set problem matrix containing client input
                MatrixProblem matrixProblem(matrix, Point(startX, startY), Point(endX, endY));

                S solution;

                if (!cacheManager->hasSolution(matrixProblem)) {
                    solution = solver->solve(matrixProblem);
                    cacheManager->saveSolution(solution, matrixProblem);
                } else {
                    solution = cacheManager->getSolution(matrixProblem);
                }

                // send solution to client
                std::string stringSolution = solution;
                send(socket, stringSolution.c_str(), stringSolution.size(), 0);
            }
        }
    }

    MyClientHandler* clone() override {
        return new MyClientHandler(this->cacheManager->clone(), this->solver->clone());
    }
};
#endif //EX4_MYCLIENTHANDLER_H
