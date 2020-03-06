#include "IA.hpp"

#include "GameHelper.hpp"
#include <vector>



bool IA::whitePlayOneRandomMove(chess_board_t const& board){

	std::vector<chess_move_t> possibleMoves = GameHelper::AllPossibleMovesWhite(board);

	//This mean white lost
	if(possibleMoves.empty())
		return false;

	int selectedIndex = rand()%possibleMoves;

	GameHelper::play(possibleMoves[selectedIndex], board);

	return true;

}

bool IA::blackPlayOneRandomMove(chess_board_t const& board){

	std::vector<chess_move_t> possibleMoves = GameHelper::AllPossibleMovesBlack(board);

	//This mean white lost
	if(possibleMoves.empty())
		return false;

	int selectedIndex = rand()%possibleMoves;

	GameHelper::play(possibleMoves[selectedIndex], board);

	return true;

}


bool IA::randomGame(chess_board_t const& board){

	//true = white, false = black
	bool turn(true);

	while(1){

		if(turn){
			if(!whitePlayOneRandomMove(board)){
				//black won
				return false;
			}
		}
		else{
			if(!blackPlayOneRandomMove(board)){
				//white won
				return true;
			}
		}


	}



}

chess_move_t IA::MC(chess_board_t const& board, int color, int playoutNB){
	int bestScore = 0; //best number of winned game for a position
	chess_move_t bestMove;

	if(color == WHITE){
		for(const auto &currentPiece : board.white_pieces){
			for(const auto &currentMove : AllPieces::allPossibleWhite(currentPiece,board)){ //for every move
				int currentScore = 0;

				auto tmpBoard = board;
				tmpBoard.board[currentMove.line_i][currentMove.col_i] = tmpBoard.board[currentMove.line_f][currentMove.col_f];
				tmpBoard.board[currentMove.line_f][currentMove.col_f] = EMPTY;

				for(auto i(0); i<playoutNB; ++i){
					//play a game
					for(auto j(0); j<MAX_NB_MOVES; ++j){
						//tmpBoard.print_board_with_color();

						std::vector<chess_move_t> actualMoves;
						chess_piece_t ennemyKing;

						for(const auto &k : tmpBoard.white_pieces){
							for(const auto &l : AllPieces::allPossibleWhite(k,tmpBoard)){
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

						//checking if it's won
						if(GameHelper::checkBlack(ennemyKing.col,ennemyKing.line,tmpBoard)){
							currentScore++;
							break;
						}

						//Let the black player play
							actualMoves.clear();
							for(const auto &k : tmpBoard.black_pieces){
								for(const auto &l : AllPieces::allPossibleBlack(k,tmpBoard)){
									actualMoves.emplace_back(l);
								}
							}

							choosedMove = actualMoves[rand()%actualMoves.size()];

							
							//play a turn
							tmpBoard.board[choosedMove.line_i][choosedMove.col_i] = tmpBoard.board[choosedMove.line_f][choosedMove.col_f];
							tmpBoard.board[choosedMove.line_f][choosedMove.col_f] = EMPTY;


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
