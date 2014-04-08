#include "mmp_c5_functions.h"

/*
 * builds a decision tree based on mmp.names & mmp.data and writes it to mmp.tree
 */
void buildTree(bool boost, std::string path_to_c5_mmp)
{
	FILE* pipe = NULL;

	if(boost)
	{
        pipe = popen(("cd " + path_to_c5_mmp + ";" + " ./c5_source/c5.0 -f mmp -b").c_str(), "r");
	}
	else
	{
        pipe = popen(("cd " + path_to_c5_mmp + ";" + " ./c5_source/c5.0 -f mmp").c_str(), "r");
	}

	if(pipe)
	{
		pclose(pipe);
	}
}

/*
 * runs the decision tree on two teams and returns the winner as a string
 */
std::string runMatchup(std::string T1, std::string T2, std::string path_to_c5_mmp)
{	
	// get team data
	std::ifstream infile((path_to_c5_mmp + "/mmp.avgs").c_str());
	std::string line;
	std::string t1_data = "";
	std::string t2_data = "";
	while (std::getline(infile, line))
	{
		if(line.find(T1) != std::string::npos)
		{
			t1_data = line;
		}
		else if(line.find(T2) != std::string::npos)
		{
			t2_data = line;
		}
	}

	if(t1_data == "" && t2_data == "")
	{
		return "Error: could not find data for team " + T1 + " and team " + T2;
	}
	else if(t1_data == "")
	{
		return "Error: could not find data for team " + T1;
	}
	else if(t2_data == "")
	{
		return "Error: could not find data for team " + T2;
	}
	

	// wrtie data to .cases file
	FILE* cases_file = fopen((path_to_c5_mmp + "/mmp.cases").c_str() , "w+");
	t1_data = t1_data.substr(t1_data.find(",") + 1);
	t2_data = t2_data.substr(t2_data.find(",") + 1);
	fprintf(cases_file, "%s,%s,?", t1_data.c_str(), t2_data.c_str());
	fclose(cases_file);

	// run tree
	char buffer[128];
	std::string result = "";
	FILE* pipe = popen(("cd " + path_to_c5_mmp + ";" + " ./given_c5_runner -f mmp").c_str(), "r");
	if(pipe)
	{
		while(!feof(pipe)) {
			if(fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
		pclose(pipe);
	}

	// parse results
	std::string winner;
	std::istringstream f(result);
	std::getline(f, line); // skip line 1
	std::getline(f, line); // skip line 2
	std::getline(f, line); // skip line 3
	while (std::getline(f, line)) {
		if(line.find("A") != std::string::npos)
		{
			winner = T1;
		}
		else
		{
			winner = T2;
		}
	}

	// return winner
	return winner;
}

/*
 * runs the decision tree on all possible matchups and returns the result as a vector of paris <team_name, wins>
 */
std::vector<std::pair<std::string, int> > runAllMatchups(std::string path_to_c5_mmp)
{
	// read team data from .avgs
	int team_data_index = 0;
	std::vector<std::string> team_data;
	std::ifstream infile((path_to_c5_mmp + "/mmp.avgs").c_str());
	std::string line;
	while (std::getline(infile, line))
	{
		team_data.push_back(line);
		team_data_index++;
	}

	// set up .cases file
	FILE* cases_file = fopen ((path_to_c5_mmp + "/mmp.cases").c_str(), "w+");
	std::string t1_data;
	std::string t2_data;
	for(int t1 = 0; t1 < 351; t1++)
	{
		for(int t2 = 0; t2 < 351; t2++)
		{
			if(t1 != t2)
			{
				t1_data = team_data[t1].substr(team_data[t1].find(",") + 1);
				t2_data = team_data[t2].substr(team_data[t2].find(",") + 1);
				fprintf(cases_file, "%s,%s,?\n", t1_data.c_str(), t2_data.c_str());
			}
		}
	}
	fclose(cases_file);

	// run tree
	char buffer[128];
	std::string result = "";
	FILE* pipe = popen(("cd " + path_to_c5_mmp + ";" + " ./given_c5_runner -f mmp").c_str(), "r");
	if(pipe)
	{
		while(!feof(pipe)) {
			if(fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
		pclose(pipe);
	}

	// parse results
	std::vector<std::pair<std::string, int> > results;
	std::string cur_team = "";
	int team_index = 0;
	int matchup_count = 0;
	bool new_team = true;
	std::istringstream f(result);
	std::getline(f, line); // skip line 1
	std::getline(f, line); // skip line 2
	std::getline(f, line); // skip line 3
	while (std::getline(f, line)) {
		if(new_team)
		{
			cur_team = team_data[team_index].substr(0, team_data[team_index].find(","));
			results.push_back(std::make_pair(cur_team,0));
			new_team = false;
		}

		if(line.find("A") != std::string::npos)
		{
			results[team_index].second++;
		}

		matchup_count++;

		if(matchup_count == team_data.size()-1)
		{
			team_index++;
			new_team = true;
			matchup_count = 0;
		}
	}
	
	// return results
	return results;
}

