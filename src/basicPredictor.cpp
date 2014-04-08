#include <iostream>
#include <cstring>
#include "clientconnection.h"
#include "messageinterface.h"
#include "../dbc.h"
#include "../neuralNetwork/NCAA_ANN_src/ncaa_train.h"
#include "../neuralNetwork/NCAA_ANN_src/ncaa_test.h"
#include "../c5_mmp/mmp_c5_functions.h"

using namespace std;

int main()
{
	ClientConnection cc;
	cc.startConnection();
	MessageInterface mi(&cc);
	string * team1 = new string();
	string * team2 = new string();

  while (true) {
    DBC db;
    db.writeC5("c5_mmp/mmp.data");
    db.writeC5Teams("c5_mmp/mmp.avgs");
    db.writeANN("neuralNetwork/NCAA_ANN_src/ncaa.data");
    db.writeANNTeams("neuralNetwork/NCAA_ANN_src/teams.txt");
    db.writeANN("ncaa.data");
    db.writeANNTeams("teams.txt");

    buildTree(false, "./c5_mmp");

    Trainer trainer;
    trainer.train_network();
    Tester tester;


    mi.getTeams(team1, team2);
    std::string c5_winner = runMatchup(*team1, *team2, "./c5_mmp");
    std::string ann_winner = tester.getPrediction(*team1, *team2);

    mi.sendWinner(c5_winner);
  }

	cc.endConnection();
}
