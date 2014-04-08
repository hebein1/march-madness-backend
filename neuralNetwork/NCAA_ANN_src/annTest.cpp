#include <iostream>
#include "gtest/gtest.h"
#include "ncaa_train.h"
#include "ncaa_test.h"

TEST(ANN, checkNetworkCreation)
{
	Trainer trainer;
	ASSERT_TRUE(trainer.createNetwork(3, 2, 4, 1));
}	

TEST(PARSE, checkTeamStatSize)
{
	Tester tester;
	tester.parse_teams("teams.txt");
	
	//check if size is right	
	ASSERT_EQ((int)tester.team_stats.size(), 419);	
}

TEST(PARSE, checkStatRankSizeEQ)
{
	Tester tester;
	tester.parse_teams("teams.txt");

	//check if sizes are equal
	ASSERT_EQ(tester.team_rank.size(), tester.team_stats.size());	
}

TEST(PARSE, checkStatValNotEmpty)
{
	Tester tester;
	tester.parse_teams("teams.txt");

	//check if all keys have a value which is not empty
	map<string, vector<float> >::const_iterator stat_it;
	for(stat_it = tester.team_stats.begin(); stat_it != tester.team_stats.end(); ++stat_it)
	{	
		ASSERT_TRUE(!(stat_it->second).empty());
	}
}

TEST(PARSE, checkRankValZero)
{
	Tester tester;
	tester.parse_teams("teams.txt");

	//check if all keys have a value equal to 0
	map<string, int>::const_iterator rank_it;
	for(rank_it = tester.team_rank.begin(); rank_it != tester.team_rank.end(); ++rank_it)
	{	
		ASSERT_EQ(rank_it->second, 0);
	}
}

