//
// Created by ortal on 12/01/2020.
//

#include "MyTestClientHandler.h"
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
using namespace std;

void MyTestClientHandler::handleClient(int client_socket) {
    cout<< "testClientHandler" <<endl;
    int valRead = 0;
    while (true){
        char line[100000] = {0};
        valRead = read(client_socket, line, 100000);
        if (valRead < 0) {
            cout<< "Error reading" <<endl;
            break;
        }
        if(strcmp(line, "end") == 0) {
            close(client_socket);
            return;
        }
        string solution;
        if (this->cm->inCache(line)){
            solution = this->cm->get(line);
        } else {
            solution = this->solver->solve(line);
            this->cm->insert(line, solution);
        }
        int sent = send(client_socket, solution.c_str(), strlen(solution.c_str()),0);
        if (sent == -1) {
            cout<< "Error sending" <<endl;
        }
    }
}

