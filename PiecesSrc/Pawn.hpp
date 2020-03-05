#ifndef PAWN_HPP
#define PAWN_HPP

#include <vector>

#include "../mymc.hpp"
#include "Helper.hpp"

class Pawn {
   public:
    static std::vector<chess_move_t> allPossibleWhite(int x, int y, chess_board_t const& board);
    static std::vector<chess_move_t> allPossibleBlack(int x, int y, chess_board_t const& board);
    static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board);
    static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board);
};

#endif