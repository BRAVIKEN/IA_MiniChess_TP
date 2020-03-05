#ifndef HELPER_HPP
#define HELPER_HPP


#include <vector>

#include "../mymc.h"


#define WHITE 0
#define BLACK 1

class Helper{

	public:

	//Return 0 for White, 1 for Black or -1 for empty.
	static int getColor(int x, int y, chess_board_t const& board){

		if(board.board[y][x] == 12) return -1;

		if(board.board[y][x] & 1){
			return WHITE;
		}
		else{
			return BLACK;
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

		const auto first = getColor(x1, y1, board);
		const auto second = getColor(x2, y2, board);

		if(first == -1 || second == -1){
			return false;
		}

		if(first == second) return false;

		return true;

	}


};




#endif