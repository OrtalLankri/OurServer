//
// Created by ortal on 12/01/2020.
//

#ifndef OURSERVER_MYSERIALSERVER_H
#define OURSERVER_MYSERIALSERVER_H

#include "Server.h"
using namespace server_side;

class MySerialServer : public Server {
public:
    static void readFromClient(int port,ClientHandler* c);
    void open(int port,ClientHandler* c);
    void stop();

};


#endif //OURSERVER_MYSERIALSERVER_H
