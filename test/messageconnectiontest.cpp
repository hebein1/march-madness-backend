#include "../src/clientconnection.h"
#include "../src/messageinterface.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

TEST(MessageConnection, Send) {
	vector<string> teams;
	
	const int size = 8;
	string teamsA[] = { "ohio","michigan","alaska","test-sample",
			"fail","random","maine","huskies" };
	
	for (int x = 0; x < size; x++)
		teams[x] = teamsA[x];

	MessageInterface mi(NULL);

	string message = mi.format(teams);

	string expected_string = "ohio:michigan:alaska:test-sample"
			"fail:random:maine:huskies";
	EXPECT_EQ(message,expected_string);
	
}

TEST(MessageConnection, Recieve) {
	MessageInterface mi(NULL);
	string content = "ohio:michigan:alaska:test-sample"
			"fail:random:maine:huskies";
	
	vector<string> teams = mi.parse(&content);
	
	const int size = 8;
	string expected_strings[] = { "ohio","michigan","alaska","test-sample",
			"fail","random","maine","huskies" };
	
	for(int x = 0; x < size; x++)
		EXPECT_EQ(teams[x],expected_strings[x]);

}
