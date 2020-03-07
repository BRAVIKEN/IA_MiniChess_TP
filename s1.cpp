#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <iostream>

#include "Battle.hpp"

#include "mymc.hpp"
#include "IA.hpp"
#include "PiecesSrc/AllPieces.hpp"

/* g++ -std=c++11 s1.cpp */

int main(int _ac, char** _av) {

    //srand(1);

	//1583539105
	int KEY(time(NULL));

    srand(KEY);

    chess_board_t chess;
    Helper h;

    chess.init_silverman_4x5();
    chess.print_board_with_color();

												//Profondeur max //Nb Game
	Battle::BattleChronoFirstOne(IA::MCTS, IA::random, 1000, 2);

    return 0;
}