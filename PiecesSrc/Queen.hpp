#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <vector>

#include "../mymc.hpp"
#include "Bishop.hpp"
#include "Helper.hpp"
#include "Rook.hpp"

class Queen {
   public:
    static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board);
    static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board);
};

#endif