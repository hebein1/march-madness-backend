#define BSIZE 1024
#include "../src/clientconnection.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>



TEST(ClientConnection, ServerRequest) {
	char test_buffer [ BSIZE ];
	string input = "hello world\r\ntest1\r\n3total\r\n";

	std::strcpy(test_buffer,input.c_str());
	
	ClientConnection cc (test_buffer, NULL);
	
	EXPECT_EQ(3,cc.poll());

	string * message = cc.getMessage();
	EXPECT_STREQ(message->c_str(),"hello world");
	
	message = cc.getMessage();
	EXPECT_STREQ(message->c_str(),"test1");
	
	message = cc.getMessage();
	EXPECT_STREQ(message->c_str(),"3total");
}

TEST(ClientConnection, ClientResponse) {
	char test_buffer [ BSIZE ];
	ClientConnection cc (NULL,test_buffer);
	
	string message = "hello world";
	
	cc.send(message);
	
	//additional formating
	test_buffer[message.length() + 2] = '\0';
	ASSERT_STREQ(test_buffer,"hello world\r\n");
	
}
