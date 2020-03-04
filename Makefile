
CC=g++

CFLAG= -O2 -Wall -pedantic -std=c++11


exec.out: mymc.h s1.o
	$(CC) -o exec.out s1.o

s1.o: s1.cpp AllPawn.hpp
	$(CC) -c s1.cpp $(CFLAG)