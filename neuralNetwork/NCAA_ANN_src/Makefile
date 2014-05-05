GCC=g++

TARGETS = ncaa 

LIB_DIR=lib

GTEST_DIR=${LIB_DIR}/gtest-1.7.0

all: $(TARGETS) ann_test

init: gtest

gtest: 
	g++ -isystem ${PWD}/../../${GTEST_DIR}/include -I ${PWD}/../../${GTEST_DIR} -pthread -c \
	 	${PWD}/../../${GTEST_DIR}/src/gtest-all.cc 
	ar -rv libgtest.a gtest-all.o	

ann_test: ncaa_train.cpp ncaa_train.o
	g++ -isystem ${PWD}/../../${GTEST_DIR}/include -c annTest.cpp 
	g++ -isystem ${PWD}/../../${GTEST_DIR}/include -pthread annTest.o ncaa_test.o \
		${PWD}/../../${GTEST_DIR}/src/gtest_main.cc libgtest.a \
		-lfann -lm -Wall -Wextra -g -o ann_test

ncaa: ncaa_train.cpp ncaa_test.cpp Makefile
	$(GCC) -O3 ncaa_train.cpp -o ncaa_train.o -lfann -c -lm -Wall -Wextra -g
	$(GCC) -O3 ncaa_test.cpp -o ncaa_test.o -lfann -c -lm -Wall -Wextra -g

clean:
	rm -f $(TARGETS) ann_test *.net *~ *.obj *.exe *.tds *.o

runalgo: $(TARGETS)
	@echo
	@echo Training network
	./ncaa_train

	@echo
	@echo Testing network
	./ncaa_test
