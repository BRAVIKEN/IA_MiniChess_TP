#include "AllPieces.hpp"

std::vector<chess_move_t> AllPieces::allPossible(chess_piece_t const& piece, chess_board_t const& board) {
    switch (piece.piece) {
        //White Pawn
        case 0:
            return Pawn::allPossibleWhite(piece.col, piece.line, board);

        //Black Pawn
        case 1:
            return Pawn::allPossibleBlack(piece.col, piece.line, board);

        //Rook
        case 2:
        case 3:
            return Rook::allPossible(piece.col, piece.line, board);

        //Knight
        case 4:
        case 5:
            return Knight::allPossible(piece.col, piece.line, board);

        //Bishop
        case 6:
        case 7:
            return Bishop::allPossible(piece.col, piece.line, board);

        //King
        case 8:
        case 9:
            return King::allPossible(piece.col, piece.line, board);

        //Queen
        case 10:
        case 11:
            return Queen::allPossible(piece.col, piece.line, board);

        /*
			This mean the value is either incorrect or it's an empty slot (12),
			and you should not call allPossible on an empty slot.
		*/
        default:
            return std::vector<chess_move_t>();
    }
}