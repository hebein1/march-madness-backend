LIB_DIR = lib
GTEST_DIR = ${LIB_DIR}/gtest-1.7.0
CLEAN_FILES = given_c5_runner mmp_c5_tests mmp_c5_tests.o mmp_c5_functions.o given_c5_runner.o mmp.tmp mmp.tree

all: clean given_c5_runner mmp_c5_tests

init : gtest

gtest:
	g++ -isystem ${PWD}/../${GTEST_DIR}/include -I ${PWD}/../${GTEST_DIR} -pthread -c ${PWD}/../${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

given_c5_runner: given_c5_runner.o
	gcc given_c5_runner.o -lm -o given_c5_runner

given_c5_runner.o: given_c5_runner.c given_c5_defns.h given_c5_global.c given_c5_hooks.c
	gcc -o given_c5_runner.o -c given_c5_runner.c

mmp_c5_tests: mmp_c5_tests.cpp mmp_c5_functions.o
	g++ -isystem ${PWD}/../${GTEST_DIR}/include -c mmp_c5_tests.cpp
	g++ -isystem ${PWD}/../${GTEST_DIR}/include -pthread mmp_c5_tests.o mmp_c5_functions.o ${PWD}/../${GTEST_DIR}/src/gtest_main.cc libgtest.a -o mmp_c5_tests

mmp_c5_functions.o: mmp_c5_functions.cpp mmp_c5_functions.h
	g++ -o mmp_c5_functions.o -c mmp_c5_functions.cpp

clean:
	rm -f ${CLEAN_FILES}
