GCC=gcc

TARGETS = ncaa_train ncaa_test

GTEST_DIR=gtest-1.7.0

all: $(TARGETS) ann_test

init: gtest

gtest: 
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c \
	 	${GTEST_DIR}/src/gtest-all.cc 
	ar -rv libgtest.a gtest-all.o

ann_test: ncaa_train.cpp ncaa_train.o
	g++ -isystem ${PWD}/${GTEST_DIR}/include -c annTest.cpp 
	g++ -isystem ${PWD}/${GTEST_DIR}/include -pthread annTest.o \
		${PWD}/${GTEST_DIR}/src/gtest_main.cc ${PWD}/${GTEST_DIR}/libgtest.a \
		-lfann -lm -o ann_test

%: %.cpp Makefile
	$(GCC) -O3 $< -o $@ -lfann -lm

clean:
	rm -f $(TARGETS) ann_test *.net *~ *.obj *.exe *.tds *.o

runalgo: $(TARGETS)
	@echo
	@echo Training network
	./ncaa_train

	@echo
	@echo Testing network with floats
	./ncaa_test
