#ifndef MESSAGEINTERFACE_H
#define MESSAGEINTERFACE_H
#include "clientconnection.h"

class MessageInterface
{
	ClientConnection * connection;
public:
	MessageInterface(ClientConnection * c): connection(c) {}
	void send(string winner);
	void getTeams(string * team1, string * team2);
	void parse(string * team1, string * team2, string * content);
	string format(string winner);
};

#endif
