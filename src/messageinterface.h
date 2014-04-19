#ifndef MESSAGEINTERFACE_H
#define MESSAGEINTERFACE_H
#include "clientconnection.h"
#include <vector>

class MessageInterface
{
	ClientConnection * connection;
public:
	MessageInterface(ClientConnection * c): connection(c) {}
	void sendRanking(vector<string> ranking);
	vector<string> getTeams();
	vector<string> parse(string * content);
	string format(vector<string> ranking);
};

#endif
