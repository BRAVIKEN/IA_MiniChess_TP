
#include "GameHelper.hpp"
#include <iostream>


bool GameHelper::checkBlack(int x, int y, chess_board_t const& board){
	
	bool first;

	/*diag*/
	first = true;
	for (int i(x - 1), j(y - 1); i >= 0 && j >= 0; --i, --j) {
		if(first){
			if(board.board[j][i] == WHITE_K) return true;
			first = false;
		}
        if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }

	first = true;
    for (int i(x - 1), j(y + 1); i >= 0 && j < board.nbl; --i, ++j) {
		if(first){
			if(board.board[j][i] == WHITE_K) return true;
			first = false;
		}
    	if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }

	first = true;
    for (int i(x + 1), j(y - 1); i < board.nbc && j >= 0; ++i, --j) {
		if(first){
			if(board.board[j][i] == WHITE_K) return true;
			first = false;
		}
        if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }

	first = true;
    for (int i(x + 1), j(y + 1); i < board.nbc && j < board.nbl; ++i, ++j) {
		if(first){
			if(board.board[j][i] == WHITE_K) return true;
			first = false;
		}
        if (board.board[j][i] == WHITE_Q || board.board[j][i] == WHITE_B)
        	return true;
    }


    /*line*/
	first = true;
    for (int i(x + 1); i < board.nbc; ++i) {
		if(first){
			if(board.board[y][i] == WHITE_K) return true;
			first = false;
		}
        if (board.board[y][i] == WHITE_Q || board.board[y][i] == WHITE_R)
        	return true;
    }

	first = true;
    for (int i(x - 1); i >= 0; --i) {
		if(first){
			if(board.board[y][i] == WHITE_K) return true;
			first = false;
		}
        if (board.board[y][i] == WHITE_Q || board.board[y][i] == WHITE_R)
        	return true;
    }

	first = true;
    for (int i(y + 1); i < board.nbl; ++i) {
		if(first){
			if(board.board[i][x] == WHITE_K) return true;
			first = false;
		}
        if (board.board[i][x] == WHITE_Q || board.board[i][x] == WHITE_R)
        	return true;
    }

	first = true;
    for (int i(y - 1); i >= 0; --i) {
		if(first){
			if(board.board[i][x] == WHITE_K) return true;
			first = false;
		}
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

bool GameHelper::checkWhite(int x, int y, chess_board_t const& board){

	/*diag*/

	bool first;

	first = true;
	for (int i(x - 1), j(y - 1); i >= 0 && j >= 0; --i, --j) {
		if(first){
			if(board.board[j][i] == BLACK_K) return true;
			first = false;
		}
        if (board.board[j][i] == BLACK_Q || board.board[j][i] == BLACK_B)
        	return true;
    }

	first = true;
    for (int i(x - 1), j(y + 1); i >= 0 && j < board.nbl; --i, ++j) {
		if(first){
			if(board.board[j][i] == BLACK_K) return true;
			first = false;
		}
    	if (board.board[j][i] == BLACK_Q || board.board[j][i] == BLACK_B)
        	return true;
    }

	first = true;
    for (int i(x + 1), j(y - 1); i < board.nbc && j >= 0; ++i, --j) {
		if(first){
			if(board.board[j][i] == BLACK_K) return true;
			first = false;
		}
        if (board.board[j][i] == BLACK_Q || board.board[j][i] == BLACK_B)
        	return true;
    }

	first = true;
    for (int i(x + 1), j(y + 1); i < board.nbc && j < board.nbl; ++i, ++j) {
		if(first){
			if(board.board[j][i] == BLACK_K) return true;
			first = false;
		}
        if (board.board[j][i] == BLACK_Q || board.board[j][i] == BLACK_B)
        	return true;
    }


    /*line*/
	first = true;
    for (int i(x + 1); i < board.nbc; ++i) {
		if(first){
			if(board.board[y][i] == BLACK_K) return true;
			first = false;
		}
        if (board.board[y][i] == BLACK_Q || board.board[y][i] == BLACK_R)
        	return true;
    }

	first = true;
    for (int i(x - 1); i >= 0; --i) {
		if(first){
			if(board.board[y][i] == BLACK_K) return true;
			first = false;
		}
        if (board.board[y][i] == BLACK_Q || board.board[y][i] == BLACK_R)
        	return true;
    }

	first = true;
    for (int i(y + 1); i < board.nbl; ++i) {
		if(first){
			if(board.board[i][x] == BLACK_K) return true;
			first = false;
		}
        if (board.board[i][x] == BLACK_Q || board.board[i][x] == BLACK_R)
        	return true;
    }

	first = true;
    for (int i(y - 1); i >= 0; --i) {
		if(first){
			if(board.board[i][x] == BLACK_K) return true;
			first = false;
		}
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
    if(board.board[y-1][x-1] == BLACK_P){
    	return true;
    }
    if(board.board[y-1][x+1] == BLACK_P){
    	return true;
    }

	return false;
}


std::vector<chess_move_t> GameHelper::AllPossibleMovesBlack(chess_board_t& board) {
	std::vector<chess_move_t> moves;
	
    for (auto& black: board.black_pieces) {

		if(black.piece == -1) continue;

        for (auto& piece: AllPieces::allPossibleBlack(black, board)) {
            play(piece, board);
            if (!checkBlack(board.black_pieces[0].col, board.black_pieces[0].line, board)) moves.emplace_back(piece);
            unplay(piece, board);
        }
    }

    return moves;
}

std::vector<chess_move_t> GameHelper::AllPossibleMovesWhite(chess_board_t& board) {
    std::vector<chess_move_t> moves;

    for (auto& white: board.white_pieces) {

		if(white.piece == -1) continue;

        for (auto& piece: AllPieces::allPossibleWhite(white, board)) {	
            play(piece, board);
            if (!checkWhite(board.white_pieces[0].col, board.white_pieces[0].line, board)) moves.emplace_back(piece);
            unplay(piece, board);
        }
    }

    return moves;
}

void GameHelper::play(chess_move_t const& move, chess_board_t& board) {
    board.board[move.line_i][move.col_i] = board.board[move.line_f][move.col_f];
    board.board[move.line_f][move.col_f] = EMPTY;

	//For the chess_piece_t vector
	int inTabIndex = board.boardToIndex[move.line_f][move.col_f];

	int oldInTabIndex = board.boardToIndex[move.line_i][move.col_i];

	board.boardToIndex[move.line_i][move.col_i] = inTabIndex;
    board.boardToIndex[move.line_f][move.col_f] = 0;

	if(inTabIndex < 0){
		//Black piece
		inTabIndex = (-1 * inTabIndex) - 1;

		board.black_pieces[inTabIndex].col = move.col_i;
		board.black_pieces[inTabIndex].line = move.line_i;

	}
	else{
		//White piece
		inTabIndex = inTabIndex - 1;

		board.white_pieces[inTabIndex].col = move.col_i;
		board.white_pieces[inTabIndex].line = move.line_i;

	}

	//If old piece wasn't empty
	if(oldInTabIndex != 0){
		// std::cout << "Killed\n";
		if(oldInTabIndex < 0){
			//black
			oldInTabIndex = (-1 * oldInTabIndex) - 1;

			board.black_pieces[oldInTabIndex].piece = -1;

			board.blackHole.push_back(oldInTabIndex);

		}
		else{
			//white
			oldInTabIndex = oldInTabIndex - 1;

			board.white_pieces[oldInTabIndex].piece = -1;

			board.whiteHole.push_back(oldInTabIndex);

		}

	}

}

void GameHelper::unplay(chess_move_t const& move, chess_board_t& board) {
    board.board[move.line_f][move.col_f] = board.board[move.line_i][move.col_i];
    board.board[move.line_i][move.col_i] = move.old_piece;

	//For the chess_piece_t vector
	int inTabIndex = board.boardToIndex[move.line_i][move.col_i];

	board.boardToIndex[move.line_f][move.col_f] = inTabIndex;

	//RE créer ANCIENNE PIECE
	if(move.old_piece != 12){
		// std::cout << "Old piece presente a remettre\n";
		int color = Helper::getColor(move.col_i, move.line_i, board);
		int index;

		//White
		if(color == 0){
			
			index = board.whiteHole.back();

			board.whiteHole.pop_back();

			int pieceType = Helper::doubleTypeToUniqueType(move.old_piece);

			board.white_pieces[index].piece = pieceType;
			board.white_pieces[index].col = move.col_i;
			board.white_pieces[index].line = move.line_i;

			board.boardToIndex[move.line_i][move.col_i] = index + 1;
			
		}
		//Black
		else{

			index = board.blackHole.back();

			board.blackHole.pop_back();

			int pieceType = Helper::doubleTypeToUniqueType(move.old_piece);

			board.black_pieces[index].piece = pieceType;
			board.black_pieces[index].col = move.col_i;
			board.black_pieces[index].line = move.line_i;

			board.boardToIndex[move.line_i][move.col_i] = -1 * (index + 1);

		}

	}
	else{
    	board.boardToIndex[move.line_i][move.col_i] = 0;
	}



	if(inTabIndex < 0){
		//Black piece
		inTabIndex = (-1 * inTabIndex) - 1;

		board.black_pieces[inTabIndex].col = move.col_f;
		board.black_pieces[inTabIndex].line = move.line_f;

	}
	else{
		//White piece
		inTabIndex = inTabIndex - 1;

		board.white_pieces[inTabIndex].col = move.col_f;
		board.white_pieces[inTabIndex].line = move.line_f;

	}
}