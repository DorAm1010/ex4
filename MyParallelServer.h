//
// Created by dor on 1/17/20.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include <chrono>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include "Server.h"
#include "MyClientHandler.h"

#define TIMEOUT 120

template <typename P, typename S>

class MyParallelServer : public server_side::Server<P,S> {
    int socketfd;

public:
    void open(int port, ClientHandler<P,S>* clientHandler) {
        int client_socket;

        socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            throw "Unable To Create Socket";
        }

        //bind socket to IP address
        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr("127.0.0.1");
        address.sin_port = htons(port);
        if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
            throw "Could not bind the socket to an IP";
        }

        timeval tv{};
        tv.tv_sec = TIMEOUT;
        if(setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)))
            throw "Could not set TIMEOUT";

        if(listen(socketfd, 10) == -1) {
            throw "Error listening to clients";
        }

        // accept all clients and detach respective threads
        while ((client_socket = accept(socketfd,
                                       (struct sockaddr*) &address, (socklen_t*)&address)) != -1) {

            ClientHandler<P,S>* handler = clientHandler->clone();
            std::thread client_thread = std::thread(&ClientHandler<P,S>::handleClient, handler, client_socket);
            client_thread.detach();
        }

    }

    void stop() override {
        close(socketfd);
    }
};


#endif //EX4_MYPARALLELSERVER_H
