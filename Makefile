
CC=g++

CFLAG= -O2 -Wall -pedantic


exec.out: mymc.h s1.o
	$(CC) -o exec.out s1.o

s1.o: s1.cpp
	$(CC) -c s1.cpp $(CFLAG)