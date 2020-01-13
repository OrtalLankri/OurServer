//
// Created by ortal on 12/01/2020.
//
#include "ClientHandler.h"
bool time_out=false;

namespace server_side {
    class Server {
    public:
        virtual void open(int port) = 0;
        virtual void stop() = 0;

    };
}

