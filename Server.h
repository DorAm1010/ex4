#ifndef EX4_SERVER_H
#define EX4_SERVER_H


#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler* clientHandler) = 0;
        virtual void stop() = 0;
    };
}

#endif //EX4_MYSERIALSERVER_H

