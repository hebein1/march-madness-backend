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

class Tester
{
	public:
		string getPrediction(string team1, string team2);
		fann_type * const run_fann(struct fann * ann, fann_type stat_input[]);
		void parse_teams(char * fileName);
		void print_rank();
		void calc_rank();
		float get_accuracy();
		int test_network();	
		
		//public members for testing purposes
		map<string, int> team_rank;
		map<string, vector<float> > team_stats;			

	private:
		float accuracy;
		struct fann *ann;
		struct fann_train_data *data;	
};

#endif
