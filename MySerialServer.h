//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_MYSERIALSERVER_H
#define OURSERVER_MYSERIALSERVER_H

#include "Server.h"
using namespace server_side;

class MySerialServer : public Server {
    void readFromClient(int port, ClientHandler c);
public:
    void open(int port,ClientHandler c);
};


#endif //OURSERVER_MYSERIALSERVER_H
