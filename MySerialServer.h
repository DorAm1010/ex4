//
// Created by Laliv on 14/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include <chrono>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include "Server.h"
#define TIMEOUT 120


template <typename P, typename S>
/**
 * server that connect with clients one after another.
 * it sends each client to a client handker, that will handle hom.
 */
class MySerialServer : public server_side::Server<P,S> {

    void stop() override {
        // do nothing
    }

public:
    //bool stopServer = true;
    void open(int port, ClientHandler<P,S>* clientHandler) override {
        //create socket
        int client_socket;
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1)
            throw "Unable To Create Socket";

        //bind socket to IP address
        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr("127.0.0.1");
        address.sin_port = htons(port);
        if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1)
            throw "Could not bind the socket to an IP";

        struct timeval tv{};
        tv.tv_sec = TIMEOUT;
        if(setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) == -1)
            throw "Could not set TIMEOUT";

        if(listen(socketfd, 10) == -1)
            throw "Could not listen to requests";

        //making socket listen to the port 1 client at a time
        client_socket = accept(socketfd, (struct sockaddr*) &address, (socklen_t*)&address);
        if (client_socket == -1)
            throw "Accept error";

        while (client_socket != -1) {
            std::cout<<"Server is now listening ..."<< std::endl;

            clientHandler->handleClient(client_socket);

            client_socket = accept(socketfd, (struct sockaddr*) &address, (socklen_t*)&address);
        }

        close(socketfd);
        std::cout <<"Done Listening" << std::endl;
    }
};

#endif
