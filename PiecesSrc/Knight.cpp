#include "Knight.hpp"

std::vector<chess_move_t> Knight::allPossible(int x, int y, chess_board_t const& board) {
    std::vector<chess_move_t> moves;
    int mx(x), my(y);
    
    if (x + 2 <= board.nbc){
        mx = x + 2;
        
        my = y + 1;
        if (my <= board.nbl && board.board[my][mx] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }

        my = y - 1;
        if (my >= board.nbl && board.board[my][mx] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }
    }

    if (x - 2 >= 0) {
        mx = x - 2;

        my = y + 1;
        if (my <= board.nbl && board.board[my][mx] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }

        my = y - 1;
        if (my >= board.nbl && board.board[my][mx] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }
    }

    if (y + 2 <= board.nbl) {
        my = y + 2;

        mx = x + 1;
        if (mx <= board.nbc && board.board[mx][my] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }

        mx = x - 1;
        if (mx >= 0 && board.board[mx][my] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }
    }

    if (y - 2 >= 0) {
        my = y - 2;

        mx = x + 1;
        if (mx <= board.nbc && board.board[mx][my] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }

        mx = x - 1;
        if (mx >= 0 && board.board[mx][my] != EMPTY) {
            if(Helper::colorDifference(x, y, mx, my, board)) {
                moves.emplace_back(x, y, mx, my);
            }
        } else {
            moves.emplace_back(x, y, mx, my);
        }
    }

    return moves;
}

bool Knight::isPossible(int x, int y, int xK, int yK, chess_board_t const& board) {
    
}
