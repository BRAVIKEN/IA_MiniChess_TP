#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <iostream>

#include "mymc.hpp"
#include "IA.hpp"
#include "PiecesSrc/AllPieces.hpp"

/* g++ -std=c++11 s1.cpp */

int main(int _ac, char** _av) {

    srand(1);
    srand(time(NULL));

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

	chess_move_t m = IA::MC(chess,WHITE,1000);
	chess.board[m.line_i][m.col_i] = chess.board[m.line_f][m.col_f];
	chess.board[m.line_f][m.col_f] = EMPTY;
	chess.print_board_with_color();

	//std::cout << h.checkWhite(2,0,chess) << std::endl;

    return 0;
}