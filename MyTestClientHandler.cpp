//
// Created by ortal on 12/01/2020.
//

#include "MyTestClientHandler.h"
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
using namespace std;

void MyTestClientHandler::handleClient(int client_socket) {
    int valRead = 0;
    while (valRead != -1){
        char line[100000] = {0};
        valRead = read(client_socket, line, 100000);
        if(line=="end") {
            return;
        }
        string solution;
        if (this->cm->inCache(line)){
            solution = this->cm->get(line);
        } else {
            solution = this->solver->solve(line);
            this->cm->insert(line, solution);
        }
        send(client_socket, solution.c_str(), strlen(solution.c_str()),0);
    }
}

MyTestClientHandler::MyTestClientHandler(Solver<string, string> *solver, CacheManager<string> *cm) : solver(solver),
                                                                                                     cm(cm) {}

