
#ifndef GAMEHELPER_HPP
#define GAMEHELPER_HPP


#include <vector>

#include "mymc.hpp"
#include "PiecesSrc/AllPieces.hpp"


class GameHelper {

	public:

		/**
		 * Verify if one color is in check.
		 * Take the king position in param.
		 * 
		 * @return true if white or black is in check state.
		 */
		static bool checkBlack(int kingX, int kingY, chess_board_t const& board);
		static bool checkWhite(int kingX, int kingY, chess_board_t const& board);

		/**
		 *  Verify if their is an equality
		 * 
		 * @return True if their is an equality, false otherwise
		 */
		static bool isEquality(chess_board_t const& board);
		static int whoWon(chess_board_t& board);

		/**
		 * Return all the possible move of the color
		 */ 
		static std::vector<chess_move_t> AllPossibleMovesBlack(chess_board_t& board);
		static std::vector<chess_move_t> AllPossibleMovesWhite(chess_board_t& board);

		//Play a move
		static void play(chess_move_t const& piece, chess_board_t& board);
		
		//Unplay a move
		static void unplay(chess_move_t const& piece, chess_board_t& board);
};



#endif