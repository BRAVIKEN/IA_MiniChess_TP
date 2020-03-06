#ifndef ALL_PIECES
#define ALL_PIECES

#include "Helper.hpp"

#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

class AllPieces {

	public:
	    /**
		 * This methode take a chess_piece_t and a chess_board_t as a prameter
		 * and will select itself which static class to use depending of the piece
		 * and will call it's allPossible method.
		 * 
		 * @return A vector containing all the possible moves of the piece
		 */
	    static std::vector<chess_move_t> allPossible(chess_piece_t const& piece, chess_board_t const& board);
};

#endif