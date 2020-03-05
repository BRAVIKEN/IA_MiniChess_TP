
#include <vector>

#include "mymc.hpp"
#include "PiecesSrc/AllPieces.hpp"


class GameHelper {

	bool checkBlack(int x, int y, chess_board_t const& board);
	
	bool checkWhite(int x, int y, chess_board_t const& board);


	///TO DO

	//Fonction qui renvoie tout les coups possible de blanc et noir
	std::vector<chess_move_t> AllPossibleMovesWhite();

	std::vector<chess_move_t> AllPossibleMovesBlack();

};