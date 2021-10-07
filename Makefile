CC=gcc
CFLAGS=-g -lstdc++
all : P1

P1: main.cpp scanner.cpp scanner.hpp token.hpp
	$(CC) -o $@ $^ $(CFLAGS) 

clean:
	rm P1