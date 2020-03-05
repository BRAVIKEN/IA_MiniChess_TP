#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <iostream>

#include "mymc.hpp"
#include "PiecesSrc/AllPieces.hpp"

/* g++ -std=c++11 s1.cpp */

int main(int _ac, char** _av) {

    srand(1);


    chess_board_t chess;
    Helper h;

    chess.init_silverman_4x5();
    chess.print_board_with_color();

	

	//std::cout << Rook::isPossible(1, 1, 2, 2, chess) << std::endl;

    //je fou -1 pour le debug, j'assigne les cases trouvé a -1 comme ca ca affiche les possibilités
	/*for(auto e : Queen::allPossible(1, 3, chess)){
		std::cout << "X: " << e.col_i << " y: " << e.line_i << std::endl;
		chess.board[e.line_i][e.col_i] = -1;
	}*/

	chess.print_board_with_color();

	std::cout << h.checkWhite(2,0,chess) << std::endl;

    return 0;
}