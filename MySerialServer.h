
#ifndef OURSERVER_MYSERIALSERVER_H
#define OURSERVER_MYSERIALSERVER_H

#include "Server.h"
#include <netinet/in.h>
#include <vector>
#include <unistd.h>

using namespace server_side;

class MySerialServer : public Server {
    int socketfdp;
public:
    void open(int port, ClientHandler* c) override;
    void stop() override;
};

#endif //OURSERVER_MYSERIALSERVER_H
