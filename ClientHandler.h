
#ifndef OURSERVER_CLIENTHANDLER_H
#define OURSERVER_CLIENTHANDLER_H

#include <iostream>
#include <fstream>
#include "Solver.h"
#include "CacheManager.h"

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int client_socket) = 0;
    virtual ClientHandler* clone()=0;
};

#endif //OURSERVER_CLIENTHANDLER_H
