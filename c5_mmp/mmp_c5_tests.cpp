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
 * test that tree is built correctly
 */
TEST(MMP, buildTreeCheck)
{
	// build tree
	buildTree();

	// check that .tree file was generated
	ASSERT_TRUE(access("mmp.tree", F_OK ) != -1);

	// print notification
	std::cout << "\nTree Built\n\n";
}

/*
 * test that a single matchup can be run on the tree
 */
TEST(MMP, singleMatchupCheck)
{
	// run a single matchup
	std::string result = runMatchup("T1","T2");

	// check that a winner was selected
	ASSERT_TRUE(result == "T1" || result == "T2");

	// print winner
	std::cout << "\nResult of matchup T1 vs. T2... " << result << " wins\n\n";
}

/*
 * test that all possible matchups can be run on the tree
 */
TEST(MMP, allMatchupsCheck)
{
	// run all matchups
	std::vector<std::pair<std::string, int> > results = runAllMatchups();

	// check that results were generated
	ASSERT_TRUE(!results.empty());

	// print the results of all the matchups in decending order
	std::sort(results.begin(), results.end(), sort_pred());

	std::cout << "\n";
	for(int i = 0; i < results.size(); i++)
	{
		std::cout << results[i].first << ": " << results[i].second << std::endl;
	}
	std::cout << "\n";
}
