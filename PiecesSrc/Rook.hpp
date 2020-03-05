#ifndef ROOK_HPP
#define ROOK_HPP

#include "../mymc.h"
#include "Helper.hpp"

//Tour
class Rook {

	public:

	//This method return all the next move possible from a Rook on x y in the board.
	static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board){

		std::vector<chess_move_t> toRet;

		//From x y to the right
		for(int i(x+1); i < board.nbc; ++i){

			if(board.board[y][i] != EMPTY){
				
				if(Helper::colorDifference(x, y, i, y, board)){
					toRet.emplace_back(x, y, i, y);
				}

				break;
			}

			toRet.emplace_back(x, y, i, y);

		}

		//From x y to the left
		for(int i(x-1); i >= 0; --i){

			if(board.board[y][i] != EMPTY){
				
				if(Helper::colorDifference(x, y, i, y, board)){
					toRet.emplace_back(x, y, i, y);
				}

				break;
			}

			toRet.emplace_back(x, y, i, y);

		}

		//From x y to the top
		for(int i(y+1); i < board.nbl; ++i){

			if(board.board[i][x] != EMPTY){
				
				if(Helper::colorDifference(x, y, x, i, board)){
					toRet.emplace_back(x, y, x, i);
				}

				break;
			}

			toRet.emplace_back(x, y, x, i);

		}

		//From x y to the down
		for(int i(y-1); i >= 0; --i){

			if(board.board[i][x] != EMPTY){
				
				if(Helper::colorDifference(x, y, x, i, board)){
					toRet.emplace_back(x, y, x, i);
				}

				break;
			}

			toRet.emplace_back(x, y, x, i);

		}

		return toRet;

	}


	static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board){

		//If not in line
		if(x != xTo && y != yTo){
			return false;
		}

		//If move on X axis
		if(x != xTo){

			int step(x > xTo ? -1 : 1);
			for(int i(x + step); i != xTo; i += step){
				if(board.board[y][i] != EMPTY){
					return false;
				}
			}

		}
		//If move on Y axis
		else if(y != yTo){
			
			int step(y > yTo ? -1 : 1);
			for(int i(y + step); i != yTo; i += step){
				if(board.board[i][x] != EMPTY){
					return false;
				}
			}

		}
		//If not moved (x == xTo && y == yTo)
		else{
			return false;
		}

		if(Helper::colorDifference(x, y, xTo, yTo, board)){
			return true;
		}
		else{
			return false;
		}
		
	}

};

#endif