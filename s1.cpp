#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <iostream>

#include "mymc.h"
#include "PiecesSrc/AllPieces.hpp"

/* g++ -std=c++11 s1.cpp */

int main(int _ac, char** _av) {

    srand(1);


    chess_board_t chess;

    chess.init_silverman_4x5();
    chess.print_board_with_color();

	

	std::cout << Rook::isPossible(1, 1, 2, 2, chess) << std::endl;

	for(auto e : King::allPossible(2, 2, chess)){
		std::cout << "X: " << e.col_i << " y: " << e.line_i << std::endl;
	}

    return 0;

}
