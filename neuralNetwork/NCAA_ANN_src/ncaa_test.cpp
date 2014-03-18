#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <vector>
#include <sstream>
#include "fann.h"

using namespace std;

map<char *, int> team_rank;
map<char *, vector<int> > team_stats;
	

void print_rank()
{
	map<int, char *> result_map;	

	map<char *, int>::const_iterator it;
	for(it = team_rank.begin(); it != team_rank.end(); ++it)
	{
		//printf("%s => %d\n", it->first, it->second);
		result_map[it->second] = it->first;
	}

	int i = 0;
	map<int, char *>::const_iterator result_it;
	for(result_it = result_map.begin(); result_it != result_map.end(); ++result_it)
	{
		i++;
		printf("%d. %s => %d\n", i, result_it->second, result_it->first);
	}
}

void parse_teams(char * fileName)
{
	FILE *teams_file = fopen(fileName, "r");
        if (teams_file == NULL)
                perror("Teams file is empty");

        char * line = NULL;
        size_t len = 0;
        size_t read;
	char * pch;
       	int pch_flag = 0;
	while ((read = getline(&line, &len, teams_file)) != -1)
        {
		char * team_name = NULL;
		vector<int> avg_stats;
		pch = strtok(line, " ");
		while(pch != NULL)
                {
                        if(pch_flag == 0)
                        {
				team_name = new char[strlen(pch) + 1];
                            	strcpy(team_name, pch);
                                printf("TEAM: %s\n", team_name);
				pch_flag = 1;
                        }
                        else if(pch_flag == 1)
                        {
				int stat = 0;
                                istringstream (pch) >> stat;
				avg_stats.push_back(stat);
                        }
                        pch = strtok(NULL, " ");
                }
		team_rank[team_name] = 0;
		team_stats[team_name] = avg_stats;
		pch_flag = 0;
		free(team_name);
	}

	//print_rank();
}

int main()
{
	parse_teams("teams.txt");
	printf("YEAH\n");
	fann_type *calc_out;
	unsigned int i;
	int ret = 0;
	int num_test_passed = 0;
	int num_total_tests = 0;
	struct fann *ann;
	struct fann_train_data *data;

	printf("Creating network.\n");

	ann = fann_create_from_file("ncaa_float.net");

	if(!ann)
	{
		printf("Error creating ann --- ABORTING.\n");
		return -1;
	}

	fann_print_connections(ann);
	fann_print_parameters(ann);

	printf("Testing network.\n");

	data = fann_read_train_from_file("ncaaTest.data");

	for(i = 0; i < fann_length_train_data(data); i++)
	{
		fann_reset_MSE(ann);
		calc_out = fann_test(ann, data->input[i], data->output[i]);
		//calc_rank_pred = fann_test(ann, );
		//printf("Matchup scores test (%f, %f) -> %f, should be %f, difference=%f\n",
		//	   data->input[i][0], data->input[i][1], calc_out[0], data->output[i][0],
		//	   (float) fann_abs(calc_out[0] - data->output[i][0]));
		num_total_tests++;
		if(((float) fann_abs(calc_out[0] - data->output[i][0])) < 0.5)
			num_test_passed++;
	}

	map<char *, vector<int> >::const_iterator it_team1;
	for(it_team1 = team_stats.begin(); it_team1 != team_stats.end(); ++it_team1)
	{
		map<char *, vector<int> >::const_iterator it_team2;
		for(it_team2 = team_stats.begin(); it_team2 != team_stats.end(); ++it_team2)
		{
			if(strcmp(it_team1->first, it_team2->first) != 0)
			{
				//fann_type * stat_input = (fann_type *) malloc((sizeof(it_team1->second) + sizeof(it_team2->second)) * sizeof(fann_type));
				fann_type stat_input[(it_team1->second).size() + (it_team2->second).size()];
				int j = 0;
				for(j = 0; j<(it_team1->second).size(); j++)
				{
					stat_input[j] = ((it_team1->second)[j]);
				}
				for(int k = 0; k<(it_team2->second).size(); k++)
				{
					stat_input[j + k] = ((it_team2->second)[k]);
				}
				
				fann_type * const calc_team_score = fann_run(ann, stat_input);
				if(calc_team_score[0] < 0.5)
				{
					//team 2 won
					team_rank[it_team2->first] += 1;

					//team 1 lost
					team_rank[it_team1->first] -= 1;
				}
				else
				{	
					//team 2 lost
					team_rank[it_team2->first] -= 1;

					//team 1 won
					team_rank[it_team1->first] += 1;
				}
			}
		}
	}

	print_rank();

	float accuracy = ((float)num_test_passed) / ((float) num_total_tests);
	printf("Accuracy = %f percent\n", accuracy*100.00);

	printf("Cleaning up.\n");
	fann_destroy_train(data);
	fann_destroy(ann);

	return ret;
}
