SHELL := /bin/bash
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Wall -Werror=return-type  \
			-Werror=uninitialized -Wno-sign-compare

TESTS = test-1-deck test-2-deck test-3-deck
CATCH = test/catch/catch.o

test-all: $(TESTS)

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(TESTS) $(CATCH)

test-1-deck: test/test-1-deck.o
test-2-deck: test/test-2-deck.o
test-3-deck: test/test-3-deck.o

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

