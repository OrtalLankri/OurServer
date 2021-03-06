
#ifndef OURSERVER_MAIN_H
#define OURSERVER_MAIN_H

#include <iostream>
#include <unistd.h>
#include <thread>
#include "MySerialServer.h"
#include "Server.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include "StringReverser.h"
#include "Matrix.h"
#include "ObjectAdapter.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"

using namespace server_side;
using namespace std;

namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            int capacity = 10;
            CacheManager<string,string>* cm = new FileCacheManager<string>(capacity);
            Solver<Matrix*, string>* solver = new ObjectAdapter();
            ClientHandler* ch = new MyClientHandler(solver, cm);
            int port = 5600;
            if (argc > 1) {
                port = atoi(argv[1]);
            }
            Server* server = new MyParallelServer();
            server->open(port, ch);
            return 0;
        }
    };
}

#endif //OURSERVER_MAIN_H
