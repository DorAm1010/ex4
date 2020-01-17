//
// Created by Laliv on 14/01/2020.
//

#include "MySerialServer.h"
#define TIMEOUT 120
using namespace server_side;
using namespace std;
using namespace literals::chrono_literals;


void MySerialServer::open(int port, ClientHandler* clientHandler) {
    //create socket
    int client_socket;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        throw "Unable To Create Socket";
    }

    //bind socket to IP address
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(port);
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP";
    }

    //making socket listen to the port 1 client at a time
    while (listen(socketfd, 1) != -1) {
        auto start = chrono::system_clock::now();
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;

        client_socket = accept(socketfd, (struct sockaddr *)&address,
                               (socklen_t*)&address);

        if (client_socket == -1) {
            while (elapsed_seconds.count() <= TIMEOUT) {
                end = chrono::system_clock::now();
                client_socket = accept(socketfd, (struct sockaddr *)&address,
                                       (socklen_t*)&address);

                if (client_socket != -1)
                    break;
                elapsed_seconds = end - start;
            }
            if (elapsed_seconds.count() >= TIMEOUT) {
                cout << "Timed Out For Connection, Moving to Next Client" << endl;
                continue;
            }
        }

        cout<<"Server is now listening ..."<< endl;

        clientHandler->handleClient(client_socket);
    }

    cout <<"Done Listening" << endl;
}

void MySerialServer::stop() {

}
