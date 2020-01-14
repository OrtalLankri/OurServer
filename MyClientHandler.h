//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_MYCLIENTHANDLER_H
#define OURSERVER_MYCLIENTHANDLER_H


#include "ClientHandler.h"

class MyClientHandler: public ClientHandler {
    Solver<vector<string>,string>* solver;
    CacheManager<string>* cm;
public:
    MyClientHandler(Solver<vector<string>, string> *solver, CacheManager<string> *cm) : solver(solver), cm(cm) {}
    void handleClient(int client_socket);
};


#endif //OURSERVER_MYCLIENTHANDLER_H
