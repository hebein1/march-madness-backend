#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>

/*
 * tests that the sample application runs correctly
 */
TEST(MMP, testSampleApplication)
{
	FILE* pipe;

	/* generate the decision tree if it has not been made already */
	if( access( "march_madness.tree", F_OK ) == -1 ) {
		FILE* pipe = popen("../c5_source/c5.0 -f march_madness", "r");
		if(pipe)
		{
			pclose(pipe);
		}
	}
	
	/* run the decision tree on the march_madness.cases data */
	char buffer[128];
	std::string result = "";
	pipe = popen("./sample -f march_madness", "r");
	if(pipe)
	{
		while(!feof(pipe)) {
			if(fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
		pclose(pipe);
	}

	/* check output */
	std::istringstream f(result);
	std::string line;
	std::getline(f, line); // skip line 1
	std::getline(f, line); // skip line 2
	std::getline(f, line); // skip line 3
	while (std::getline(f, line)) {
		std::cout << line << "\n";
		ASSERT_TRUE(line.find("A") != std::string::npos || line.find("B") != std::string::npos);
	}
}
