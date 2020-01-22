//
// Created by ortal on 14/01/2020.
//

#ifndef OURSERVER_MYCLIENTHANDLER_H
#define OURSERVER_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <list>
#include <vector>
#include <deque>
#include "Matrix.h"
#include <mutex>

class MyClientHandler: public ClientHandler {
    Solver<Matrix*,string>* solver;
    CacheManager<string,string>* cm;
    Matrix* createMatrix(vector<string> lines);
    mutex mtx;
public:
    MyClientHandler(Solver<Matrix*, string> *solver, CacheManager<string,string> *cm) : solver(solver), cm(cm) {}
    void handleClient(int client_socket) override;
};


#endif //OURSERVER_MYCLIENTHANDLER_H
