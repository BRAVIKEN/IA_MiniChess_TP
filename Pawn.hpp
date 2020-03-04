#ifndef PAWN_HPP
#define PAWN_HPP

#include <vector>

#include "mymc.h"
#include "AllPawn.hpp"

class Pawn{
	public:
		static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board){
			std::vector<chess_move_t> toReturn;
			if(Helper::getColor(x,y,board) == BLACK){ //si c'est noir

				//forward
		        if (board.board[y + 1][x] == EMPTY && y != board.nbl - 1)
		        	toReturn.emplace_back(x,y,x,y+1);
		        //eat left
		        if (y != (board.nbl - 1) && x != 0 && Helper::getColor(x - 1, y + 1, board) == WHITE)
		            toReturn.emplace_back(x,y,x-1,y+1);
		        //eat right
		        if (y != (board.nbl - 1) && x != (board.nbc - 1) && Helper::getColor(x + 1, y + 1, board) == WHITE)
		            toReturn.emplace_back(x,y,x-1,y+1);

			} else { // sinon blanc

				//forward
			    if (y != 0 && board.board[y - 1][x] == EMPTY)
			        toReturn.emplace_back(x,y,x,y-1);

			    //eat left
		        if (y != 0 && x != 0 && Helper::getColor(x - 1,y - 1, board) == BLACK)
		            toReturn.emplace_back(x,y,x-1,y-1);

		        //eat right
		        if (y != 0 && x != (board.nbc - 1) && Helper::getColor(x + 1, y - 1, board) == BLACK)
		            toReturn.emplace_back(x,y,x+1,y-1);

			}
		}

		static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board){

		}
};


#endif