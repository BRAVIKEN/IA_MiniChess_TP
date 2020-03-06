
#include "GameHelper.hpp"


bool GameHelper::checkBlack(int x, int y, chess_board_t const& board){

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

bool GameHelper::checkWhite(int x, int y, chess_board_t const& board){

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
        switch (black.piece) {
            case PAWN:
                for (auto& piece: Pawn::allPossibleBlack(black.line, black.col, board)) {
                    play(piece, board);
                    if (!checkBlack(board.black_pieces[0].col, board.black_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case ROOK:
                for (auto& piece: Rook::allPossible(black.line, black.col, board)) {
                    play(piece, board);
                    if (!checkBlack(board.black_pieces[0].col, board.black_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case KNIGHT:
                for (auto& piece: Knight::allPossible(black.line, black.col, board)) {
                    play(piece, board);
                    if (!checkBlack(board.black_pieces[0].col, board.black_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case BISHOP:
                for (auto& piece: Bishop::allPossible(black.line, black.col, board)) {
                    play(piece, board);
                    if (!checkBlack(board.black_pieces[0].col, board.black_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case KING:
                for (auto& piece: King::allPossible(black.line, black.col, board)) {
                    play(piece, board);
                    if (!checkBlack(board.black_pieces[0].col, board.black_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case QUEEN:
                for (auto& piece: Queen::allPossible(black.line, black.col, board)) {
                    play(piece, board);
                    if (!checkBlack(board.black_pieces[0].col, board.black_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            default:
                break;
        }
    }

    return moves;
}

std::vector<chess_move_t> GameHelper::AllPossibleMovesWhite(chess_board_t& board) {
    std::vector<chess_move_t> moves;

    for (auto& white: board.white_pieces) {
        switch (white.piece) {
            case PAWN:
                for (auto& piece: Pawn::allPossibleWhite(white.line, white.col, board)) {
                    play(piece, board);
                    if (!checkWhite(board.white_pieces[0].col, board.white_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case ROOK:
                for (auto& piece: Rook::allPossible(white.line, white.col, board)) {
                    play(piece, board);
                    if (!checkWhite(board.white_pieces[0].col, board.white_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case KNIGHT:
                for (auto& piece: Knight::allPossible(white.line, white.col, board)) {
                    play(piece, board);
                    if (!checkWhite(board.white_pieces[0].col, board.white_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case BISHOP:
                for (auto& piece: Bishop::allPossible(white.line, white.col, board)) {
                    play(piece, board);
                    if (!checkWhite(board.white_pieces[0].col, board.white_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case KING:
                for (auto& piece: King::allPossible(white.line, white.col, board)) {
                    play(piece, board);
                    if (!checkWhite(board.white_pieces[0].col, board.white_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            case QUEEN:
                for (auto& piece: Queen::allPossible(white.line, white.col, board)) {
                    play(piece, board);
                    if (!checkWhite(board.white_pieces[0].col, board.white_pieces[0].line, board)) moves.emplace_back(piece);
                    unplay(piece, board);
                }
                break;

            default:
                break;
        }
    }

    return moves;
}

void GameHelper::play(chess_move_t const& piece, chess_board_t& board) {
    board.board[piece.line_i][piece.col_i] = board.board[piece.line_f][piece.col_f];
    board.board[piece.line_f][piece.col_f] = EMPTY;
}

void GameHelper::unplay(chess_move_t const& piece, chess_board_t& board) {
    board.board[piece.line_f][piece.col_f] = board.board[piece.line_i][piece.col_i];
    board.board[piece.line_i][piece.col_i] = piece.old_piece;
}