#include "Pawn.hpp"

std::vector<chess_move_t> Pawn::allPossibleWhite(int x, int y, chess_board_t const& board) {
    std::vector<chess_move_t> toReturn;

    if (y != 0) {
        //forward
        if (board.board[y - 1][x] == EMPTY)
            toReturn.emplace_back(x, y, x, y - 1);

        //eat left
        if (x != 0 && Helper::getColor(x - 1, y - 1, board) == BLACK)
            toReturn.emplace_back(x, y, x - 1, y - 1), board.board[y-1][x-1];

        //eat right
        if (x != (board.nbc - 1) && Helper::getColor(x + 1, y - 1, board) == BLACK)
            toReturn.emplace_back(x, y, x + 1, y - 1, board.board[y-1][x+1]);
    }

    return toReturn;
}

std::vector<chess_move_t> Pawn::allPossibleBlack(int x, int y, chess_board_t const& board) {
    std::vector<chess_move_t> toReturn;

    if (y != board.nbl - 1) {
        //forward
        if (board.board[y + 1][x] == EMPTY)
            toReturn.emplace_back(x, y, x, y + 1);

        //eat left
        if (x != 0 && Helper::getColor(x - 1, y + 1, board) == WHITE)
            toReturn.emplace_back(x, y, x - 1, y + 1, board.board[y+1][x-1]);

        //eat right
        if (x != (board.nbc - 1) && Helper::getColor(x + 1, y + 1, board) == WHITE)
            toReturn.emplace_back(x, y, x + 1, y + 1, board.board[y+1][x+1]);
    }

    return toReturn;
}

std::vector<chess_move_t> Pawn::allPossible(int x, int y, chess_board_t const& board) {
    if (Helper::getColor(x, y, board) == BLACK) {  //if blak
        return allPossibleBlack(x, y, board);
    } else {  //it's white
        return allPossibleWhite(x, y, board);
    }
}

bool Pawn::isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board) {
}