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
		 * @param turn If it's false, white start. Black start otherwise.
		 * 
		 * @return 0 if white won, 1 if black won et -1 si match nul ou timeout.
		 */
		static int randomGame(bool turn, chess_board_t& board);

		static chess_move_t random(int playoutNB, int color, chess_board_t const& board);

		/*
		**Return a movement determined by the Monte Carlo algorithme.
		**It take the board of the game, and the color of the player.
		*/
		static chess_move_t MC(int playoutNB, int color, chess_board_t const& board_);

		static void getBoardsFromDepth(chess_board_t board, int depth, int maxDepth,chess_move_t move, std::vector<std::pair<chess_board_t,chess_move_t>>& allBoards, int color);


		static chess_move_t MCTS(int playoutNB, int color, chess_board_t const& board);

		static std::pair<int,chess_move_t> nested_MC(int _level, int _color, int _startColor, std::pair<int,chess_move_t> _scoreAndMove, bool start, chess_board_t const& _board);

		static chess_move_t NMCS(int depth, int color, chess_board_t const& board);

		static chess_move_t anytime_NMC(int _level, int _color, chess_board_t const& _board);


		#include "IA.hpp"
		
	};

#endif