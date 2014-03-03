GCC=gcc

TARGETS = ncaa_train ncaa_test ncaa_test_fixed

all: $(TARGETS)

%: %.c Makefile
	$(GCC) -O3 $< -o $@ -lfann -lm

%_fixed: %.c Makefile
	$(GCC) -O3 -DFIXEDFANN $< -o $@ -lfixedfann -lm

clean:
	rm -f $(TARGETS) ncaa_fixed.data *.net *~ *.obj *.exe *.tds

runtest: $(TARGETS)
	@echo
	@echo Training network
	./ncaa_train

	@echo
	@echo Testing network with floats
	./ncaa_test

	@echo
	#@echo Testing network with fixed points
	./ncaa_test_fixed
