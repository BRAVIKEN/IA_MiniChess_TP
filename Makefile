CC = g++
SRC = s1.cpp \
	mymc.cpp \
	GameHelper.cpp \
	IA.cpp \
	MC.cpp \
	PiecesSrc/AllPieces.cpp \
	PiecesSrc/Helper.cpp \
	PiecesSrc/Knight.cpp \
	PiecesSrc/Pawn.cpp \
	PiecesSrc/King.cpp \
	PiecesSrc/Bishop.cpp \
	PiecesSrc/Queen.cpp \
	PiecesSrc/Rook.cpp

INCLUDES = mymc.hpp \
		GameHelper.hpp \
		IA.hpp \
		PiecesSrc/AllPieces.hpp \
		PiecesSrc/Helper.hpp \
		PiecesSrc/Knight.hpp \
		PiecesSrc/Pawn.hpp \
		PiecesSrc/King.hpp \
		PiecesSrc/Bishop.hpp \
		PiecesSrc/Queen.hpp \
		PiecesSrc/Rook.hpp

HEADER_ONLY = mymc.hpp \
			GameHelper.hpp \
			IA.hpp \
			PiecesSrc/AllPieces.hpp \
			PiecesSrc/Helper.hpp \
			PiecesSrc/Pawn.hpp \
			PiecesSrc/King.hpp \
			PiecesSrc/Bishop.hpp \
			PiecesSrc/Queen.hpp \
			PiecesSrc/Rook.hpp

OBJ = $(SRC:.cpp=.o)
CFLAGS = -O2 -Wall -pedantic -std=c++11
LDFLAGS =

chess.out:    $(OBJ) $(INCLUDES) 
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)
	
%.o:	%.cpp %.hpp mymc.hpp PiecesSrc/Helper.hpp $(HEADER_ONLY)
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

%.o:	%.cpp mymc.hpp PiecesSrc/Helper.hpp $(HEADER_ONLY)
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)


clean:
	rm *.o
	rm PiecesSrc/*.o