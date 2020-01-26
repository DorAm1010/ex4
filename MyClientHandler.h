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
/**
 * this client handler get each time a problem from client,
 * and returns the solution for the problem. this continue
 * until the client sends "end".
 */
class MyClientHandler : public ClientHandler<P,S> {
    Solver<P,S>* solver;
    CacheManager<P, S>* cacheManager;

public:

    MyClientHandler(CacheManager<P, S>* cacheManager1, Solver<P,S>* solver1) {
        solver = solver1;
        cacheManager = cacheManager1;
    }

    void handleClient(int socket) override  {
        Matrix matrix;
        int startX = 0, startY = 0, endX = 0, endY = 0;
        char input[65536] = {0};
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

            if(helper.find("end") != std::string::npos) {
                strcat(input, buffer);
                break;
            }
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

            for(int i = 0; i < size; i++){
                while(helper.at(i) != ' ' && helper.at(i) != ',' && helper.at(i) != '\r' && helper.at(i) != '\n'){
                    stringNumber += helper.at(i);
                    i++;
                    if(i >= size) {
                        break;
                    }
                }
                if(!stringNumber.empty()) {
                    matrix_rows.push_back(stoi(stringNumber));
                }
                stringNumber = "";
            }

            if (matrix_rows.size() > 2) {
                // add another row to matrix
                matrix.addRow(matrix_rows);
            } else if (!startP_defined){

                startX = matrix_rows.at(0);
                startY = matrix_rows.at(1);
                startP_defined = true;

            } else {
                endX = matrix_rows.at(0);
                endY = matrix_rows.at(1);


                MatrixProblem matrixProblem(matrix, Point(startX, startY), Point(endX, endY));

                S solution;

                if (!cacheManager->hasSolution(matrixProblem)) {
                    solution = solver->solve(matrixProblem);
                    cacheManager->saveSolution(solution, matrixProblem);
                } else {
                    solution = cacheManager->getSolution(matrixProblem);
                }

                std::string stringSolution = solution;
                send(socket, stringSolution.c_str(), stringSolution.size(), 0);
                //std::cout << solution << std::endl;
            }
        }
    }

    MyClientHandler* clone() override {
        return new MyClientHandler(this->cacheManager->clone(), this->solver->clone());
    }
};
#endif //EX4_MYCLIENTHANDLER_H
