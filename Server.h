#ifndef EX4_SERVER_H
#define EX4_SERVER_H


#include "ClientHandler.h"
namespace server_side {
    template <typename T, typename S>
    class Server {
    public:
        virtual void open(int port, ClientHandler<T,S>* clientHandler) = 0;
        virtual void stop() = 0;
    };
}

#endif //EX4_MYSERIALSERVER_H

