#include "messageinterface.h"

string MessageInterface::format(vector<string> ranking) {
	string buffer = "";
	for(int x = 0; x < ranking.size(); x++) {
		string content = ranking[x];
		// append ":" if not the last item in the list
		if (x < ranking.size() - 1)
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
	int startIndex = 0;
	bool done = false;
	while(!done) {
		int endIndex = content->find(':',startIndex);
		if (endIndex == string::npos) {
			done = true;
			endIndex = content->size();
		}
		string team = content->substr(startIndex,endIndex - startIndex);
		teams.push_back(team);
		startIndex = endIndex + 1;
	}
	return teams;
}
