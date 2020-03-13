#include "IA.hpp"

#define MAX_NMCS_IT 5

std::pair<int,chess_move_t> IA::nested_MC(int _level, int _color, int _startColor, std::pair<int,chess_move_t> _scoreAndMove, bool start, chess_board_t const& _board) {

	std::vector<chess_move_t> moves;
	int nextPlayer;
	chess_board_t board = _board;
	if(_color == WHITE){

		moves = GameHelper::AllPossibleMovesWhite(board);
	} else {

		moves = GameHelper::AllPossibleMovesBlack(board);
	}

	if(moves.size() == 0){

		return _scoreAndMove;
	}


	chess_board_t tmpBoard;

	std::pair<int,chess_move_t> min = _scoreAndMove;

	for(chess_move_t currentMovement : moves) {

		tmpBoard = board;

		GameHelper::play(currentMovement, tmpBoard);

		//std::pair<int,chess_move_t> r = std::make_pair(_scoreAndMove.first -1, _scoreAndMove.second);
		std::pair<int,chess_move_t> r = _scoreAndMove;
		if(start == 1){
			r.second = currentMovement;

		}

		if(_level == 0) {

			if(IA::randomGame(nextPlayer,tmpBoard) == _startColor)
				r.first--;
			
		} else {

			r = nested_MC( _level-1,!_color, _startColor, r, 0,tmpBoard);
		}
		if(r.first < min.first){

			min = r;
		}
	}


	return min;
}

chess_move_t IA::NMCS(int depth, int color, chess_board_t const& board){

	return IA::nested_MC(depth, color, color, std::make_pair(0,chess_move_t()), 1, board).second;
}


chess_move_t IA::anytime_NMC(int _level, int _color, chess_board_t const& _board) {

	std::pair<int,chess_move_t> best;
	best.first = 0;
	for(int i = 0; i < MAX_NMCS_IT; i++) {
		std::pair<int,chess_move_t> r = nested_MC( _level,_color,_color, best, 1,_board);
		if(r.first < best.first) best = r;
	}
	return best.second;
}