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
		fann_type * const getPrediction(struct fann * ann, fann_type stat_input[]);
		void parse_teams(char * fileName);
		void print_rank();
		void calc_rank();
		int test_network();	
		//public members for testing purposes
		map<string, int> team_rank;
		map<string, vector<float> > team_stats;			

	private:
		struct fann *ann;
		struct fann_train_data *data;	
};

#endif
