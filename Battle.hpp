#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "PiecesSrc/AllPieces.hpp"

class Battle {
   
	public:
		
		/**
		 * Battle between first func and second func. 
		 * select the playout
		*/
		static void BattleTwo(chess_move_t (*firstFunc)(int, int, chess_board_t const&), chess_move_t (*secondFunc)(int, int, chess_board_t const&), int playoutNB);

		/**
		 * Battle between first func and second func.
		 * Print to average playing time of the first function for n game at the end. 
		 * select the playout and the number of game
		*/
		static void BattleChronoFirstOne(chess_move_t (*firstFunc)(int, int, chess_board_t const&), chess_move_t (*secondFunc)(int, int, chess_board_t const&), int playoutNB, int nbGame);


};

#endif  // BATTLE_HPP
