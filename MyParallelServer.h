
#ifndef OURSERVER_MYPARALLELSERVER_H
#define OURSERVER_MYPARALLELSERVER_H

#include "Server.h"
#include <netinet/in.h>
#include <thread>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>

using namespace server_side;

class MyParallelServer :public Server{
    int socketfdp;
    vector<thread*> threads;
public:
    static void clientThread(ClientHandler* c, int client_socket);
        void open(int port, ClientHandler* c) override;
    void stop() override;
};

#endif //OURSERVER_MYPARALLELSERVER_H
