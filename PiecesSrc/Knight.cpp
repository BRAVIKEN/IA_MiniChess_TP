#include "Knight.hpp"

std::vector<chess_move_t> Knight::allPossible(int x, int y, chess_board_t const& board) {
    std::vector<chess_move_t> moves;

    if (x + 2 < board.nbc) {
        if (y + 1 < board.nbl && Helper::colorDifference(x, y, x + 2, y + 1, board)) moves.emplace_back(x, y, x + 2, y + 1, board.board[y+1][x+2]);
        if (y - 1 >= 0 && Helper::colorDifference(x, y, x + 2, y - 1, board)) moves.emplace_back(x, y, x + 2, y - 1, board.board[y-1][x+2]);
    }

    if (x - 2 >= 0) {
        if (y + 1 < board.nbl && Helper::colorDifference(x, y, x - 2, y + 1, board)) moves.emplace_back(x, y, x - 2, y + 1, board.board[y+1][x-2]);
        if (y - 1 >= 0 && Helper::colorDifference(x, y, x - 2, y - 1, board)) moves.emplace_back(x, y, x - 2, y - 1, board.board[y-1][x-2]);
    }

    if (y + 2 < board.nbl) {
        if (x + 1 < board.nbc && Helper::colorDifference(x, y, x + 1, y + 2, board)) moves.emplace_back(x, y, x + 1, y + 2, board.board[y+2][x+1]);
        if (x - 1 >= 0 && Helper::colorDifference(x, y, x - 1, y + 2, board)) moves.emplace_back(x, y, x - 1, y + 2, board.board[y+2][x-1]);
    }

    if (y - 2 >= 0) {
        if (x + 1 < board.nbc && Helper::colorDifference(x, y, x + 1, y - 2, board)) moves.emplace_back(x, y, x + 1, y - 2, board.board[y-2][x+1]);
        if (x - 1 >= 0 && Helper::colorDifference(x, y, x - 1, y - 2, board)) moves.emplace_back(x, y, x - 1, y - 2, board.board[y-2][x-1]);
    }

    return moves;
}

bool Knight::isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board) {
    int diffx(x - xTo), diffy(y - yTo);

    if (xTo >= board.nbc || xTo < 0 || yTo >= board.nbl || yTo < 0) return false;
    if (!Helper::colorDifference(x, y, xTo, yTo, board)) return false;
    if ((diffx == -2 || diffx == 2) && (diffy == -1 || diffy == 1)) return true;
    if ((diffx == -1 || diffx == 1) && (diffy == -2 || diffy == 2)) return true;

    return false;
}
