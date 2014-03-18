#define BSIZE 1024
#include "clientconnection.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <cstring>


TEST(ClientConnection, Connect) {
	ClientConnection cc = new ClientConnection();
	EXPECT_TRUE(cc.connect());
	EXPECT_TRUE(cc.isConnected());
	EXPECT_TRUE(cc.disconnect());
	EXPECT_FALSE(cc.isConnected());
}

TEST(ClientConnection, ServerRequest) {
	char test_buffer[ BSIZE ];
	string[] messages = { "hello world\r\n\r\n" };

	int startIdx = 0;
	for (string message : messages) {
		int len = strlen(message);
		ASSERT_TRUE(startIdx + len < BSIZE);
		strcpy(test_buffer + startIdx,message);
	}
	
	ClientConnection cc = new ClientConnection(test_buffer, NULL);

	string message = cc.poll();
	ASSERT_STREQ(message,"hello world");
}

TEST(ClientConnection, ClientResponse) {
	char test_buffer[ BSIZE ];
	ClientConnection cc = new ClientConnection(NULL,test_buffer);
	
	cc.send("hello world");
	
	//additional formating
	int len = strlen("hello world");
	test_buffer[len] = '\0';
	ASSERT_STREQ(test_buffer,"hello world\r\n\r\n");
	
}
