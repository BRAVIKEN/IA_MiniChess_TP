
CC=g++

CFLAG= -O2 -Wall -pedantic -std=c++11


exec.out: s1.o
	$(CC) -o exec.out s1.o

s1.o: s1.cpp mymc.h AllPawn.hpp
	$(CC) -c s1.cpp $(CFLAG)