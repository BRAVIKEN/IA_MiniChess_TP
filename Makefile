CC = g++
SRC = s1.cpp PiecesSrc/Knight.cpp
INCLUDES = mymc.h PiecesSrc/Helper.hpp PiecesSrc/Knight.hpp PiecesSrc/Pawn.hpp PiecesSrc/King.hpp
OBJ = $(SRC:.cpp=.o)
CFLAGS = -O2 -Wall -pedantic -std=c++11
LDFLAGS =

chess:    $(OBJ) $(INCLUDES) 
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)
	
%.o:	%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	
clean:
	rm *.o
	rm PiecesSrc/*.o