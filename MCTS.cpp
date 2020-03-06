#include <cmath>
#include <iostream>
#include "IA.hpp"


#define CONSTANTE 0.4


struct Node{

	Node(chess_move_t move, int _turn, Node* _parent = nullptr)
	: total(0), win(0), parent(_parent), moveToHere(move), turn(_turn), isEnd(false), isWon(false) {}

	int total;
	int win;

	Node* parent;

	std::vector<Node> childs;

	chess_move_t moveToHere;
	int turn;

	bool isEnd;
	bool isWon;

};

/*

Arbre 1 noeud, noeud de départ

boucle{




}


*/

void backPropagate(Node& tree) {
	Node* currentNode = &tree;

    while(currentNode->parent != nullptr) {

        ++currentNode->win;

        currentNode = currentNode->parent;
    }
}


Node& selection(Node& tree, chess_board_t& board){	

	// std::cout << "Debut selection" << std::endl;
	// std::cout << "total : " << tree.total << std::endl;

	++tree.total;

	if(tree.childs.empty()){

		if(tree.isEnd) return tree;

		if (tree.turn == WHITE) {
			for (chess_move_t& move : GameHelper::AllPossibleMovesWhite(board)) {
				// GameHelper::play(move, board);
				tree.childs.emplace_back(move, BLACK, &tree);
				// GameHelper::unplay(move, board);
			}
		}
		if (tree.turn == BLACK) {
			for (chess_move_t& move : GameHelper::AllPossibleMovesBlack(board)) {
				// GameHelper::play(move, board);
				tree.childs.emplace_back(move, WHITE, &tree);
				// GameHelper::unplay(move, board);
			}
		}
	}

	// if(tree.childs.empty()){

	// 	std::cout << "end : " << tree.isEnd << std::endl;

	// 	// std::cout << "C VIDE WTF = " << tree.turn << std::endl;
		
	// 	board.print_board_with_color();

	// 	auto vec = GameHelper::AllPossibleMovesBlack(board);

	// 	std::cout << "coup possible : " <<vec.size() << std::endl;

	// 	// for(auto e : board.black_pieces){

	// 	// 	std::cout << e.piece << " : " << e.col << " et " << e.line << std::endl;

	// 	// }



	// }
	
	// std::cout << "Fin If" << std::endl;

	
	float max(-1.0);
	Node* best(nullptr);

	// std::cout << "Debut forEach" << std::endl;

	// std::cout << "Child size : " << tree.childs.size() << std::endl;
	for(Node& child : tree.childs){
		
		if(child.total == 0){
			// std::cout << "child == 0" << std::endl;
			GameHelper::play(child.moveToHere, board);
			
			++child.total;
			// std::cout << "return child" << std::endl;

			return child;
		}
		
		// std::cout << "Calcul" << std::endl;
		//// (win/total) + CONSTANTE * sqrt(log(totalDaron)/total)
		float calcul = (child.win/child.total) + CONSTANTE * sqrt(log(child.parent->total)/child.total); //CALCUL;

		if(calcul > max){
			// std::cout << "Winner" << std::endl;
			max = calcul;
			best = &child;


		}

		//std::cout << "continue for each" << std::endl;

	}
    
	// std::cout << "Fin for" << std::endl;

	//ICI

	

	// std::cout << "play" << std::endl;
	GameHelper::play(best->moveToHere, board);
	// std::cout << "fin fonction" << std::endl;
	
	return selection(*best, board);

}

//#define WHITE 0
//#define BLACK 1
chess_move_t IA::MCTS(int playoutNB, int color, chess_board_t const& board) {
    
	int nb(0);

	Node tree(chess_move_t(0, 0, 0, 0, 0), color, nullptr);

	while(nb < playoutNB){

		// std::cout << "1" << std::endl;
		chess_board_t boardCopy(board);

		// std::cout << "2" << std::endl;
		Node& selectedNode(selection(tree, boardCopy));
		
		// std::cout << "3" << std::endl;

		//If we already tested the end.
		if(selectedNode.isEnd){
			if(selectedNode.isWon) backPropagate(selectedNode);
			continue;
		}
		// std::cout << "4" << std::endl;

		//Check if it's an ending state...
		int aWinner = GameHelper::whoWon(boardCopy);
		if(aWinner != -1){
			// std::cout << "SOMONE LOST/WON" << std::endl;
			selectedNode.isEnd = true;

			//...and if we won
			if(aWinner == color){
				// std::cout << "ITS WHITE" << std::endl;
				selectedNode.isWon = true;
				backPropagate(selectedNode);
			}
			continue;
		}
		// std::cout << "5" << std::endl;

		//Copy the board to not erease it
		int whoWon = randomGame(selectedNode.turn, boardCopy);

		// std::cout << "6" << std::endl;

		if(whoWon == color){
			backPropagate(selectedNode);
		}

		// std::cout << "7" << std::endl;

		++nb;
	}



	//Choose best and return it.
	float best(0.0);
	int bestIndex(0);

	for(int i(0); i < tree.childs.size(); ++i){
		
		float newValue(tree.childs[i].win / tree.childs[i].total );

		if(newValue > best){

			best = newValue;
			bestIndex = i;

		}

	}

	return tree.childs[bestIndex].moveToHere;

}
