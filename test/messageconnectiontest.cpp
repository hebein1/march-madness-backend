#include "../src/clientconnection.h"
#include "../src/messageinterface.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

TEST(MessageConnection, Send) {
	string winner = "illinois";
	MessageInterface mi(NULL);

	string message = mi.format(winner);

	EXPECT_EQ(message,"winner:illinois");
	
}

TEST(MessageConnection, Recieve) {
	string * team1 = new string();
	string * team2 = new string();
	MessageInterface mi(NULL);
	
	string content = "michigan:illinois";
	mi.parse(team1,team2,&content);

	EXPECT_EQ(*team1,"michigan");
	EXPECT_EQ(*team2,"illinois");
	
}
