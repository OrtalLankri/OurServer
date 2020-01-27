
#include "MySerialServer.h"

void MySerialServer::stop() {
    close(this->socketfdp);
}

void MySerialServer::open(int port, ClientHandler *c) {
    // create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    this->socketfdp = socketfd;
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
    int connect = 1;
    while (connect) {
        // time out
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(socketfd, &rfds);
        struct timeval tv;
        tv.tv_sec = 120;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));
        connect = select(socketfd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
        if (connect < 0) {
            connect = 0;
            break;
        }
        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        // if acceptance failed
        if (client_socket == -1) {
            connect = 0;
            break;
        }
        cout << "Server is now connected" << endl;
        c->handleClient(client_socket);
    }
    this->stop();
}