#ifndef ROOK_HPP
#define ROOK_HPP

#include "../mymc.hpp"
#include "Helper.hpp"

//Tour
class Rook {
   public:
    //This method return all the next move possible from a Rook on x y in the board.
    static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board);
    static bool isPossible(int x, int y, int xTo, int yTo, chess_board_t const& board);
};

#endif