CC=gcc
CFLAGS=-g -lstdc++ -std=c++11
all : Scanner

Scanner: main.cpp scanner.cpp scanner.hpp token.hpp testScanner.cpp testScanner.hpp
	$(CC) -o $@ $^ $(CFLAGS) 

clean:
	rm Scanner
