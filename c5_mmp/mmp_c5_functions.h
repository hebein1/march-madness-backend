#ifndef C5_FUNCTIONS
#define C5_FUNCTIONS

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/*
 * helper sorting function
 */
struct sort_pred {
    bool operator()(const std::pair<std::string,int> &left, const std::pair<std::string,int> &right) {
		return left.second > right.second;
    }
};

/*
 * builds a decision tree based on mmp.names & mmp.data and writes it to mmp.tree
 */
void buildTree(bool boost, std::string path_to_c5_mmp);

/*
 * runs the decision tree on two teams and returns the winner as a string
 */
std::string runMatchup(std::string T1, std::string T2, std::string path_to_c5_mmp);

/*
 * runs the decision tree on all possible matchups and returns the result as a vector of paris <team_name, wins>
 */
std::vector<std::pair<std::string, int> > runAllMatchups(std::string path_to_c5_mmp);

#endif //C5_FUNCTIONS
