#include "Queen.hpp"

std::vector<chess_move_t> Queen::allPossible(int x, int y, chess_board_t const& board) {
    std::vector<chess_move_t> toReturn = Rook::allPossible(x, y, board);
    std::vector<chess_move_t> BishopMoves = Bishop::allPossible(x, y, board);

    toReturn.insert(toReturn.end(), BishopMoves.begin(), BishopMoves.end());

    return toReturn;
}

bool Queen::isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board) {
    if (Rook::isPossible(x, y, xTo, yTo, board) || Bishop::isPossible(x, y, xTo, yTo, board)) return true;
    return false;
}