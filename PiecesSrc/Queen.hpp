#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <vector>

#include "../mymc.h"
#include "Helper.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"

class Queen{

	public:

		static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board){

			std::vector<chess_move_t> toReturn = Rook::allPossible(x,y,board);
			std::vector<chess_move_t> BishopMoves = Bishop::allPossible(x,y,board);
			
			toReturn.insert(toReturn.end(),BishopMoves.begin(), BishopMoves.end());

			return toReturn;
		}

		static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board){

		}
};


#endif