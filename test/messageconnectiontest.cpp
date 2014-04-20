#include "../src/clientconnection.h"
#include "../src/messageinterface.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

TEST(MessageConnection, Send) {
	const int size = 8;

	vector<string> teams(size);

	string teamsA[size] = { "ohio","michigan","alaska","test-sample",
			"fail","random","maine","huskies" };
	
	for (int x = 0; x < size; x++)
		teams[x] = teamsA[x];

	MessageInterface mi(NULL);

	string message = mi.format(teams);

	string expected_string = "ohio:michigan:alaska:test-sample"
			":fail:random:maine:huskies";
	EXPECT_EQ(expected_string,message);
	
}

TEST(MessageConnection, Recieve) {
	MessageInterface mi(NULL);
	string content = "ohio:michigan:alaska:test-sample"
			":fail:random:maine:huskies";
	
	vector<string> teams = mi.parse(&content);
	
	const int size = 8;
	string expected_strings[size] = { "ohio","michigan","alaska","test-sample",
			"fail","random","maine","huskies" };
	
	for(int x = 0; x < size; x++)
		EXPECT_EQ(expected_strings[x],teams[x]);

}
