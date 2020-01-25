
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

using namespace std;

class MyClientHandler: public ClientHandler {
    Solver<Matrix*,string>* solver;
    CacheManager<string,string>* cm;
    Matrix* createMatrix(deque<string> lines);
public:
    MyClientHandler(Solver<Matrix*, string> *slvr, CacheManager<string,string> *cacheManager) : solver(slvr), cm(cacheManager) {}
    void handleClient(int client_socket) override;
    MyClientHandler* clone() override;
};

#endif //OURSERVER_MYCLIENTHANDLER_H
