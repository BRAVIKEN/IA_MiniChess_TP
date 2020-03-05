
CC=g++

CFLAG= -O2 -Wall -pedantic -std=c++11



exec.out: s1.o PiecesSrc/Knight.o
	$(CC) -o exec.out s1.o PiecesSrc/Knight.o

s1.o: s1.cpp mymc.h PiecesSrc/Helper.hpp PiecesSrc/Pawn.hpp PiecesSrc/King.hpp
	$(CC) -c s1.cpp $(CFLAG)

PiecesSrc/Knight.o: PiecesSrc/Knight.cpp PiecesSrc/Helper.hpp mymc.h
	$(CC) -c PiecesSrc/Knight.cpp $(CFLAG)
	mv Knight.o PiecesSrc

clean: 
	rm *.o