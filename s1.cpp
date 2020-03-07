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

    chess.init_silverman_4x5();

	std::cout << "MCTS : " << std::endl << std::endl;
	Battle::BattleChronoFirstOne(IA::MCTS, IA::random, 100000, 2);
	std::cout << "MC : " << std::endl << std::endl;
	Battle::BattleChronoFirstOne(IA::startMC, IA::MCTS, 300, 1);
	std::cout << "MCTS BLANC vs MC NOIR " << std::endl << std::endl;
	Battle::BattleTwo(IA::MCTS, IA::startMC, 500);


    return 0;
}