#ifndef IA_HPP
#define IA_HPP

#include <vector>

#include "mymc.hpp"
#include "GameHelper.hpp"
#include "PiecesSrc/AllPieces.hpp"

class IA {

	public:


		static bool whitePlayOneRandomMove(chess_board_t& board);
		static bool blackPlayOneRandomMove(chess_board_t& board);

		/**
		 * Play a random game.
		 * 
		 * @return 0 if white won, 1 if black won et -1 si match nul ou timeout.
		 */
		static int randomGame(chess_board_t& board);


		/*
		**Return a movement determined by the Monte Carlo algorithme.
		**It take the board of the game, and the color of the player.
		*/
		static chess_move_t MC(chess_board_t const& board, int color, int playoutNB);

		static bool MCTS();

	};

#endif