#include "clientconnection.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>

const string ClientConnection::SERVERNAME = "localhost";

bool ClientConnection::begin() {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (this->sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
    	return false;
    }

    server = gethostbyname(ClientConnection::SERVERNAME.c_str()); // change to localhost
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return false;
    }
    // configuration
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(ClientConnection::PORTNUM);
    
    if (connect(this->sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
    	return false;
    }
    this->isConnected = true;

    return true;
}

void ClientConnection::disconnect() {
	return;
}

string ClientConnection::poll() {
	return "test";
}

bool ClientConnection::send(string message) {
	return false;
}

