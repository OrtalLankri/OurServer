
#ifndef OURSERVER_MYPARALLELSERVER_H
#define OURSERVER_MYPARALLELSERVER_H

#include "Server.h"
#include <netinet/in.h>
#include <thread>
#include <vector>
#include <unistd.h>

using namespace server_side;

class MyParallelServer :public Server{
    int socketfdp;
public:
    static void readFromClient(int port,ClientHandler* c, int* socketfdp);
    static void clientThread(ClientHandler* c, int client_socket);
        void open(int port, ClientHandler* c) override;
    void stop() override;
};

#endif //OURSERVER_MYPARALLELSERVER_H
