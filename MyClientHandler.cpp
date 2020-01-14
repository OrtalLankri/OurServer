//
// Created by ortal on 14/01/2020.
//

#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <list>
#include <vector>
#include "MyClientHandler.h"

void MyClientHandler::handleClient(int client_socket) {
    int valRead = 0;
    while (valRead != -1){
        char line[100000] = {0};
        valRead = read(client_socket, line, 100000);
        vector<string> lines;
        string key = "";
        while(line != "end") {
            lines.push_back(line);
            key += line;
        }
        string solution;
        if (this->cm->inCache(key)){
            solution = this->cm->get(key);
        } else {
            solution = this->solver->solve(lines);
            this->cm->insert(key, solution);
        }
        send(client_socket, solution.c_str(), strlen(solution.c_str()),0);
    }
}