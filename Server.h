#ifndef EX4_SERVER_H
#define EX4_SERVER_H


#include "ClientHandler.h"
namespace server_side {
    template <typename T, typename S>
    class Server {
    public: 
        /**
         * opens a port on the port given.
         */
        virtual void open(int port, ClientHandler<T,S>* clientHandler) = 0;
        /**
         * stop running of server.
         */
        virtual void stop() = 0;
    };
}

#endif //EX4_MYSERIALSERVER_H

