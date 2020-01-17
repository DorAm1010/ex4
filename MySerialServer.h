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
#include "Server.h"

class MySerialServer : public server_side::Server {
    void open(int port, ClientHandler* clientHandler) override;
    void stop() override;
};

#endif