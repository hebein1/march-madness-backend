#include <stdio.h>

#include "fann.h"

int main()
{
	fann_type *calc_out;
	unsigned int i;
	int ret = 0;
	int num_test_failed = 0;
	int num_total_tests = 0;
	struct fann *ann;
	struct fann_train_data *data;

	printf("Creating network.\n");

#ifdef FIXEDFANN
	ann = fann_create_from_file("ncaa_fixed.net");
#else
	ann = fann_create_from_file("ncaa_float.net");
#endif

	if(!ann)
	{
		printf("Error creating ann --- ABORTING.\n");
		return -1;
	}

	fann_print_connections(ann);
	fann_print_parameters(ann);

	printf("Testing network.\n");

#ifdef FIXEDFANN
	data = fann_read_train_from_file("ncaa_fixed.data");
#else
	data = fann_read_train_from_file("ncaa.data");
#endif

	for(i = 0; i < fann_length_train_data(data); i++)
	{
		num_total_tests++;

		fann_reset_MSE(ann);
		calc_out = fann_test(ann, data->input[i], data->output[i]);
#ifdef FIXEDFANN
		printf("Matchup test (%d, %d) -> %d, should be %d, difference=%f\n",
			   data->input[i][0], data->input[i][1], calc_out[0], data->output[i][0],
			   (float) fann_abs(calc_out[0] - data->output[i][0]) / fann_get_multiplier(ann));

		if((float) fann_abs(calc_out[0] - data->output[i][0]) / fann_get_multiplier(ann) > 0.2)
		{
			printf("Test failed\n");
			ret = -1;
			num_test_failed++;
		}
#else
		printf("Matchup test (%f, %f) -> %f, should be %f, difference=%f\n",
			   data->input[i][0], data->input[i][1], calc_out[0], data->output[i][0],
			   (float) fann_abs(calc_out[0] - data->output[i][0]));
#endif
	}

	printf("Cleaning up.\n");
	printf("%d tests failed \n", num_test_failed);
	float accuracy = ((float)(num_total_tests - num_test_failed))/((float)num_total_tests);
	printf("Accuracy: %f percent \n", accuracy*100.00);
	fann_destroy_train(data);
	fann_destroy(ann);

	return ret;
}
