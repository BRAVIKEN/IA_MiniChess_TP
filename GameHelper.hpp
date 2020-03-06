
#ifndef GAMEHELPER_HPP
#define GAMEHELPER_HPP


#include <vector>

#include "mymc.hpp"
#include "PiecesSrc/AllPieces.hpp"


class GameHelper {

	public:
		static bool checkBlack(int kingX, int kingY, chess_board_t const& board);
		static bool checkWhite(int kingX, int kingY, chess_board_t const& board);

		//TODO
		static bool checkMateBlack(int kingX, int kingY, chess_board_t const& board);
		static bool checkMateWhite(int kingX, int kingY, chess_board_t const& board);

		///TO DO
		//Fonction qui renvoie tout les coups possible de blanc et noir
		static std::vector<chess_move_t> AllPossibleMovesBlack(chess_board_t& board);
		static std::vector<chess_move_t> AllPossibleMovesWhite(chess_board_t& board);

		///TODO
		static int whiteScore(chess_board_t const& board);
		static int blackScore(chess_board_t const& board);
		
		static void play(chess_move_t const& piece, chess_board_t& board);
		static void unplay(chess_move_t const& piece, chess_board_t& board);
};



#endif