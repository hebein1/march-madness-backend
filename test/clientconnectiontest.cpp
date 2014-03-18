#define BSIZE 1024
#include "../src/clientconnection.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>


TEST(ClientConnection, Connect) {
	ClientConnection cc;
	EXPECT_TRUE(cc.startConnection());
	EXPECT_TRUE(cc.getIsConnected());
	cc.endConnection();
	EXPECT_FALSE(cc.getIsConnected());
}

TEST(ClientConnection, ServerRequest) {
	char test_buffer [ BSIZE ];
	string input = "hello world\r\n\r\n";

	std::strcpy(test_buffer,input.c_str());
	
	ClientConnection cc (test_buffer, NULL);

	string * message = cc.getMessage();
	ASSERT_STREQ(message->c_str(),"hello world");
}

TEST(ClientConnection, ClientResponse) {
	char test_buffer [ BSIZE ];
	ClientConnection cc (NULL,test_buffer);
	
	string message = "hello world";
	
	cc.send(message);
	
	//additional formating
	test_buffer[message.length() + 4] = '\0';
	ASSERT_STREQ(test_buffer,"hello world\r\n\r\n");
	
}
