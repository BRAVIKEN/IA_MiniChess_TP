#ifndef IA_HPP
#define IA_HPP

#include <vector>

#include "mymc.hpp"
#include "GameHelper.hpp"
#include "PiecesSrc/AllPieces.hpp"

class IA {

	public:


		static bool whitePlayOneRandomMove(chess_board_t const& board);
		static bool blackPlayOneRandomMove(chess_board_t const& board);

		/**
		 * Play a random game.
		 * 
		 * @return True if white won, False if black won.
		 */
		static bool randomGame(chess_board_t const& board);


		/*
		**Return a movement determined by the Monte Carlo algorithme.
		**It take the board of the game, and the color of the player.
		*/
		static chess_move_t MC(chess_board_t const& board, int color, int playoutNB);

		static bool MCTS();

	};

#endif