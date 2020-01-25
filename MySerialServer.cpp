
#include "MySerialServer.h"

void MySerialServer::stop() {
    close(this->socketfdp);
}

void MySerialServer::open(int port, ClientHandler *c) {
    // create thread
    thread *t = new thread(&MySerialServer::readFromClient, port, c, &this->socketfdp);
    t->detach();
}

void MySerialServer::readFromClient(int port, ClientHandler *c, int *socketfdp) {
    // create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    *socketfdp = socketfd;
    // if creation failed
    if (socketfd == -1) {
        cerr << "Could not create a socket" << endl;
        return;
    }
    //bind socket to IP address
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    // time out
    struct timeval tv;
    tv.tv_sec = 120;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));
    //bind
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "Could not bind the socket to an IP" << endl;
        return;
    }
    //making socket listen to the port
    if (listen(socketfd, 5) == -1) {
        cerr << "Error during listening command" << endl;
        return;
    } else {
        cout << "Server is now listening ..." << endl;
    }
    while (true) {
        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        // if acceptance failed
        if (client_socket == -1) {
            cerr << "Error accepting client" << endl;
            return;
        }
        cout << "Server is now connected" << endl;
        c->handleClient(client_socket);
    }
}
