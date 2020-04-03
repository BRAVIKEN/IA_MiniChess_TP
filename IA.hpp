#ifndef IA_HPP
#define IA_HPP

#include <vector>

#include "mymc.hpp"
#include "GameHelper.hpp"
#include "PiecesSrc/AllPieces.hpp"
#include <unordered_map>

struct Hash {
    size_t operator()(const std::vector<std::vector<int>>& v) const {
        std::hash<int> h;
        size_t seed(0);

        for (std::vector<int> i : v) {
            for (int j : i) {
                seed ^= h(j) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
        }

		return seed;
    }

};
class IA {

	public:


		static bool whitePlayOneRandomMove(chess_board_t& board);
		static bool blackPlayOneRandomMove(chess_board_t& board);

		/**
		 * Play a random game.
		 * @param turn If it's false, white start. Black start otherwise.
		 * 
		 * @return 0 if white won, 1 if black won et -1 si match nul ou timeout.
		 */
		static int randomGame(bool turn, chess_board_t& board);

		static chess_move_t random(int playoutNB, int color, chess_board_t const& board);

		/*
		**Return a movement determined by the Monte Carlo algorithme.
		**It take the board of the game, and the color of the player.
		*/
		static chess_move_t MC(int playoutNB, int color, chess_board_t const& board_);

		static void getBoardsFromDepth(chess_board_t board, int depth, int maxDepth,chess_move_t move, std::vector<std::pair<chess_board_t,chess_move_t>>& allBoards, int color);


		static chess_move_t MCTS(int playoutNB, int color, chess_board_t const& board);
/*
		static std::pair<int,chess_move_t> nested_MC(int _level, int _color, int _startColor, std::pair<int,chess_move_t> _scoreAndMove, bool start, chess_board_t const& _board);

		static chess_move_t NMCS(int depth, int color, chess_board_t const& board);

		static chess_move_t anytime_NMC(int _level, int _color, int _N, chess_board_t const& _board);
*/

		static int nested_MC(int _score, int _level, int _max_level, int _player, int _color, std::unordered_map<std::vector<std::vector<int>>, std::pair<int, chess_move_t>, Hash>& _h, chess_board_t& _board);
		static chess_move_t anytime_NMC(int _max_level, int _color, chess_board_t const& _board);

	};

#endif