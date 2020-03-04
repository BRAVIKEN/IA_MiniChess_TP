
CC=g++

CFLAG= -O2 -Wall -pedantic -std=c++11


exec.out: s1.o
	$(CC) -o exec.out s1.o

s1.o: s1.cpp mymc.h AllPawn.hpp Knight.cpp Knight.hpp
	$(CC) -c s1.cpp $(CFLAG)

clean: 
	rm *.o