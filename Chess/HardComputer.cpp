#include "HardComputer.h"
HardComputer::HardComputer(char color) :Player(string("Computer(Hard)"), color) {

}

void  insertNode(Node*& root, Node* add) {
	root->pNext.push_back(add);
}
Node* createGameTree(ChessBoard* cb,char color,int depth, int maxdepth) {
	bool canMove = false;
	Node* root = new Node;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cb->cp[i][j]&&cb->cp[i][j]->getColor()==color) {
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
							if (depth == maxdepth) {
								root->srcrow = i;
								root->srccol = j;
								root->desrow = k;
								root->descol = l;
								root->weight = cb->calculateWeight();
								cb->cp[i][j] = currentPiece;
								cb->cp[k][l] = dest;
								return root;
							}
							Node* add = createGameTree(cb, color2, depth+1, maxdepth);
							if (add) {
								add->srcrow = i;
								add->srccol = j;
								add->desrow = k;
								add->descol = l;
								insertNode(root, add);
							}
						}
						cb->cp[i][j] = currentPiece;
						cb->cp[k][l] = dest;
					}
				}
			}
		}
	}
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
	int min = (*root->pNext.begin())->weight;
	for (auto it = root->pNext.begin(); it < root->pNext.end(); it++) {
		if (min > (*it)->weight) {
			min = (*it)->weight;
		}
	}
	root->weight = min;
}
void GameTreeTraversal(Node* root,char color) {
	if (root->pNext.empty()) {
		return;
	}

	for (auto it = root->pNext.begin(); it < root->pNext.end(); it++) {
		GameTreeTraversal((*it), (color == 'W') ? 'B' : 'W');
	}
	Minimax(root,color);
}
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
void HardComputer::selectChessPieceAndDest(ChessBoard* cb, int& srcRow, int& srcCol, int& desrow, int& descol) {
	Node* root = createGameTree(cb, this->color,1,4);
	GameTreeTraversal(root, this->color);
	vector <Node*>select;
	for (auto it = root->pNext.begin(); it < root->pNext.end(); it++) {
		if ((*it)->weight == root->weight) {
			select.push_back(*it);
		}
	}
	srand(time(0));
	int index = rand() % select.size() + 0;
	srcRow = (*(select.begin() + index))->srcrow;
	srcCol = (*(select.begin() + index))->srccol;
	desrow = (*(select.begin() + index))->desrow;
	descol = (*(select.begin() + index))->descol;
	DeleteGameTree(root);
}