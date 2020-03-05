#include "Knight.hpp"

std::vector<chess_move_t> Knight::allPossible(int x, int y, chess_board_t const& board) {
    std::vector<chess_move_t> moves;

    if (isPossible(x, y, x + 2, y + 1, board)) moves.emplace_back(x, y, x + 2, y + 1);
    if (isPossible(x, y, x + 2, y - 1, board)) moves.emplace_back(x, y, x + 2, y - 1);

    if (isPossible(x, y, x - 2, y + 1, board)) moves.emplace_back(x, y, x - 2, y + 1);
    if (isPossible(x, y, x - 2, y - 1, board)) moves.emplace_back(x, y, x - 2, y - 1);

    if (isPossible(x, y, x + 1, y + 2, board)) moves.emplace_back(x, y, x + 1, y + 2);
    if (isPossible(x, y, x - 1, y + 2, board)) moves.emplace_back(x, y, x - 1, y + 2);

    if (isPossible(x, y, x + 1, y - 2, board)) moves.emplace_back(x, y, x + 1, y - 2);
    if (isPossible(x, y, x - 1, y - 2, board)) moves.emplace_back(x, y, x - 1, y - 2);

    return moves;
}

bool Knight::isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board) {
    int diffx(x - xTo), diffy(y - yTo);

    if (xTo >= board.nbc || xTo < 0 || yTo >= board.nbl || yTo < 0) return false;
    if (board.board[xTo][yTo] != EMPTY && !Helper::colorDifference(x, y, xTo, yTo, board)) return false;
    if ((diffx == -2 || diffx == 2) && (diffy == -1 || diffy == 1)) return true;
    if ((diffx == -1 || diffx == 1) && (diffy == -2 || diffy == 2)) return true;

    return false;
}
