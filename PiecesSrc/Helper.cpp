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