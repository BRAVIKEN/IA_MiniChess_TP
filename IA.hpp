#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <vector>

#include "mymc.hpp"
#include "GameHelper.hpp"
#include "PiecesSrc/AllPieces.hpp"

class IA {

	public:
		/*
		**Return a movement determined by the Monte Carlo algorithme.
		**It take the board of the game, and the color of the player.
		*/
		static chess_move_t MC(chess_board_t const& board, int color, int playoutNB);

		static bool MCTS();

	};

#endif