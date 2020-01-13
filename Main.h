//
// Created by adi on 1/13/20.
//

#ifndef OURSERVER_MAIN_H
#define OURSERVER_MAIN_H

#include <iostream>
#include "MySerialServer.h"
#include "Server.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include "StringReverser.h"


using namespace server_side;
using namespace std;

namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            Server* server = new MySerialServer();
            int capacity = 10;
            CacheManager<string>* cm = new FileCacheManager<string>(capacity);
            Solver<string, string>* solver = new StringReverser();
            ClientHandler* ch = new MyTestClientHandler(solver, cm);
            int port = atoi(argv[0]);
            server->open(port, ch);
            cout<<"main Hello, World!"<<endl;
            return 0;
        }
    };
}

#endif //OURSERVER_MAIN_H