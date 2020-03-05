CC = g++
SRC = s1.cpp PiecesSrc/Knight.cpp
INCLUDES = mymc.h PiecesSrc/Helper.hpp PiecesSrc/Knight.hpp PiecesSrc/Pawn.hpp PiecesSrc/King.hpp PiecesSrc/Bishop.hpp
OBJ = $(SRC:.cpp=.o)
CFLAGS = -O2 -Wall -pedantic -std=c++11
LDFLAGS =

chess.out:    $(OBJ) $(INCLUDES) 
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)
	
%.o:	%.cpp %.hpp mymc.h PiecesSrc/Helper.hpp
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

%.o:	%.cpp mymc.h PiecesSrc/Helper.hpp
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)


clean:
	rm *.o
	rm PiecesSrc/*.o