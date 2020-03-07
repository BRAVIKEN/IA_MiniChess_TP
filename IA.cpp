#include "IA.hpp"

#include "GameHelper.hpp"
#include <vector>

#include <chrono>
#include <thread>

#include <iostream>

bool IA::whitePlayOneRandomMove(chess_board_t& board){

	std::vector<chess_move_t> possibleMoves = GameHelper::AllPossibleMovesWhite(board);


	//This mean white lost
	if(possibleMoves.empty())
		return false;

	int selectedIndex = rand()%possibleMoves.size();


	GameHelper::play(possibleMoves[selectedIndex], board);


	return true;

}


bool IA::blackPlayOneRandomMove(chess_board_t& board){

	std::vector<chess_move_t> possibleMoves = GameHelper::AllPossibleMovesBlack(board);

	//This mean white lost
	if(possibleMoves.empty())
		return false;
	
	int selectedIndex = rand()%possibleMoves.size();

	
	GameHelper::play(possibleMoves[selectedIndex], board);


	return true;

}


int IA::randomGame(bool turn, chess_board_t& board){

	//false = white, true = black

	int depth(0);
	while(depth/2 < MAX_NB_MOVES){
		
		if(!turn){
			if(!whitePlayOneRandomMove(board)){
				//black won
				return 1;
			}
		}
		else{
			if(!blackPlayOneRandomMove(board)){
				//white won
				return 0;
			}
		}

		//board.print_board_with_color();

		if(GameHelper::isEquality(board)) return -1;
		

		turn = !turn;

		///DEBUG
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));


		++depth;

	}
	//std::cout << "overtime\n";
	return -1;


}

chess_move_t IA::random(int playoutNB, int color, chess_board_t const& board){

	chess_board_t boardCopy = board;

	if(color == WHITE){

		std::vector<chess_move_t> possibleMoves = GameHelper::AllPossibleMovesWhite(boardCopy);

		//You should never call this function if the game is done
		if(possibleMoves.empty())
			return chess_move_t(0, 0, 0, 0, 0);

	
		return possibleMoves[rand()%possibleMoves.size()];

	}
	else{
		
		std::vector<chess_move_t> possibleMoves = GameHelper::AllPossibleMovesBlack(boardCopy);

		//You should never call this function if the game is done
		if(possibleMoves.empty())
			return chess_move_t(0, 0, 0, 0, 0);

	
		return possibleMoves[rand()%possibleMoves.size()];		

	}
}