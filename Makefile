
dbctest: dbctest.cpp dbc.h dbc
	g++ -isystem ${PWD}/gtest-1.7.0/include -c dbctest.cpp 
	g++ -isystem ${PWD}/gtest-1.7.0/include -pthread dbctest.o dbc.o ${PWD}/gtest-1.7.0/src/gtest_main.cc ${PWD}/gtest-1.7.0/libgtest.a \
		      -lsqlite3 -o dbctest

dbc: dbc.cpp dbc.h
	g++ -c dbc.cpp




