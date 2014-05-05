#include <iostream>
#include "gtest/gtest.h"
#include "ncaa_train.h"
#include "ncaa_test.h"

//test untrained network initialization or creation
TEST(ANN, checkNetworkCreation)
{
	Trainer trainer;
	ASSERT_TRUE(trainer.createNetwork(3, 2, 4, 1));
}	

//check if size is right
TEST(PARSE, checkTeamStatSize)
{
	Tester tester(1);
	tester.parse_teams("../../teams.txt");
		
	ASSERT_EQ((int)tester.team_stats.size(), 351);	
}

//check if sizes are equal	
TEST(PARSE, checkStatRankSizeEQ)
{
	Tester tester(1);
	tester.parse_teams("../../teams.txt");

	ASSERT_EQ(tester.team_rank.size(), tester.team_stats.size());	
}

//check if all keys have a value which is not empty
TEST(PARSE, checkStatValNotEmpty)
{
	Tester tester(1);
	tester.parse_teams("../../teams.txt");

	map<string, vector<float> >::const_iterator stat_it;
	for(stat_it = tester.team_stats.begin(); stat_it != tester.team_stats.end(); ++stat_it)
	{	
		ASSERT_TRUE(!(stat_it->second).empty());
	}
}

//check if all keys have a value equal to 0
TEST(PARSE, checkRankValZero)
{
	Tester tester(1);
	tester.parse_teams("../../teams.txt");

	map<string, int>::const_iterator rank_it;
	for(rank_it = tester.team_rank.begin(); rank_it != tester.team_rank.end(); ++rank_it)
	{	
		ASSERT_EQ(rank_it->second, 0);
	}
}

