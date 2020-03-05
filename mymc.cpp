#include "mymc.hpp"

void chess_board_t::init_silverman_4x5() {
    nbl = 5;
    nbc = 4;
    for (int i = 0; i < MAX_LINES; i++)
        for (int j = 0; j < MAX_COLS; j++)
            board[i][j] = EMPTY;

    board[0][0] = BLACK_R;
    board[1][0] = BLACK_P;
    board[0][1] = BLACK_Q;
    board[1][1] = BLACK_P;
    board[0][2] = BLACK_K;
    board[1][2] = BLACK_P;
    board[0][3] = BLACK_R;
    board[1][3] = BLACK_P;
    board[4][0] = WHITE_R;
    board[3][0] = WHITE_P;
    board[4][1] = WHITE_Q;
    board[3][1] = WHITE_P;
    board[4][2] = WHITE_K;
    board[3][2] = WHITE_P;
    board[4][3] = WHITE_R;
    board[3][3] = WHITE_P;

    ///DEBUG
    board[1][1] = WHITE_B;

    init_pieces();
    //update_moves();
}

void chess_board_t::add_black_piece(int _piece, int _i, int _j) {
    black_pieces.emplace_back(_piece, _i, _j);
    // black_pieces[nb_black_pieces].piece = _piece;
    // black_pieces[nb_black_pieces].line = _i;
    // black_pieces[nb_black_pieces].col = _j;
    // nb_black_pieces++;
}

void chess_board_t::add_white_piece(int _piece, int _i, int _j) {
    white_pieces.emplace_back(_piece, _i, _j);
    // white_pieces[nb_white_pieces].piece = _piece;
    // white_pieces[nb_white_pieces].line = _i;
    // white_pieces[nb_white_pieces].col = _j;
    // nb_white_pieces++;
}

void chess_board_t::init_pieces() {
    for (int i = 0; i < nbl; i++)
        for (int j = 0; j < nbc; j++) {
            if (board[i][j] == BLACK_P)
                add_black_piece(PAWN, i, j);
            else if (board[i][j] == WHITE_P)
                add_white_piece(PAWN, i, j);
            else if (board[i][j] == BLACK_R)
                add_black_piece(ROOK, i, j);
            else if (board[i][j] == WHITE_R)
                add_white_piece(ROOK, i, j);
            else if (board[i][j] == BLACK_N)
                add_black_piece(KNIGHT, i, j);
            else if (board[i][j] == WHITE_N)
                add_white_piece(KNIGHT, i, j);
            else if (board[i][j] == BLACK_B)
                add_black_piece(BISHOP, i, j);
            else if (board[i][j] == WHITE_B)
                add_white_piece(BISHOP, i, j);
            else if (board[i][j] == BLACK_K)
                add_black_piece(KING, i, j);
            else if (board[i][j] == WHITE_K)
                add_white_piece(KING, i, j);
            else if (board[i][j] == BLACK_Q)
                add_black_piece(QUEEN, i, j);
            else if (board[i][j] == WHITE_Q)
                add_white_piece(QUEEN, i, j);
            else { /* nothing, it is just empty */
            }
        }
}

// white in minus and black in major
void chess_board_t::print_board() {
    for (int i = 0; i < nbl; i++) {
        for (int j = 0; j < nbc; j++) {
            if (board[i][j] == BLACK_P)
                printf("P");
            else if (board[i][j] == WHITE_P)
                printf("p");
            else if (board[i][j] == BLACK_R)
                printf("R");
            else if (board[i][j] == WHITE_R)
                printf("r");
            else if (board[i][j] == BLACK_N)
                printf("K");
            else if (board[i][j] == WHITE_N)
                printf("k");
            else if (board[i][j] == BLACK_B)
                printf("B");
            else if (board[i][j] == WHITE_B)
                printf("b");
            else if (board[i][j] == BLACK_K)
                printf("K");
            else if (board[i][j] == WHITE_K)
                printf("k");
            else if (board[i][j] == BLACK_Q)
                printf("Q");
            else if (board[i][j] == WHITE_Q)
                printf("q");
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

// white in minus and black in major
// white is white and black is blue
void chess_board_t::print_board_with_color() {
    for (int i = 0; i < nbl; i++) {
        for (int j = 0; j < nbc; j++) {
            if (board[i][j] == BLACK_P)
                printf("P");
            else if (board[i][j] == WHITE_P)
                printf("\x1B[34mp\x1B[39m");
            else if (board[i][j] == BLACK_R)
                printf("R");
            else if (board[i][j] == WHITE_R)
                printf("\x1B[34mr\x1B[39m");
            else if (board[i][j] == BLACK_N)
                printf("K");
            else if (board[i][j] == WHITE_N)
                printf("\x1B[34mk\x1B[39m");
            else if (board[i][j] == BLACK_B)
                printf("B");
            else if (board[i][j] == WHITE_B)
                printf("\x1B[34mb\x1B[39m");
            else if (board[i][j] == BLACK_K)
                printf("K");
            else if (board[i][j] == WHITE_K)
                printf("\x1B[34mk\x1B[39m");
            else if (board[i][j] == BLACK_Q)
                printf("Q");
            else if (board[i][j] == WHITE_Q)
                printf("\x1B[34mq\x1B[39m");
            //degub
            else if (board[i][j] == -1)
                printf("\x1B[31m#\x1B[39m");
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

// bool chess_board_t::BLACK_P_can_move_fwd(int _i, int _j) {
//     if (_i == nbl - 1)
//         return false;
//     if (board[_i + 1][_j] != EMPTY)
//         return false;
//     return true;
// }

// bool chess_board_t::BLACK_P_can_eat_left(int _i, int _j) {
//     if (_i == (nbl - 1))
//         return false;
//     if (_j == 0)
//         return false;
//     if (is_white(board[_i + 1][_j - 1]))
//         return true;
//     return false;
// }
// bool chess_board_t::BLACK_P_can_eat_right(int _i, int _j) {
//     if (_i == (nbl - 1))
//         return false;
//     if (_j == (nbc - 1))
//         return false;
//     if (is_white(board[_i + 1][_j + 1]))
//         return true;
//     return false;
// }

// bool chess_board_t::WHITE_P_can_move_fwd(int _i, int _j) {
//     if (_i == 0)
//         return false;
//     if (board[_i - 1][_j] != EMPTY)
//         return false;
//     return true;
// }

// bool chess_board_t::WHITE_P_can_eat_left(int _i, int _j) {
//     if (_i == 0)
//         return false;
//     if (_j == 0)
//         return false;
//     if (is_black(board[_i - 1][_j - 1]))
//         return true;
//     return false;
// }

// bool chess_board_t::WHITE_P_can_eat_right(int _i, int _j) {
//     if (_i == 0)
//         return false;
//     if (_j == (nbc - 1))
//         return false;
//     if (is_black(board[_i - 1][_j + 1]))
//         return true;
//     return false;
// }