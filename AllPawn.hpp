
#include <iostream>
#include <vector>

#include "mymc.h"


class Helper{

	public:

	//Return 0 for White, 1 for Black or -1 for empty.
	static int getColor(int x, int y, chess_board_t const& board){

		if(board.board[y][x] == 12) return -1;

		if(board.board[y][x] & 1){
			return 0;
		}
		else{
			return 1;
		}

	}

	/**
	 * Verify if color are different.
	 * Note : Empty is considered as a third color.
	 * (So empty with any color will return true)
	 * 
	 * @return True if they are from different color, false otherwise.
	 */
	static bool colorDifference(int x1, int y1, int x2, int y2, chess_board_t const& board){

		if(getColor(x1, y1, board) == getColor(x2, y2, board)) return false;

		return true;


	}


};


//Tour
class Rook {

	public:

	static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board){

		std::vector<chess_move_t> toRet;

		for(int i(x); i < board.nbc; ++i){

			if(board.board[y][i] != EMPTY){
				
				if(Helper::colorDifference(x, y, i, y, board)){
					toRet.emplace_back(x, y, i, y);
				}

				break;
			}

			toRet.emplace_back(x, y, i, y);

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