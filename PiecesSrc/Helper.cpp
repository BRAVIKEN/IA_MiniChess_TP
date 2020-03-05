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
bool Helper::checkBlack(int x, int y, chess_board_t const& board){

	/*diag*/
	for (int i(x - 1), j(y - 1); i >= 0 && j >= 0; --i, --j) {
        if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }

    for (int i(x - 1), j(y + 1); i >= 0 && j < board.nbl; --i, ++j) {
    	if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }

    for (int i(x + 1), j(y - 1); i < board.nbc && j >= 0; ++i, --j) {
        if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }

    for (int i(x + 1), j(y + 1); i < board.nbc && j < board.nbl; ++i, ++j) {
        if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }


    /*line*/
    for (int i(x + 1); i < board.nbc; ++i) {
        if (board.board[y][i] == WHITE_Q || board.board[y][i] == WHITE_R)
        	return true;
    }

    for (int i(x - 1); i >= 0; --i) {
        if (board.board[y][i] == WHITE_Q || board.board[y][i] == WHITE_R)
        	return true;
    }

    for (int i(y + 1); i < board.nbl; ++i) {
        if (board.board[i][x] == WHITE_Q || board.board[i][x] == WHITE_R)
        	return true;
    }

    for (int i(y - 1); i >= 0; --i) {
        if (board.board[i][x] == WHITE_Q || board.board[i][x] == WHITE_R)
        	return true;
    }


    /*knight*/
    if (x + 2 < board.nbc) {
        if (y + 1 < board.nbl && board.board[y+1][x+2] == WHITE_N) return true;
        if (y - 1 >= 0 && board.board[y-1][x+2] == WHITE_N) return true;
    }

    if (x - 2 >= 0) {
        if (y + 1 < board.nbl && board.board[y+1][x-2] == WHITE_N) return true;
        if (y - 1 >= 0 && board.board[y-1][x-2] == WHITE_N) return true;
    }

    if (y + 2 < board.nbl) {
        if (x + 1 < board.nbc && board.board[y+2][x+1] == WHITE_N) return true;
        if (x - 1 >= 0 && board.board[y+2][x-1] == WHITE_N) return true;
    }

    if (y - 2 >= 0) {
        if (x + 1 < board.nbc && board.board[y-2][x+1] == WHITE_N) return true;
        if (x - 1 >= 0 && board.board[y-2][x-1] == WHITE_N) return true;
    }


    /*pawn*/
    if(board.board[y+1][x-1] == WHITE_P){
    	return true;
    }
    if(board.board[y+1][x+1] == WHITE_P){
    	return true;
    }


	return false;
}

bool Helper::checkWhite(int x, int y, chess_board_t const& board){

	/*diag*/
	for (int i(x - 1), j(y - 1); i >= 0 && j >= 0; --i, --j) {
        if (board.board[j][i] == BLACK_Q && board.board[j][i] == BLACK_B)
        	return true;
    }

    for (int i(x - 1), j(y + 1); i >= 0 && j < board.nbl; --i, ++j) {
    	if (board.board[j][i] == BLACK_Q && board.board[j][i] == BLACK_B)
        	return true;
    }

    for (int i(x + 1), j(y - 1); i < board.nbc && j >= 0; ++i, --j) {
        if (board.board[j][i] == BLACK_Q && board.board[j][i] == BLACK_B)
        	return true;
    }

    for (int i(x + 1), j(y + 1); i < board.nbc && j < board.nbl; ++i, ++j) {
        if (board.board[j][i] == BLACK_Q && board.board[j][i] == BLACK_B)
        	return true;
    }


    /*line*/
    for (int i(x + 1); i < board.nbc; ++i) {
        if (board.board[y][i] == BLACK_Q || board.board[y][i] == BLACK_R)
        	return true;
    }

    for (int i(x - 1); i >= 0; --i) {
        if (board.board[y][i] == BLACK_Q || board.board[y][i] == BLACK_R)
        	return true;
    }

    for (int i(y + 1); i < board.nbl; ++i) {
        if (board.board[i][x] == BLACK_Q || board.board[i][x] == BLACK_R)
        	return true;
    }

    for (int i(y - 1); i >= 0; --i) {
        if (board.board[i][x] == BLACK_Q || board.board[i][x] == BLACK_R)
        	return true;
    }


    /*knight*/
    if (x + 2 < board.nbc) {
        if (y + 1 < board.nbl && board.board[y+1][x+2] == BLACK_N) return true;
        if (y - 1 >= 0 && board.board[y-1][x+2] == BLACK_N) return true;
    }

    if (x - 2 >= 0) {
        if (y + 1 < board.nbl && board.board[y+1][x-2] == BLACK_N) return true;
        if (y - 1 >= 0 && board.board[y-1][x-2] == BLACK_N) return true;
    }

    if (y + 2 < board.nbl) {
        if (x + 1 < board.nbc && board.board[y+2][x+1] == BLACK_N) return true;
        if (x - 1 >= 0 && board.board[y+2][x-1] == BLACK_N) return true;
    }

    if (y - 2 >= 0) {
        if (x + 1 < board.nbc && board.board[y-2][x+1] == BLACK_N) return true;
        if (x - 1 >= 0 && board.board[y-2][x-1] == BLACK_N) return true;
    }

    /*pawn*/
    if(board.board[y-1][x-1] == WHITE_P){
    	return true;
    }
    if(board.board[y-1][x+1] == WHITE_P){
    	return true;
    }

	return false;
}