#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>
#include <queue>

using namespace std;

class ClientConnection
{
	static const int BUFFSIZE = 4096;
	static const int PORTNUM = 3000;
	static const string SERVERNAME;
	int sockfd;
	bool isConnected;
	char * instream;
	char * outstream;
	queue<string *> messages;
	bool pushMessageOnQueue(char * buff,int n);
public:
	ClientConnection() : isConnected(false), instream(NULL), outstream(NULL){}
	ClientConnection(char * in, char * out) : isConnected(true), instream(in), outstream(out) {}
	bool startConnection();
	void endConnection();
	bool getIsConnected() { return isConnected; }
	int poll();
	string * getMessage();
	void checkMessages();
	bool send(string message);
};
#endif
