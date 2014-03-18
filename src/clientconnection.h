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

using namespace std;

class ClientConnection
{
	static const int PORTNUM = 3000;
	static const string SERVERNAME;
	int sockfd;
	bool isConnected;
	char * instream;
	char * outstream;
public:
	ClientConnection() : isConnected(false), instream(new char[4096]), outstream(new char[4096]) {}
	ClientConnection(char * in, char * out) : isConnected(false), instream(in), outstream(out) {}
	~ClientConnection() { delete[] instream; delete[] outstream; }
	bool begin();
	void disconnect();
	bool getIsConnected() { return isConnected; }
	string poll();
	bool send(string message);
};
#endif
