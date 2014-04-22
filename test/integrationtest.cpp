#include "../src/clientconnection.h"
#include "../src/messageinterface.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>


TEST(IntegrationTest, Client) {
	ClientConnection cc;
	EXPECT_TRUE(cc.startConnection());
	ASSERT_TRUE(cc.getIsConnected());
	
	string * message = cc.getMessage();
	EXPECT_STREQ(message->c_str(),"illinois:michigan");
	cc.send("illinois:michigan");

	message = cc.getMessage();
	EXPECT_STREQ(message->c_str(),"michigan:texas:alaska");
	cc.send("texas:alaska:michigan");

	message = cc.getMessage();
	EXPECT_STREQ(message->c_str(),"san jose:charleston:qdoba:a:b:c");
	cc.send("charleston:san jose:qdoba:a:b:c");

	MessageInterface mi(&cc);
	
	const int size = 10;
	string teams_a[size] = { "check1","random","crazy13","bumby","zP","10",
				"9","8","7","6" };
	
	vector<string> teams = mi.getTeams();
	for(int x = 0; x < size; x++)
		EXPECT_EQ(teams_a[x],teams[x]);
	
	mi.sendRanking(teams);

	cc.endConnection();
	EXPECT_FALSE(cc.getIsConnected());
}

