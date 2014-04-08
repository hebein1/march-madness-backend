#include <iostream>
#include <cstring>
#include "clientconnection.h"
#include "messageinterface.h"

using namespace std;

int main()
{
	ClientConnection cc;
	cc.startConnection();
	MessageInterface mi(&cc);
	string * team1 = new string();
	string * team2 = new string();

  while (true) {
    mi.getTeams(team1, team2);

    if(team1->length() < team2->length())
      mi.sendWinner(*team1);
    else
      mi.sendWinner(*team2);
  }

	cc.endConnection();
}
