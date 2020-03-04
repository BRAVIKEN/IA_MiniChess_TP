#ifndef IA_MINICHESS_TP_KNIGHT_HPP
#define IA_MINICHESS_TP_KNIGHT_HPP

#include <vector>
#include "mymc.h"
#include "AllPawn.hpp"

class Knight {
   public:
    static std::vector<chess_move_t> allPossible(int x, int y, chess_board_t const& board);
    static bool isPossible(int x, int y, int xK, int yK, chess_board_t const& board);
};

#endif // IA_MINICHESS_TP_KNIGHT_HPP