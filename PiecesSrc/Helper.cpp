#include "Helper.hpp"

int Helper::getColor(int x, int y, chess_board_t const& board) {
    if (board.board[y][x] == 12) return -1;

    if (board.board[y][x] & 1) {
        return WHITE;
    } else {
        return BLACK;
    }
}

bool Helper::colorDifference(int x1, int y1, int x2, int y2, chess_board_t const& board) {
    return !(getColor(x1, y1, board) == getColor(x2, y2, board));
}


//return a vector of a selected pieces with there positions
std::vector<chess_piece_t> Helper::getPiecePos(chess_board_t const& board, int piece){

	std::vector<chess_piece_t> toReturn;

	for(auto i(0); i<board.nbl; i++){
		for(auto j(0); j<board.nbc; j++){
			if(board.board[i][j] == piece)
				toReturn.emplace_back(piece,i,j);
		}
	}

	return toReturn;

}

//#include <iostream> //debug
