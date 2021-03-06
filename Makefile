# This is the makefile for the March Madness Engine
SRC_DIR=src
LIB_DIR=lib
BIN_DIR=bin
GTEST_DIR=gtest-1.7.0
CLEAN_FILES=dbctest.o predictor.o dbc.o dbc dbctests mmetests mme
C_FLAGS=-lsqlite3

# Default functionality should be to build the program and tests
all: mmetests 

# To build the gtest library run init once
init : gtest

# Command to build gtest library
gtest:
	g++ -isystem ${LIB_DIR}/${GTEST_DIR}/include -I ${LIB_DIR}/${GTEST_DIR} -pthread -c \
	 	${LIB_DIR}/${GTEST_DIR}/src/gtest-all.cc 
	ar -rv libgtest.a gtest-all.o

# This March Madness Engine test builder all test should be a dependency of mmetests
mmetests: dbctests

dbctests: dbctest.cpp dbc.o
	g++ -isystem ${PWD}/${LIB_DIR}/${GTEST_DIR}/include -c dbctest.cpp 
	g++ -isystem ${PWD}/${LIB_DIR}/${GTEST_DIR}/include -pthread dbctest.o dbc.o \
		${PWD}/${LIB_DIR}/${GTEST_DIR}/src/gtest_main.cc libgtest.a \
		-lsqlite3 -o mmetests

# This is the March Madness Engine builder
mme: predictor.o dbc.o clientconnection.o messageinterface.o  mmp_c5_functions.o
	g++ ${C_FLAGS} -o mme predictor.o dbc.o clientconnection.o messageinterface.o mmp_c5_functions.o neuralNetwork/NCAA_ANN_src/ncaa_test.o neuralNetwork/NCAA_ANN_src/ncaa_train.o -lfann -lsqlite3 

mmp_c5_functions.o: c5_mmp/mmp_c5_functions.o
	g++ -o mmp_c5_functions.o -c c5_mmp/mmp_c5_functions.cpp

predictor.o: ${SRC_DIR}/basicpredictor.cpp
	g++ -o predictor.o -c ${SRC_DIR}/basicPredictor.cpp

clientconnection.o: ${SRC_DIR}/clientconnection.cpp
	g++ -o clientconnection.o -c ${SRC_DIR}/clientconnection.cpp

messageinterface.o: ${SRC_DIR}/messageinterface.cpp
	g++ -o messageinterface.o -c ${SRC_DIR}/messageinterface.cpp

dbc.o: dbc.cpp dbc.h
	g++ -std=c++0x ${C_FLAGS} -o dbc.o -c dbc.cpp

# Destroy object files
clean:
	rm -f ${CLEAN_FILES}


