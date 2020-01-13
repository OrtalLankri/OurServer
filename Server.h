//
// Created by ortal on 12/01/2020.
//
#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port,ClientHandler c);
        void stop();

    };
}

