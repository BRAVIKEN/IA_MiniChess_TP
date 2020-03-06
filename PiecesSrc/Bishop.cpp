#include "Bishop.hpp"

std::vector<chess_move_t> Bishop::allPossible(int x, int y, chess_board_t const& board) {
    std::vector<chess_move_t> toReturn;

    //down left side
    for (int i(x - 1), j(y - 1); i >= 0 && j >= 0; --i, --j) {
        if (board.board[j][i] != EMPTY) {
            if (Helper::colorDifference(x, y, i, j, board)) {
                toReturn.emplace_back(x, y, i, j, board.board[j][i]);
            }

            break;
        }

        toReturn.emplace_back(x, y, i, j);
    }

    //up left side
    for (int i(x - 1), j(y + 1); i >= 0 && j < board.nbl; --i, ++j) {
        if (board.board[j][i] != EMPTY) {
            if (Helper::colorDifference(x, y, i, j, board)) {
                toReturn.emplace_back(x, y, i, j, board.board[j][i]);
            }

            break;
        }

        toReturn.emplace_back(x, y, i, j);
    }

    //down right side
    for (int i(x + 1), j(y - 1); i < board.nbc && j >= 0; ++i, --j) {
        if (board.board[j][i] != EMPTY) {
            if (Helper::colorDifference(x, y, i, j, board)) {
                toReturn.emplace_back(x, y, i, j, board.board[j][i]);
            }

            break;
        }

        toReturn.emplace_back(x, y, i, j);
    }

    //up right side
    for (int i(x + 1), j(y + 1); i < board.nbc && j < board.nbl; ++i, ++j) {
        if (board.board[j][i] != EMPTY) {
            if (Helper::colorDifference(x, y, i, j, board)) {
                toReturn.emplace_back(x, y, i, j, board.board[j][i]);
            }

            break;
        }

        toReturn.emplace_back(x, y, i, j);
    }

    return toReturn;
}

bool Bishop::isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board) {
    int stepx(xTo < x ? -1 : 1), stepy(yTo < y ? -1 : 1);

    if (x == xTo || y == yTo) return false;
    if (xTo >= board.nbc || xTo < 0 || yTo >= board.nbl || yTo < 0) return false;
    if (!Helper::colorDifference(x, y, xTo, yTo, board)) return false;

    for (int i(x), j(y); i != xTo && j != yTo; i += stepx, j += stepy) {
        if (board.board[j][i] != EMPTY) {
            return false;
        }
    }

    return true;
}