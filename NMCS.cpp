#include "IA.hpp"

#define MAX_NMCS_IT 5
/*
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

	std::pair<int,chess_move_t> min(_scoreAndMove);

	for(chess_move_t currentMovement : moves) {

		tmpBoard = board;

		GameHelper::play(currentMovement, tmpBoard);

		std::pair<int,chess_move_t> r = std::make_pair(_scoreAndMove.first -1, _scoreAndMove.second);
		std::pair<int,chess_move_t> r(min);
		r.first++;
		if(start == 1){
			r.second = currentMovement;

		}

		if(_level == 0) {

			if(IA::randomGame(!_color, tmpBoard) == _startColor)
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


chess_move_t IA::anytime_NMC(int _level, int _color, int _N, chess_board_t const& _board) {

	std::pair<int,chess_move_t> best;
	best.first = 0;
	for(int i = 0; i < _N; i++) {
		std::pair<int,chess_move_t> r = nested_MC( _level,_color,_color, best, 1,_board);
		if(r.first < best.first) best = r;
	}
	return best.second;
}
*/
#include <iostream>
chess_move_t IA::anytime_NMC(int _max_level, int _color, chess_board_t const& _board) {
    std::unordered_map<std::vector<std::vector<int>>, std::pair<int, chess_move_t>, Hash> h;
    std::vector<chess_move_t> moves;
    chess_board_t board(_board);
    chess_move_t best;
    int max(0);

    if (_color == WHITE) {
        moves = GameHelper::AllPossibleMovesWhite(board);
    } else {
        moves = GameHelper::AllPossibleMovesBlack(board);
    }

    // while (true) {
    for (chess_move_t& move : moves) {
        chess_board_t tmp(board);

        GameHelper::play(move, tmp);
        nested_MC(0, -1, _max_level, _color, _color, h, tmp);

        auto h_itr(h.find(tmp.board));
        if (h_itr != h.end()) {
            if (h_itr->second.first > max) {
                max = h_itr->second.first;
                best = h_itr->second.second;
            }
        }
    }
    // }

    return best;
}

int IA::nested_MC(int _score, int _level, int _max_level, int _player, int _color, std::unordered_map<std::vector<std::vector<int>>, std::pair<int, chess_move_t>, Hash>& _h, chess_board_t& _board) {
    std::vector<chess_move_t> moves;
    chess_board_t board(_board);
    chess_move_t best;
    int max(0), v(0);

    if (_player == WHITE) {
        moves = GameHelper::AllPossibleMovesWhite(board);
    } else {
        moves = GameHelper::AllPossibleMovesBlack(board);
    }

    if (moves.empty()) {
        if (_level == _max_level) {
            if (_h.find(board.board) == _h.end()) {
                _h[board.board] = std::make_pair(_score, chess_move_t());
            }
        }

        return _score;
    }

    if (_level != _max_level) {
        if (_level == 0) {
            int w(IA::randomGame(_player, board));
            if (w == _color)
                return _score++;
            else
                return _score--;
        }

        for (chess_move_t& move : moves) {
            chess_board_t tmp(board);

            GameHelper::play(move, tmp);
            int w = GameHelper::whoWon(board);
            if (w == _color)
                _score++;
            else
                _score--;

            v = nested_MC(_score, _level - 1, _max_level, !_player, _color, _h, tmp);

            if (v > max) {
                max = v;
            }
        }

        return max;
    }
	
    for (chess_move_t& move : moves) {
        chess_board_t tmp(board);
        int score = _score;

        GameHelper::play(move, tmp);

        int w = GameHelper::whoWon(board);
        if (w == _color)
            score++;
        else
            score--;

        v = nested_MC(score, _level - 1, _max_level, !_player, _color, _h, tmp);

        if (v > max) {
            max = v;
            best = move;
        }
    }

    auto h = _h.find(board.board);
    if (h == _h.end()) {
        _h[board.board] = std::make_pair(max, best);
    } else {
        int a(h->second.first);
        chess_move_t b(h->second.second);

        if (max > a) {
            _h[board.board].first = max;
            _h[board.board].second = best;
        } else {
            best = b;
        }
    }

    GameHelper::play(best, board);

    int w = GameHelper::whoWon(board);
    if (w == _color)
        _score++;
    else
        _score--;

    return nested_MC(_score, _level, _max_level, !_player, _color, _h, board);
}