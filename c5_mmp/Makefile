LIB_DIR = lib
GTEST_DIR = ${LIB_DIR}/gtest-1.7.0
CLEAN_FILES = given_c5_runner mmp_c5_tests mmp_c5_tests.o mmp.tmp mmp.tree

all: clean given_c5_runner mmp_c5_tests

init : gtest

gtest:
	g++ -isystem ${PWD}/../${GTEST_DIR}/include -I ${PWD}/../${GTEST_DIR} -pthread -c ${PWD}/../${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

given_c5_runner:
	gcc given_c5_runner.c -lm -o given_c5_runner

mmp_c5_tests:
	g++ -isystem ${PWD}/../${GTEST_DIR}/include -c mmp_c5_tests.cpp
	g++ -isystem ${PWD}/../${GTEST_DIR}/include -pthread mmp_c5_tests.o ${PWD}/../${GTEST_DIR}/src/gtest_main.cc libgtest.a -o mmp_c5_tests

clean:
	rm -f ${CLEAN_FILES}
