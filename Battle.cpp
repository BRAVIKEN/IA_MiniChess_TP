#include "Battle.hpp"

#include <iostream>

#include "mymc.hpp"
#include "GameHelper.hpp"

bool Battle::BattleTwo(chess_move_t (*firstFunc)(int, int, chess_board_t const&), chess_move_t (*secondFunc)(int, int, chess_board_t const&), int playoutNB){

	chess_board_t chess;

    chess.init_silverman_4x5();
    chess.print_board_with_color();

	int player = BLACK;

	while(1){

		chess_move_t move = firstFunc(playoutNB, WHITE, chess);
		GameHelper::play(move, chess);
		chess.print_board_with_color();

		if(GameHelper::isEquality(chess)){
			std::cout << "Equality." << std::endl;
		}

		int who = GameHelper::whoWon(chess);
		if(who != -1){

			if(who == WHITE){
				std::cout << "White gagne." << std::endl;
			}
			else{
				std::cout << "Black gagne." << std::endl;
			}

			break;

		}

		chess_move_t move2 = secondFunc(playoutNB, BLACK, chess);
		GameHelper::play(move2, chess);
		chess.print_board_with_color();

		
		if(GameHelper::isEquality(chess)){
			std::cout << "Equality." << std::endl;
		}

		who = GameHelper::whoWon(chess);
		if(who != -1){

			if(who == WHITE){
				std::cout << "White gagne." << std::endl;
			}
			else{
				std::cout << "Black gagne." << std::endl;
			}

			break;

		}

	}

	return true;

}