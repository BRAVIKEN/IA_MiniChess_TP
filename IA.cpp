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


	int index (board.boardToIndex[possibleMoves[selectedIndex].line_f][possibleMoves[selectedIndex].col_f]);

	GameHelper::play(possibleMoves[selectedIndex], board);



	//possibleMoves[selectedIndex].print();
	return true;

}

bool IA::blackPlayOneRandomMove(chess_board_t& board){

	std::vector<chess_move_t> possibleMoves = GameHelper::AllPossibleMovesBlack(board);

	//This mean white lost
	if(possibleMoves.empty())
		return false;


	int selectedIndex = rand()%possibleMoves.size();



	int index(board.boardToIndex[possibleMoves[selectedIndex].line_f][possibleMoves[selectedIndex].col_f]);

	
	GameHelper::play(possibleMoves[selectedIndex], board);


	//possibleMoves[selectedIndex].print();
	return true;

}


bool IA::randomGame(chess_board_t& board){

	//true = white, false = black
	bool turn(true);

	int depth(0);
	while(depth/2 < MAX_NB_MOVES){
		
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
		
		turn = !turn;

		///DEBUG
		//board.print_board_with_color();
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));

		++depth;

	}



}
