#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <vector>

#include "../mymc.h"
#include "Helper.hpp"

class Bishop{

	public:

		static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board){
			std::vector<chess_move_t> toReturn;

			//partie gauche haute
			for(auto i(x - 1),j(y - 1); i >= 0; --i,--j){
				bool eated = Helper::colorDifference(x, y, i, j, board);
				if(j >= 0 && (board.board[j][i] == EMPTY || eated)){
					toReturn.emplace_back(x,y,i,j);
					if(eated){
						break;
					}
				} else {
					break;
				}
			}

			//partie gauche basse
			for(auto i(x - 1),j(y + 1); i >= 0; --i,++j){
				bool eated = Helper::colorDifference(x, y, i, j, board);
				if(j < board.nbl && (board.board[j][i] == EMPTY || eated)){
					toReturn.emplace_back(x,y,i,j);
					if(eated){
						break;
					}
				} else {
					break;
				}
			}

			//partie droite haute
			for(auto i(x + 1),j(y - 1); i < board.nbc; ++i,--j){
				bool eated = Helper::colorDifference(x, y, i, j, board);
				if(j >= 0 && (board.board[j][i] == EMPTY || eated)){
					toReturn.emplace_back(x,y,i,j);
					if(eated){
						break;
					}
				} else {
					break;
				}
			}

			//partie droite basse
			for(auto i(x + 1),j(y + 1); i < board.nbc; ++i,++j){
				bool eated = Helper::colorDifference(x, y, i, j, board);
				if(j < board.nbl && (board.board[j][i] == EMPTY || eated)){
					toReturn.emplace_back(x,y,i,j);
					if(eated){
						break;
					}
				} else {
					break;
				}
			}
			return toReturn;
		}

		static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board){

		}
};


#endif