#include "Battle.hpp"

#include <iostream>
#include <chrono>

#include "mymc.hpp"
#include "GameHelper.hpp"


class Timer{

	public:
		Timer() : beg_(clock_::now()) {}
		void reset() { beg_ = clock_::now(); }
		double elapsed() const { 
			return std::chrono::duration_cast<second_>
				(clock_::now() - beg_).count(); }

	private:
		typedef std::chrono::high_resolution_clock clock_;
		typedef std::chrono::duration<double, std::ratio<1> > second_;
		std::chrono::time_point<clock_> beg_;

};

bool Battle::BattleChronoFirstOne(chess_move_t (*firstFunc)(int, int, chess_board_t const&), chess_move_t (*secondFunc)(int, int, chess_board_t const&), int playoutNB, int nbGame){
	
	Timer myTimer;

	double endSum(0);

	for(int i(0); i < nbGame; ++i){

		chess_board_t chess;

		chess.init_silverman_4x5();
		chess.print_board_with_color();

		std::vector<double> allTime;


		while(1){

			myTimer.reset();
			chess_move_t move = firstFunc(playoutNB, WHITE, chess);
			allTime.emplace_back(myTimer.elapsed());

			GameHelper::play(move, chess);
			chess.print_board_with_color();

			if(GameHelper::isEquality(chess)){
				std::cout << "Equality." << std::endl;
				break;
			}

			int who = GameHelper::whoWon(chess);
			if(who != -1){

				if(who == WHITE){
					std::cout << "White gagne." << std::endl;
				}
				else{
					std::cout << "Black gagne." << std::endl;
				}

				break;

			}

			chess_move_t move2 = secondFunc(playoutNB, BLACK, chess);
			GameHelper::play(move2, chess);
			chess.print_board_with_color();

			
			if(GameHelper::isEquality(chess)){
				std::cout << "Equality." << std::endl;
			}

			who = GameHelper::whoWon(chess);
			if(who != -1){

				if(who == WHITE){
					std::cout << "White gagne." << std::endl;
				}
				else{
					std::cout << "Black gagne." << std::endl;
				}

				break;

			}

		}

		double sum(0);
		for(double t : allTime){

			sum += t;

		}
		sum /= allTime.size();

		endSum += sum;

	}

	endSum /= nbGame;

	std::cout << "Temps moyen par coup sur " << nbGame << " partie(s) : " << endSum << std::endl;

	return true;

}


bool Battle::BattleTwo(chess_move_t (*firstFunc)(int, int, chess_board_t const&), chess_move_t (*secondFunc)(int, int, chess_board_t const&), int playoutNB){

	chess_board_t chess;

    chess.init_silverman_4x5();
    chess.print_board_with_color();

	while(1){

		chess_move_t move = firstFunc(playoutNB, WHITE, chess);
		GameHelper::play(move, chess);
		chess.print_board_with_color();

		if(GameHelper::isEquality(chess)){
			std::cout << "Equality." << std::endl;
			break;
		}

		int who = GameHelper::whoWon(chess);
		if(who != -1){

			if(who == WHITE){
				std::cout << "White gagne." << std::endl;
			}
			else{
				std::cout << "Black gagne." << std::endl;
			}

			break;

		}

		chess_move_t move2 = secondFunc(playoutNB, BLACK, chess);
		GameHelper::play(move2, chess);
		chess.print_board_with_color();

		
		if(GameHelper::isEquality(chess)){
			std::cout << "Equality." << std::endl;
		}

		who = GameHelper::whoWon(chess);
		if(who != -1){

			if(who == WHITE){
				std::cout << "White gagne." << std::endl;
			}
			else{
				std::cout << "Black gagne." << std::endl;
			}

			break;

		}

	}

	return true;

}