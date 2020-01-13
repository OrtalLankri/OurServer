//
// Created by ortal on 12/01/2020.
//

#include <netinet/in.h>
#include <thread>
#include <vector>
#include "MySerialServer.h"

void MySerialServer::open(int port,ClientHandler c) {
    // create thread
//    thread *t = new thread(&MySerialServer::readFromClient, port, c);
//    Singleton::getInstance()->addThread(t);
   // t->detach();

}
/**
 * the function reads the data from the simulator and updates the xml map
 * @param client_socket the socket
 * @param socketfd the socketfd
 */
void MySerialServer::readFromClient(int port, ClientHandler c) {
/// while connected!!!
    while (true) {
        /**
     * opens the server communication and runs it on a new thread
     * @return the number of indexes to move in the commands map
     */
        // create socket
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
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
        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        // if acceptance failed
        if (client_socket == -1) {
            cerr << "Error accepting client" << endl;
            return;
        }
        cout << "Server is now connected" << endl;
        c.handleClient(client_socket);

//handler
//        int valRead = 0;
//        while (valRead != -1 && Singleton::getInstance()->isConnected()) {
//            Singleton::getInstance()->getMTX()->lock();
//            //reading from client
//            char buffer[100000] = {0};
//            valRead = read(client_socket, buffer, 100000);
//            string value = "";
//            vector<double> values;
//            // separate the values of the buffer
//            int length = strlen(buffer);
//            for (int i = 0; i < length; i++) {
//                if (buffer[i] == ',') {
//                    double num = atof(value.c_str());
//                    values.push_back(num);
//                    value = "";
//                    continue;
//                }
//                value = value + buffer[i];
//            }
//            values.push_back(atof(value.c_str()));
//            // update the values read from socket
//            Data::UpdateXMLMap(values);
//            Singleton::getInstance()->getMTX()->unlock();
//        }
//        close(socketfd);
    }
}
