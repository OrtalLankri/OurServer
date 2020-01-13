//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_CLIENTHANDLER_H
#define OURSERVER_CLIENTHANDLER_H
#include <iostream>
#include <fstream>

using namespace std;

class ClientHandler{
public:
    virtual int handleClient(int client_socket);
};
#endif //OURSERVER_CLIENTHANDLER_H
