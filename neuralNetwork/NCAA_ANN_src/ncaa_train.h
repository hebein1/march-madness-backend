#ifndef NCAA_TRAIN
#define NCAA_TRAIN
#include <stdio.h>
#include "fann.h"

class Trainer
{
	public:
		//inline function for testing purposes
		struct fann * createNetwork(unsigned int num_layers, unsigned int num_input, unsigned int num_neurons_hidden, unsigned int num_output)
		{
			return fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);
		};

		int FANN_API test_callback(struct fann *ann, struct fann_train_data *train,
        				unsigned int max_epochs, unsigned int epochs_between_reports,
        				float desired_error, unsigned int epochs);
		int train_network();

	private:
		//no private members
};

#endif
