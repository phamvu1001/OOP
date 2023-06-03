#include "HardComputer.h"
HardComputer::HardComputer(char color) :Player(string("Computer(Hard)"), color) {

}
//create Node
void  insertNode(Node*& root, Node* add) {
	root->pNext.push_back(add);
}
//Create GameTree
Node* createGameTree(ChessBoard* cb,char color,int depth, int maxdepth) {
	bool canMove = false;
	Node* root = new Node;
	//find a ChessPiece belong to color
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cb->cp[i][j]&&cb->cp[i][j]->getColor()==color) {
				//find valid move
				for (int k = 0; k < 8; k++) {
					for (int l = 0; l < 8; l++) {
						ChessPiece* currentPiece = cb->cp[i][j];
						ChessPiece* dest = cb->cp[k][l];
						bool LegalMove = cb->cp[i][j]->isLegalMove(i, j, k, l, cb->cp);
						cb->cp[k][l] = currentPiece;
						cb->cp[i][j] = NULL;
						bool SelfCheckMove = cb->isInCheck(color);
						if (LegalMove && !SelfCheckMove) {
							canMove = true;
							char color2 = (color == 'B') ? 'W' : 'B';
							//if the root has depth=delth-1, the found move is a leaf
							if (depth == maxdepth-1) {
								Node* add = new Node;
								add->srcrow = i;
								add->srccol = j;
								add->desrow = k;
								add->descol = l;
								add->weight = cb->calculateWeight();
								insertNode(root, add);
							}
							else {
								//find the subGameTree
								Node* add = createGameTree(cb, color2, depth + 1, maxdepth);
								if (add) {
									add->srcrow = i;
									add->srccol = j;
									add->desrow = k;
									add->descol = l;
									insertNode(root, add);
								}
							}
						}
						cb->cp[i][j] = currentPiece;
						cb->cp[k][l] = dest;
					}
				}
			}
		}
	}
	//if the Root has no more valid move(has a winner) 
	if (!canMove) {
		if (color == 'W') {
			root->weight = -10000;
		}
		else {
			root->weight = 10000;
		}
	}
	return root;
}
void Minimax(Node* root, char color) {
	if (root->pNext.empty()) {
		return;
	}
	//White : MAX
	if (color == 'W') {
		int max = (*root->pNext.begin())->weight;
		for (auto it = root->pNext.begin(); it < root->pNext.end(); it++) {
			if (max < (*it)->weight) {
				max = (*it)->weight;
			}
		}
		root->weight = max;
		return;
	}
	//Black: MIN
	int min = (*root->pNext.begin())->weight;
	for (auto it = root->pNext.begin(); it < root->pNext.end(); it++) {
		if (min > (*it)->weight) {
			min = (*it)->weight;
		}
	}
	root->weight = min;
}
//display Minimax for all un-leaf Node 
void GameTreeTraversal(Node* root,char color) {
	if (root->pNext.empty()) {
		return;
	}

	for (auto it = root->pNext.begin(); it < root->pNext.end(); it++) {
		GameTreeTraversal((*it), (color == 'W') ? 'B' : 'W');
	}
	Minimax(root,color);
}
//Delete GameTree
void DeleteGameTree(Node* root) {
	if (root->pNext.size() == 0) {
		delete root;
		return;
	}
	while (!root->pNext.empty()) {
		Node* pdel =* root->pNext.begin();
		root->pNext.erase(root->pNext.begin());
		DeleteGameTree(pdel); 
	}
	delete root;
}
//Select move for hardComputer
void HardComputer::selectChessPieceAndDest(ChessBoard* cb, int& srcRow, int& srcCol, int& desrow, int& descol) {
	//create a GameTree with depth=4
	Node* root = createGameTree(cb, this->color,1,4);
	GameTreeTraversal(root, this->color);
	//select all Node has the same value with root
	vector <Node*>select;
	for (auto it = root->pNext.begin(); it < root->pNext.end(); it++) {
		if ((*it)->weight == root->weight) {
			select.push_back(*it);
		}
	}
	//get a random move between all moves found in last step
	srand(time(0));
	int index = rand() % select.size() + 0;
	srcRow = (*(select.begin() + index))->srcrow;
	srcCol = (*(select.begin() + index))->srccol;
	desrow = (*(select.begin() + index))->desrow;
	descol = (*(select.begin() + index))->descol;
	//delete GameTree
	DeleteGameTree(root);
	Sleep(1000);
}