#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <vector>

#include "../mymc.hpp"
#include "Helper.hpp"

class Bishop {
   public:
    static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board);
    static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board);
};

#endif