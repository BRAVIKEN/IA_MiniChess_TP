
#include "IA.hpp"


chess_move_t IA::otherMC(int playoutNB, int color, chess_board_t const& board){

	chess_board_t boardCopy = board;


	std::vector<chess_move_t> allMove;
	int nextPlayer;

	if(color == WHITE){
		allMove = GameHelper::AllPossibleMovesWhite(boardCopy);
		nextPlayer = BLACK;
	}
	//BLACK
	else{
		allMove = GameHelper::AllPossibleMovesBlack(boardCopy);
		nextPlayer = WHITE;
	}

	int playoutPerMove = playoutNB/allMove.size();

	chess_move_t* best(nullptr);
	int bestWinValue(-1);

	for(chess_move_t& move : allMove){		

		GameHelper::play(move, boardCopy);
		
		int win(0);

		for(int i(0); i < playoutPerMove; ++i){
			
			chess_board_t currentBoard = boardCopy;
			int whoWon = IA::randomGame(nextPlayer, currentBoard);
			if(whoWon == color) ++win;

		}

		if(win > bestWinValue){
			bestWinValue = win;
			best = &move;
		}

		GameHelper::unplay(move, boardCopy);

	}

	return *best;

}