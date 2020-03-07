#include "IA.hpp"


chess_move_t IA::MC(int playoutNB, int color, chess_board_t const& board_){
    chess_board_t board(board_);
    int bestScore(0);
    chess_move_t* bestMove(nullptr);

    std::vector<chess_move_t> allMove;
    int nextPlayer;

    if(color == WHITE){
        allMove = GameHelper::AllPossibleMovesWhite(board);
        nextPlayer = BLACK;
    } else {
        allMove = GameHelper::AllPossibleMovesBlack(board);
        nextPlayer = WHITE;
    }

    int finalPlayoutNumber = playoutNB/allMove.size();

    for (chess_move_t &currentMove : allMove) {
        int currentScore(0);

        GameHelper::play(currentMove, board);


        for (int i(0); i < finalPlayoutNumber; ++i) {
        	
			chess_board_t tmpBoard(board);

            if(IA::randomGame(nextPlayer,tmpBoard) == WHITE){
                currentScore++;
            }

        }

        if (currentScore > bestScore) {
            bestScore = currentScore;
            bestMove = &currentMove;
        }

        GameHelper::unplay(currentMove, board);
    }

    return (*bestMove);
}


/*
** BUGGY!!!
** CARE, MUST USE THIS FUCTION WITH ODD NUMBER, ELSE IT WILL CRASH
*/
void IA::getBoardsFromDepth(chess_board_t board, int depth, int maxDepth,chess_move_t move, std::vector<std::pair<chess_board_t,chess_move_t>>& allBoards, int color){
    if(depth == 0){
        allBoards.emplace_back(board,move);
        return;
    }
    if(color == WHITE){

        if((maxDepth)%2 == depth%2){
            for (const auto &currentMove : GameHelper::AllPossibleMovesWhite(board)){
                GameHelper::play(currentMove, board);
                if(depth == maxDepth){
                    getBoardsFromDepth(board, depth-1, maxDepth, currentMove, allBoards, WHITE);
                } else {
                    getBoardsFromDepth(board, depth-1, maxDepth, move, allBoards, WHITE);
                }
                GameHelper::unplay(currentMove, board);
            }
        } else {
            for (const auto &currentMove : GameHelper::AllPossibleMovesWhite(board)){
                GameHelper::play(currentMove, board);
                getBoardsFromDepth(board, depth-1, maxDepth, move, allBoards, BLACK);
                GameHelper::unplay(currentMove, board);
            }
        }
    } else {
        if((maxDepth)%2 == depth%2){
            for (const auto &currentMove : GameHelper::AllPossibleMovesBlack(board)){
                GameHelper::play(currentMove, board);
                if(depth == maxDepth){
                    getBoardsFromDepth(board, depth-1, maxDepth, currentMove, allBoards, BLACK);
                } else {
                    getBoardsFromDepth(board, depth-1, maxDepth, move, allBoards, BLACK);
                }
                GameHelper::unplay(currentMove, board);
            }
        } else {
            for (const auto &currentMove : GameHelper::AllPossibleMovesBlack(board)){
                GameHelper::play(currentMove, board);
                getBoardsFromDepth(board, depth-1, maxDepth, move, allBoards, WHITE);
                GameHelper::unplay(currentMove, board);
            }
        }
    }
}