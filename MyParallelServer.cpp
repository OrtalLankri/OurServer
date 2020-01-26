
#include <strings.h>
#include "MyParallelServer.h"



void MyParallelServer::open(int port, ClientHandler *ch) {

    int portNo, listenFd;
    struct sockaddr_in svrAdd, clntAdd;
    int connFd;
    vector<thread*> vec_thread;
    portNo = port;
    //create socket
    listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return;
    }
    bzero((char*) &svrAdd, sizeof(svrAdd));
    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(portNo);
    //bind socket
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return;
    }
    listen(listenFd, 10);
    bool is_connected = true;
    int threadsNum = 0;
    while (threadsNum < 10 && is_connected)
    {
        socklen_t len = sizeof(clntAdd);
        cout << "Server is now listening ..." << endl;
        connFd = accept(listenFd, (struct sockaddr *)&clntAdd, &len);
        if (connFd < 0)
        {
            cerr << "Arror accepting client" << endl;
            return;
        }
        else
        {
            cout << "Server is now connected" << endl;
        }
        ClientHandler* chClone = ch->clone();
        thread *t_ch = new thread(&MyParallelServer::clientThread, chClone, connFd);
        vec_thread.push_back(t_ch);
        threadsNum++;
    }
    for(int i = 0; i < vec_thread.size(); i++)
    {
        vec_thread[i]->join();
    }
    stop();
}


void MyParallelServer::stop(){
    close(this->socketfdp);
}

void MyParallelServer::clientThread(ClientHandler* c, int client_socket) {
    c->handleClient(client_socket);
}
