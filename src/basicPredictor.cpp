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

  DBC db;
  db.writeC5("c5_mmp/mmp.data");
  db.writeC5Teams("c5_mmp/mmp.avgs");
  db.writeANN("neuralNetwork/NCAA_ANN_src/ncaa.data");
  db.writeANNTeams("neuralNetwork/NCAA_ANN_src/teams.txt");
  db.writeANN("ncaa.data");
  db.writeANNTeams("teams.txt");

  buildTree(false, "./c5_mmp");

  //Trainer trainer;
	//bool first_run = true;
  //trainer.train_network();
  //Tester tester;
  //tester.parse_teams();
  //tester.calc_rank();
  //tester.print_rank();

  while (true) {
    std::vector<std::string> teams = mi.getTeams();
    if (teams.size() == 1) {
      std::vector<std::pair<std::string, int> > results = runAllMatchups("./c5_mmp");
      std::sort(results.begin(), results.end(), sort_pred());

      std::vector<std::string> ranks;
      for (int i = 0; i < results.size(); i++) {
        ranks.push_back(results[i].first);
      }
      mi.sendRanking(ranks);
    } else if (teams.size() == 2) {
      std::string c5_winner = runMatchup(teams[0], teams[1], "./c5_mmp");
      //std::string ann_winner = tester.getPrediction(*team1, *team2);

      std::vector<std::string> winner;
      winner.push_back(c5_winner);

      mi.sendRanking(winner);
    }
  }

	cc.endConnection();
}
