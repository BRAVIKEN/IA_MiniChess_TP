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


void backPropagate(Node& tree) {
	Node* currentNode = &tree;

    while(currentNode->parent != nullptr) {

        ++currentNode->win;

        currentNode = currentNode->parent;
    }
}


Node& selectionPropa(Node& tree, chess_board_t& board){	


	++tree.total;

	if(tree.childs.empty()){

		if(tree.isEnd) return tree;

		if (tree.turn == WHITE) {
			for (chess_move_t& move : GameHelper::AllPossibleMovesWhite(board))
				tree.childs.emplace_back(move, BLACK, &tree);
		}
		if (tree.turn == BLACK) {
			for (chess_move_t& move : GameHelper::AllPossibleMovesBlack(board))
				tree.childs.emplace_back(move, WHITE, &tree);
		}
	}
	
	float max(-1.0);
	Node* best(nullptr);

	for(Node& child : tree.childs){
		
		if(child.total == 0){

			GameHelper::play(child.moveToHere, board);
			
			++child.total;

			return child;
		}
		
		float calcul = ((float)child.win/(float)child.total) + CONSTANTE * sqrt(log((float)child.parent->total)/(float)child.total); //CALCUL;

		if(calcul > max){

			max = calcul;
			best = &child;

		}


	}

	GameHelper::play(best->moveToHere, board);
	
	return selectionPropa(*best, board);

}



//White = 0, Black = 1
chess_move_t IA::MCTS(int playoutNB, int color, chess_board_t const& board) {
    
	Node tree(chess_move_t(0, 0, 0, 0, 0), color, nullptr);

	for(int nb(0); nb < playoutNB; ++nb){

		chess_board_t boardCopy(board);

		Node& selectedNode(selectionPropa(tree, boardCopy));
		

		//If we already tested the end.
		if(selectedNode.isEnd){
			if(selectedNode.isWon) backPropagate(selectedNode);
			continue;
		}

		//Check if it's an ending state...
		int aWinner = GameHelper::whoWon(boardCopy);
		if(aWinner != -1){

			selectedNode.isEnd = true;

			if(aWinner == color){
				selectedNode.isWon = true;
				backPropagate(selectedNode);
			}
			continue;
		}

		//Copy the board to not erease it
		int whoWon = randomGame(selectedNode.turn, boardCopy);


		if(whoWon == color){
			backPropagate(selectedNode);
		}

		
	}



	//Choose best and return it.
	float best(0.0);
	int bestIndex(0);

	for(size_t i(0); i < tree.childs.size(); ++i){
		
		float newValue((float)tree.childs[i].win / (float)tree.childs[i].total );

		if(newValue > best){

			best = newValue;
			bestIndex = i;

		}

	}

	return tree.childs[bestIndex].moveToHere;

}
