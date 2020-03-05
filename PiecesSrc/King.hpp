#ifndef KING_HPP
#define KING_HPP

#include "../mymc.hpp"
#include "Helper.hpp"

#include <vector>

class King {
   public:
    static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board);
};

#endif