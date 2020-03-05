#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <vector>

#include "../mymc.h"
#include "Helper.hpp"

class Bishop{

	public:

		static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board){
			std::vector<chess_move_t> toReturn;

			//down left side
			for(int i(x - 1), j(y - 1); i >= 0 && j >= 0; --i,--j){

				if(board.board[j][i] != EMPTY){
					
					if(Helper::colorDifference(x, y, i, j, board)){
						toReturn.emplace_back(x,y,i,j);
					}

					break;
				
				}

				toReturn.emplace_back(x,y,i,j);

			}

			//up left side
			for(int i(x - 1), j(y + 1); i >= 0 && j < board.nbl; --i,++j){
				if(board.board[j][i] != EMPTY){
					
					if(Helper::colorDifference(x, y, i, j, board)){
						toReturn.emplace_back(x,y,i,j);
					}

					break;
				
				}

				toReturn.emplace_back(x,y,i,j);
			}

			//down right side
			for(int i(x + 1), j(y - 1); i < board.nbc && j >= 0; ++i,--j){
				if(board.board[j][i] != EMPTY){
					
					if(Helper::colorDifference(x, y, i, j, board)){
						toReturn.emplace_back(x,y,i,j);
					}

					break;
				
				}

				toReturn.emplace_back(x,y,i,j);
			}

			//up right side
			for(int i(x + 1), j(y + 1); i < board.nbc && j < board.nbl; ++i,++j){
				if(board.board[j][i] != EMPTY){
					
					if(Helper::colorDifference(x, y, i, j, board)){
						toReturn.emplace_back(x,y,i,j);
					}

					break;
				
				}

				toReturn.emplace_back(x,y,i,j);
			}

			return toReturn;
			
		}

		static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board){

		}
};


#endif