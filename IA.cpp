#include "IA.hpp"

chess_move_t IA::MC(chess_board_t const& board, int color, int playoutNB){
	int bestScore = 0; //best number of winned game for a position
	chess_move_t bestMove;

	if(color == WHITE){
		for(const auto &currentPiece : board.white_pieces){
			for(const auto &currentMove : AllPieces::allPossible(currentPiece,board)){ //for every move
				int currentScore = 0;

				auto tmpBoard = board;
				tmpBoard.board[currentMove.line_i][currentMove.col_i] = tmpBoard.board[currentMove.line_f][currentMove.col_f];
				tmpBoard.board[currentMove.line_f][currentMove.col_f] = EMPTY;

				for(auto i(0); i<playoutNB; ++i){
					//play a game
					for(auto j(0); j<MAX_NB_MOVES; ++j){
						
						std::vector<chess_move_t> actualMoves;
						chess_piece_t ennemyKing;

						for(const auto &k : tmpBoard.white_pieces){
							for(const auto &l : AllPieces::allPossible(k,tmpBoard)){
								actualMoves.emplace_back(l);
							}
						}

						chess_move_t choosedMove = actualMoves[rand()%actualMoves.size()];

						
						//play a turn
						tmpBoard.board[choosedMove.line_i][choosedMove.col_i] = tmpBoard.board[choosedMove.line_f][choosedMove.col_f];
						tmpBoard.board[choosedMove.line_f][choosedMove.col_f] = EMPTY;

						for(const auto &p : tmpBoard.black_pieces){

							if(p.piece == KING){
								ennemyKing = p;
								break;
							}

						}


						if(GameHelper::checkBlack(ennemyKing.col,ennemyKing.line,tmpBoard)){
							currentScore++;
							break;
						}
					}
					tmpBoard = board;
				}

				if(currentScore > bestScore){
					bestScore = currentScore;
					bestMove = currentMove;
				}

			}
		}
	}
	
	return bestMove;
}
