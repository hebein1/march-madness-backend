#include "messageinterface.h"

string MessageInterface::format(string team) {
	return "winner:" + team;
}

void MessageInterface::sendWinner(string winner) {
	string message = format(winner);
	this->connection->send(message);
}

void MessageInterface::getTeams(string * team1, string * team2) {
	string * message = this->connection->getMessage();
	parse(team1,team2,message);
	delete message;
}

void MessageInterface::parse(string * team1, string * team2, string * content) {
	int splitIndex = content->find(':');
	(* team1) = content->substr(0,splitIndex);
	(* team2) = content->substr(splitIndex+1,content->size());
}
