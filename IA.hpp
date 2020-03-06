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
		 * @param turn If it's true, white start. Black start otherwise.
		 * 
		 * @return 0 if white won, 1 if black won et -1 si match nul ou timeout.
		 */
		static int randomGame(bool turn, chess_board_t& board);


		/*
		**Return a movement determined by the Monte Carlo algorithme.
		**It take the board of the game, and the color of the player.
		*/
		static chess_move_t MC(const chess_board_t& board, int color, int playoutNB, int startDepth);

		static void getBoardsFromDepth(chess_board_t board, int depth, int maxDepth,chess_move_t move, std::vector<std::pair<chess_board_t,chess_move_t>>& allBoards, int color);


		static chess_move_t MCTS(int playoutNB, int color, chess_board_t const& board);
		
	};

#endif