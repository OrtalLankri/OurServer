
#ifndef OURSERVER_SERVER_H
#define OURSERVER_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop() = 0;
    };
}

#endif //OURSERVER_SERVER_H


