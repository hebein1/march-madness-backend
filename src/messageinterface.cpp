#include "messageinterface.h"

string MessageInterface::format(vector<string> ranking) {
	string buffer = "";
	for(vector<string>::iterator it = ranking.begin(); it != ranking.end(); ++it) {
		string content = (*it);
		if (distance(it,ranking.end()) > 1)
			content.append(":");
		buffer.append(content);
	}
	return buffer;
}

void MessageInterface::sendRanking(vector<string> ranking) {
	string message = format(ranking);
	this->connection->send(message);
}

vector<string> MessageInterface::getTeams() {
	string * message = this->connection->getMessage();
	vector<string> teams = parse(message);
	delete message;
	return teams;
}

vector<string> MessageInterface::parse(string * content) {
	vector<string> teams;
	vector<string>::iterator it = teams.begin();
	int startIndex = 0;
	bool done = false;
	while(!done) {
		int endIndex = content->find(':',startIndex);
		if (endIndex == string::npos) {
			done = true;
			endIndex = content->size();
		}
		string team = content->substr(startIndex,endIndex);
		it = teams.insert(it,team);
		startIndex = endIndex + 1;
	}
	return teams;
}
