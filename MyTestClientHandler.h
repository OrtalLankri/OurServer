
#ifndef OURSERVER_MYTESTCLIENTHANDLER_H
#define OURSERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>

using namespace std;

class MyTestClientHandler: public ClientHandler {
    Solver<string,string>* solver;
    CacheManager<string,string>* cm;
public:
    MyTestClientHandler(Solver<string, string> *slvr, CacheManager<string,string> *cacheManager) : solver(slvr), cm(cacheManager) {}
    void handleClient(int client_socket) override;
    MyTestClientHandler* clone() override;
};

#endif //OURSERVER_MYTESTCLIENTHANDLER_H
