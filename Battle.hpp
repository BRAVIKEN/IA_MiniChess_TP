#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "PiecesSrc/AllPieces.hpp"

class Battle {
   
	public:
		
		static bool BattleTwo(chess_move_t (*firstFunc)(int, int, chess_board_t const&), chess_move_t (*secondFunc)(int, int, chess_board_t const&), int playoutNB);



};

#endif  // BATTLE_HPP
