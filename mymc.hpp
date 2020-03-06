#ifndef MYMC_H
#define MYMC_H

#include <cstdio>
#include <cstdlib>

#include <vector>

#define WHITE_P 0  // pawn pion
#define BLACK_P 1
#define WHITE_R 2  // rook tour
#define BLACK_R 3
#define WHITE_N 4  // knight cavalier
#define BLACK_N 5
#define WHITE_B 6  // bishop fou
#define BLACK_B 7
#define WHITE_K 8  // king roi
#define BLACK_K 9
#define WHITE_Q 10  // queen reine
#define BLACK_Q 11
#define EMPTY 12  // empty vide

#define PAWN 0
#define ROOK 1
#define KNIGHT 2
#define BISHOP 3
#define KING 4
#define QUEEN 5

#define MAX_NB_MOVES 1000

//char *cboard = (char *)"ox.";

struct chess_piece_t {
    chess_piece_t(){}
    chess_piece_t(int _piece, int _i, int _j) : piece(_piece), line(_i), col(_j) {}

    int piece;
    int line;
    int col;
};

struct chess_move_t {
	chess_move_t() {}
    chess_move_t(int xFrom, int yFrom, int xTo, int yTo)
	: col_f(xFrom), line_f(yFrom), col_i(xTo), line_i(yTo), old_piece(12) {}

    chess_move_t(int xFrom, int yFrom, int xTo, int yTo, int oPiece)
	: col_f(xFrom), line_f(yFrom), col_i(xTo), line_i(yTo), old_piece(oPiece) {}

    int col_f;
    int line_f;
    int col_i;
    int line_i;
    int old_piece;

    void print() const {
        printf("(move x: %d y: %d TO x: %d y: %d)\n", col_f, line_f, col_i, line_i);
    }
};

// bool is_black(int _piece) {
//     if (_piece == EMPTY)
//         return false;
//     if (_piece & 1 == 1)
//         return true;
//     return false;
// }

// bool is_white(int _piece) {
//     if (_piece == EMPTY)
//         return false;
//     if (_piece & 1 == 0)
//         return true;
//     return false;
// }

#define MAX_LINES 8
#define MAX_COLS 8

struct chess_board_t {
    int nbl;
    int nbc;


    int board[MAX_LINES][MAX_COLS];

	//This will contain the index + 1 of the pieces in the white_pieces and black_pieces (black will be negative)
    int boardToIndex[MAX_LINES][MAX_COLS];

    int turn;

    // chess_piece_t white_pieces[2 * MAX_LINES];
    // int nb_white_pieces;

    /**
	 * Quelques idées sur comment utiliser ces data.
	 * Ces vecteurs représentes toutes les pieces de chaque joueurs
	 * (en plus de stoquer les pieces dans board)
	 * 
	 * Lors d'un tour de joueur, on peut lister la liste de tout les coups possible
	 * en parcourant son tableau de piece respectif (white_pieces pour blanc par exemple)
	 * 
	 * On loop dans le tableau et pour chaque piece on appelle
	 * allPossible dessus.
	 * (Note je rajoute une fonction dans allPieces qui s'occupe de faire le bon appel)
	 * 
	 */
    std::vector<chess_piece_t> white_pieces;
    std::vector<int> whiteHole;

    // chess_piece_t black_pieces[2 * MAX_LINES];
    // int nb_black_pieces;
    //int nb_moves;

    std::vector<chess_piece_t> black_pieces;
	std::vector<int> blackHole;
    
	std::vector<chess_move_t> moves;
    int moves_update_turn;

    void init_silverman_4x5();
    void add_black_piece(int _piece, int _i, int _j);
    void add_white_piece(int _piece, int _i, int _j);
    void init_pieces();

    // white in minus and black in major
    void print_board();

    // white in minus and black in major
    // white is white and black is blue
    void print_board_with_color();

    // bool BLACK_P_can_move_fwd(int _i, int _j);
    // bool BLACK_P_can_eat_left(int _i, int _j);
    // bool BLACK_P_can_eat_right(int _i, int _j);
    // bool WHITE_P_can_move_fwd(int _i, int _j);
    // bool WHITE_P_can_eat_left(int _i, int _j);
    // bool WHITE_P_can_eat_right(int _i, int _j);
};
#endif
