#include <iostream>
#include "gtest/gtest.h"
#include "ncaa_train.h"
#include "ncaa_test.h"

TEST(ANN, checkNetworkCreation)
{
	ASSERT_TRUE(createNetwork(3, 2, 4, 1));
}	

TEST(PARSE, checkTeamStatSize)
{
	parse_teams("teams.txt");
	
	//check if size is right	
	ASSERT_EQ((int)team_stats.size(), 351);	
}

TEST(PARSE, checkStatRankSizeEQ)
{
	parse_teams("teams.txt");

	//check if sizes are equal
	ASSERT_EQ(team_rank.size(), team_stats.size());	
}

TEST(PARSE, checkStatValNotEmpty)
{
	parse_teams("teams.txt");

	//check if all keys have a value which is not empty
	map<string, vector<float> >::const_iterator stat_it;
	for(stat_it = team_stats.begin(); stat_it != team_stats.end(); ++stat_it)
	{	
		ASSERT_TRUE(!(stat_it->second).empty());
	}
}

TEST(PARSE, checkRankValZero)
{
	parse_teams("teams.txt");

	//check if all keys have a value equal to 0
	map<string, int>::const_iterator rank_it;
	for(rank_it = team_rank.begin(); rank_it != team_rank.end(); ++rank_it)
	{	
		ASSERT_EQ(rank_it->second, 0);
	}
}

