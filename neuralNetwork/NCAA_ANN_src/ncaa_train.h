#ifndef NCAA_TRAIN
#define NCAA_TRAIN
#include <stdio.h>

#include "fann.h"

struct fann * createNetwork(unsigned int num_layers, unsigned int num_input, unsigned int num_neurons_hidden, unsigned int num_output)
{
	return fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);
}

#endif
