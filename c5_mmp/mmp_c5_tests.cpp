#include "gtest/gtest.h"
#include "mmp_c5_functions.cpp"
#include <algorithm>

/*
 * helper sorting function
 */
struct sort_pred {
    bool operator()(const std::pair<std::string,int> &left, const std::pair<std::string,int> &right) {
		return left.second > right.second;
    }
};

/*
 * test buildTree() with boosting
 */
TEST(MMP, buildTreeBoostCheck)
{
	// build tree
	buildTree(true);

	// check that .tree file was generated
	ASSERT_TRUE(access("mmp.tree", F_OK ) != -1);
}

/*
 * test buildTree() with no boosting
 */
TEST(MMP, buildTreeNormalCheck)
{
	// build tree
	buildTree(false);

	// check that .tree file was generated
	ASSERT_TRUE(access("mmp.tree", F_OK ) != -1);
}

/*
 * test runMatchup() with invalid team 1 string
 */
TEST(MMP, runMatchupInvalidTeamOneCheck)
{
	// run a single matchup
	std::string t1 = "INVALID 1";
	std::string t2 = "Stony Brook";
	std::string result = runMatchup(t1,t2);

	// check that a winner was selected
	ASSERT_TRUE(result == "Error: could not find data for team INVALID 1");
}

/*
 * test runMatchup() with invalid team 2 string
 */
TEST(MMP, runMatchupInvalidTeamTwoCheck)
{
	// run a single matchup
	std::string t1 = "Vermont";
	std::string t2 = "INVALID 2";
	std::string result = runMatchup(t1,t2);

	// check that a winner was selected
	ASSERT_TRUE(result == "Error: could not find data for team INVALID 2");
}

/*
 * test runMatchup() with invalid team 1 string and invalid team 2 string
 */
TEST(MMP, runMatchupInvalidTeam1Team2Check)
{
	// run a single matchup
	std::string t1 = "INVALID 1";
	std::string t2 = "INVALID 2";
	std::string result = runMatchup(t1,t2);

	// check that a winner was selected
	ASSERT_TRUE(result == "Error: could not find data for team INVALID 1 and team INVALID 2");
}

/*
 * test runMatchup() with valid teams
 */
TEST(MMP, runMatchupValidCheck)
{
	// run a single matchup
	std::string t1 = "Vermont";
	std::string t2 = "Stony Brook";
	std::string result = runMatchup(t1,t2);

	// check that a winner was selected
	ASSERT_TRUE(result == t1 || result == t2);

	// print winner
	std::cout << "\nResult of matchup " << t1 << " vs. " << t2 << "... " << result << " wins\n\n";
}

/*
 * test runAllMatchups()
 */
TEST(MMP, runAllMatchupsCheck)
{
	// run all matchups
	std::vector<std::pair<std::string, int> > results = runAllMatchups();

	// check that results were generated
	ASSERT_TRUE(results.size() == 351);

	// print the results of all the matchups in decending order
	std::sort(results.begin(), results.end(), sort_pred());

	std::cout << "\n";
	for(int i = 0; i < results.size(); i++)
	{
		std::cout << results[i].first << ": " << results[i].second << std::endl;
	}
	std::cout << "\n";
}
