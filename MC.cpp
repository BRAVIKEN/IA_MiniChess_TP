#include "IA.hpp"

chess_move_t IA::MC(const chess_board_t &board, int color, int playoutNB, int startDepth) {
    int bestScore(0);  //best number of winned game for a position
    chess_move_t bestMove;
    std::vector<std::pair<chess_board_t,chess_move_t>> allBoards;

    if (color == WHITE) {
        IA::getBoardsFromDepth(board, startDepth, startDepth, chess_move_t(), allBoards, WHITE);
        for(auto &actualBoardAndMove : allBoards){
            for (const auto &currentMove : GameHelper::AllPossibleMovesWhite(actualBoardAndMove.first)) {  //for every move

                    int currentScore(0);

                    GameHelper::play(currentMove, actualBoardAndMove.first);

                    chess_board_t tmpBoard(actualBoardAndMove.first);

                    for (int i(0); i < playoutNB; ++i) {
                        //play a game
                        //play, if black player is checkmate
                        if(IA::randomGame(true,tmpBoard) == WHITE){
                            currentScore++;
                        } 

                        tmpBoard = actualBoardAndMove.first;
                    }

                    if (currentScore > bestScore) {
                        bestScore = currentScore;
                        bestMove = actualBoardAndMove.second;
                    }

                    GameHelper::unplay(currentMove, actualBoardAndMove.first);
                
            }
        }
        
    } else if(color == BLACK){
        IA::getBoardsFromDepth(board, startDepth, startDepth, chess_move_t(), allBoards, BLACK);
        for(auto &actualBoardAndMove : allBoards){
            for (const auto &currentMove : GameHelper::AllPossibleMovesBlack(actualBoardAndMove.first)) {  //for every move

                    int currentScore(0);

                    GameHelper::play(currentMove, actualBoardAndMove.first);

                    chess_board_t tmpBoard(actualBoardAndMove.first);

                    
                    for (int i(0); i < playoutNB; ++i) {
                        //play a game
                        //play, if black player is checkmate
                        if(IA::randomGame(false,tmpBoard) == BLACK){
                            currentScore++;
                        } 

                        tmpBoard = actualBoardAndMove.first;
                    }

                    if (currentScore > bestScore) {
                        bestScore = currentScore;
                        bestMove = actualBoardAndMove.second;
                    }

                    GameHelper::unplay(currentMove, actualBoardAndMove.first);
                
            }
        }
    }
    return bestMove;
}

/*
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