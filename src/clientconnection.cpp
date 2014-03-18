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

bool ClientConnection::startConnection() {
    // testing purposes only
    if (this->instream != NULL || this->outstream != NULL) {
	this->isConnected = true;
	return this->isConnected;
    }

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

    return this->isConnected;
}

bool ClientConnection::pushMessageOnQueue(char * buff, int n) {
	int last = 0;
	int x;
	bool complete = true;
	for (x = 0; x < n; x++) {	
		complete = false;
		if(strncmp(buff + x, "\r\n\r\n",4) == 0) {
			this->messages.push(new string(buff + last,x - last));
			x += 4;
			last = x;
			complete = true;
		}
	}
	return complete;
}

void ClientConnection::checkMessages() {	
	char buff [ClientConnection::BUFFSIZE];
	buff[ClientConnection::BUFFSIZE - 1] = '\0';
	int n;
	if (this->instream == NULL) {
		n = recv(sockfd,buff,ClientConnection::BUFFSIZE - 1,MSG_DONTWAIT);
	} else {
		n = strlen(this->instream);
		strncpy(buff,this->instream,n);
	}
	if (n < 1) { 
		// do not push messages
	} else {
		pushMessageOnQueue(buff,n); //don't worry about it for now
	}
}

void ClientConnection::endConnection() {
	if (this->instream == NULL && this->outstream == NULL) {
		close(sockfd);
	}
	isConnected = false;
	return;
}

int ClientConnection::poll() {
	checkMessages();
	return this->messages.size();
}

/**
 * YOU MUST DELETE ANY MESSAGES YOU RECEIVE
 */
string * ClientConnection::getMessage() {
	checkMessages(); // add messages from socket onto queue
	if (this->messages.size() == 0) {
		return NULL;
	}
	string * message = messages.front();
	this->messages.pop();
	return message;
}

bool ClientConnection::send(string message) {
	int n = 0;
	message.append("\r\n\r\n");
	if (this->outstream == NULL) { 
		write(sockfd,message.c_str(),message.length());	
	} else { // for testing purposes do not send over socket
		strcpy(this->outstream,message.c_str());
	}	
	return true;
}

