//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_MYTESTCLIENTHANDLER_H
#define OURSERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler: public ClientHandler {
    Solver<string,string>* solver;
    CacheManager<string>* cm;
public:
    MyTestClientHandler(Solver<string, string> *solver, CacheManager<string> *cm) : solver(solver), cm(cm) {}
    void handleClient(int client_socket) override;
};


#endif //OURSERVER_MYTESTCLIENTHANDLER_H
