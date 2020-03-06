#include <cmath>
#include <iostream>
#include "IA.hpp"

chess_move_t selection(chess_board_t& board, int playout, int color) {
    int nb_won(0), p;
    double stat(0), max(0);
    bool winner;
    chess_board_t tmpboard(board);
    chess_move_t best;

    for (auto& piece : GameHelper::AllPossibleMovesBlack(board)) {
        for (p = 0; p < playout; ++p) {
            if (IA::randomGame(color, tmpboard) == color) nb_won++;
        }
        stat = (nb_won / p) + 0.4 * sqrt(log(playout) / p);
        if (stat > max) {
            max = stat;
            best = piece;
        }
    }

    return best;
}

chess_move_t IA::MCTS(chess_board_t& board, int playoutNB, int color) {
    chess_move_t best, s;

    // for (auto& piece : GameHelper::AllPossibleMovesBlack(board)) {
        s = selection(board, playoutNB, color);
        GameHelper::play(s, board);
    // }
}
