//
// Created by dor on 1/17/20.
//
#ifndef EX4_TESTCLIENTHANDLER_H
#define EX4_TESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
//
// Created by dor on 1/14/20.
//
using namespace std;
class MyTestClientHandler : public ClientHandler {
    Solver solver;
    CacheManager* cacheManager;

//    MyTestClientHandler(Solver _solver, CacheManager<Problem, Solution> manager) {
//        solver = _solver;
//        cacheManager = &manager;
//    }
    void handleClient(int socket) override {
        string output;
        char buffer[1024];
        char* string3;

        // read from client
        int valread = read(socket, buffer, 1024);
        if (valread == -1)
            cout << "Could Not Read Client Input" << endl;

        // drop \n char
        string3 = strtok(buffer, "\n");

        // concatenate string
        for(int j = strlen(string3) - 1; j >= 0; j--) {
            output += string3[j];
        }

        cout << output << endl;
    }
};


#endif //EX4_TESTCLIENTHANDLER_H
