#define BSIZE 1024
#include "../src/clientconnection.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>


TEST(ClientConnection, Connect) {
	ClientConnection cc;
	EXPECT_TRUE(cc.begin());
	EXPECT_TRUE(cc.getIsConnected());
	cc.disconnect();
	EXPECT_FALSE(cc.getIsConnected());
}

TEST(ClientConnection, ServerRequest) {
	char test_buffer[ BSIZE ];
	string input = "hello world\r\n\r\n";

	std::strcpy(test_buffer,input.c_str());
	
	ClientConnection cc (test_buffer, NULL);

	string message = cc.poll();
	ASSERT_STREQ(message.c_str(),"hello world\r\n\r\n");
}

TEST(ClientConnection, ClientResponse) {
	char test_buffer[ BSIZE ];
	ClientConnection cc (NULL,test_buffer);
	
	cc.send("hello world");
	
	//additional formating
	int len = strlen("hello world");
	test_buffer[len] = '\0';
	ASSERT_STREQ(test_buffer,"hello world\r\n\r\n");
	
}
