//
// Created by ortal on 20/01/2020.
//

#ifndef OURSERVER_MYPARALLELSERVER_H
#define OURSERVER_MYPARALLELSERVER_H


#include "Server.h"
using namespace server_side;

class MyParallelServer :public Server{
    int socketfdp;
public:
    static void readFromClient(int port,ClientHandler* c, int* socketfdp);
    void open(int port, ClientHandler* c) override;
    void stop() override;
};


#endif //OURSERVER_MYPARALLELSERVER_H
