#ifndef NCAA_TEST
#define NCAA_TEST

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include "fann.h"

using namespace std;

map<string, int> team_rank;
map<string, vector<float> > team_stats;
	
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
	string team_name;
	while ((read = getline(&line, &len, teams_file)) != -1)
        {
	
		if(pch_flag == 0)
		{
			team_name  = string(line, strlen(line)-1);
			pch_flag = 1;
		}
		else
		{
			vector<float> avg_stats;
			pch = strtok(line, " ");
			while(pch != NULL)
                	{
				float stat = 0.0;
                                istringstream (pch) >> stat;
				avg_stats.push_back(stat);	
                        
                        	pch = strtok(NULL, " ");
			}
			pch_flag = 0;	
               		team_rank[team_name] = 0;
			team_stats[team_name] = avg_stats;
		}
		
	}
	
	//print_rank();
}

#endif
