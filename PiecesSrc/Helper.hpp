#ifndef HELPER_HPP
#define HELPER_HPP

#include <vector>

#include "../mymc.hpp"
#include "AllPieces.hpp"

#define WHITE 0
#define BLACK 1

class Helper {
   public:
    //Return 0 for White, 1 for Black or -1 for empty.
    static int getColor(int x, int y, chess_board_t const& board);

    /**
	 * Verify if color are different.
	 * Note : Empty is considered as a third color.
	 * (So empty with any color will return true)
	 * 
	 * @return True if they are from different color, false otherwise.
	 */
    static bool colorDifference(int x1, int y1, int x2, int y2, chess_board_t const& board);

	std::vector<chess_piece_t> getPiecePos(chess_board_t const& board, int piece);

	bool checkBlack(int x, int y, chess_board_t const& board);
	bool checkWhite(int x, int y, chess_board_t const& board);

};

#endif