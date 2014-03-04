LIB_DIR=lib
GTEST_DIR=${LIB_DIR}/gtest-1.7.0
CLEAN_FILES=sample sample_test sample_test.o

all: sample sample_test

init : gtest

gtest:
	g++ -isystem ${PWD}/../../${GTEST_DIR}/include -I ${PWD}/../../${GTEST_DIR} -pthread -c \
	 	${PWD}/../../${GTEST_DIR}/src/gtest-all.cc 
	ar -rv libgtest.a gtest-all.o

sample:
	gcc sample.c -lm -o sample

sample_test: sample_test.cpp
	g++ -isystem ${PWD}/../../${GTEST_DIR}/include -c sample_test.cpp
	g++ -isystem ${PWD}/../../${GTEST_DIR}/include -pthread sample_test.o \
		${PWD}/../../${GTEST_DIR}/src/gtest_main.cc libgtest.a \
		-o sample_test

clean:
	rm -f ${CLEAN_FILES}
