
#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *ch) {
    //create socket
    int socketfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    this->socketfdp = socketfd;
    if(socketfd < 0) {
        cerr << "Cannot open socket" << endl;
        return;
    }
    struct sockaddr_in address, clntAdd;
    bzero((char*) &address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    //bind socket
    if(bind(socketfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        cerr << "Cannot bind" << endl;
        return;
    }
    listen(socketfd, 10);
    vector<thread*> threads;
    int threadsNum = 0;
    while (threadsNum < 10)
    {
        socklen_t len = sizeof(clntAdd);
        cout << "Server is now listening ..." << endl;
        int client_socket = accept(socketfd, (struct sockaddr *)&clntAdd, &len);
        if (client_socket < 0) {
            cerr << "Error accepting client" << endl;
            break;
        }
        else {
            cout << "Server is now connected" << endl;
            ClientHandler *chClone = ch->clone();
            thread *t = new thread(&MyParallelServer::clientThread, chClone, client_socket);
            threads.push_back(t);
            threadsNum++;
        }
    }
    for(thread* t : threads) {
        t->join();
    }
    stop();
}

void MyParallelServer::stop(){
    close(this->socketfdp);
}

void MyParallelServer::clientThread(ClientHandler* c, int client_socket) {
    c->handleClient(client_socket);
}
