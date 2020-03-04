
#include "AllPawn.hpp"

#include <vector>



class King {

	std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board){
		
		std::vector<chess_move_t> toRet;

		//L R D U
		//1 1 1 1
		//1 2 4 8

		int sumPossible(0);

		//can left
		if(x > 0){
			if(Helper::colorDifference(x, y, x-1, y, board))
				toRet.emplace_back(x, y, x-1, y);

			sumPossible += 1;
		}

		//can right
		if(x < board.nbc-1){
			if(Helper::colorDifference(x, y, x+1, y, board))
				toRet.emplace_back(x, y, x+1, y);

			sumPossible += 2;
		}

		//can down
		if(y > 0 ){
			if(Helper::colorDifference(x, y, x, y-1, board))
				toRet.emplace_back(x, y, x, y-1);
				
			sumPossible += 4;
		}

		//can up
		if(y < board.nbl-1){
			if(Helper::colorDifference(x, y, x, y+1, board))
				toRet.emplace_back(x, y, x, y+1);

			sumPossible += 8;
		}


		//down left
		if(sumPossible & 5)
			if(Helper::colorDifference(x, y, x-1, y-1, board))
				toRet.emplace_back(x, y, x-1, y-1);

		//down right
		if(sumPossible & 6)
			if(Helper::colorDifference(x, y, x+1, y-1, board))
				toRet.emplace_back(x, y, x+1, y-1);

		//up left
		if(sumPossible & 9)
			if(Helper::colorDifference(x, y, x-1, y+1, board))
				toRet.emplace_back(x, y, x-1, y+1);

		//up right
		if(sumPossible & 10)
			if(Helper::colorDifference(x, y, x+1, y+1, board))
				toRet.emplace_back(x, y, x+1, y+1);


		return toRet;

	}



};