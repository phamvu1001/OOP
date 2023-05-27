#include "GameManager.h"
GameManager::GameManager() {
	this->cb = new ChessBoard;
	this->turn = 'W';
}
void GameManager::getPlayerInformation() {
	int mode;
	do {
		cout << "Mode: \n";
		cout << "1. Two players\n";
		cout << "2. Computer(Easy)\n";
		cout << "3. Computer(Hard)\n";
		cout << "Your choice: ";
		cin >> mode;
	} while (mode < 1 || mode>3);
	switch (mode) {
	case 1: {
		string name1, name2;
		cin.ignore();
		cout << "First-player's name: ";
		getline(cin, name1, '\n');
		cout << "Second-player's name: ";
		getline(cin, name2, '\n');
		srand(time(0));
		int turn = rand()% 2+0;
		if (turn == 0) {
			this->player1 = new Person(name1, 'B');
			this->player2 = new Person(name2, 'W');
		}
		else {
			this->player1 = new Person(name1, 'W');
			this->player2 = new Person(name2, 'B');
		}
		return;
		}
	case 2: {

	}
	case 3: {

	}
	}
}
Player* GameManager::getPlayerInTurn() {
	if (this->player1->getColor() == this->turn) {
		return this->player1;
	}
	return this->player2;
}
void GameManager::changeTurn() {
	if (this->turn == 'W') {
		this->turn = 'B';
	}
	else {
		this->turn = 'W';
	}
}
bool GameManager::IsGameOver() {
	if (this->cb->isInCheck('W') && this->cb->canMove('W')==0) {
		return 1;
	}
	if (this->cb->isInCheck('B') && this->cb->canMove('B')==0) {
		return 1;
	}
	return 0;
}
bool GameManager::IsSelfCheckMove(int srcrow,int srccol,int desrow,int descol){
	ChessPiece* cp = this->cb->cp[desrow][descol];
	this->cb->cp[desrow][descol] = this->cb->cp[srcrow][srccol];
	this->cb->cp[srcrow][srccol] = NULL;
	if (this->cb->isInCheck(this->turn)) {
		this->cb->cp[srcrow][srccol] = this->cb->cp[desrow][descol];
		this->cb->cp[desrow][descol] = cp;
		return 1;
	}
	this->cb->cp[srcrow][srccol] = this->cb->cp[desrow][descol];
	this->cb->cp[desrow][descol] = cp;
	return 0;
}
void GameManager::Move(int srcrow, int srccol, int desrow, int descol) {
	this->cb->cp[desrow][descol] = this->cb->cp[srcrow][srccol];
	this->cb->cp[srcrow][srccol] = NULL;
}
void GameManager::handle() {
	this->getPlayerInformation();
	system("cls");
	do {
		this->cb->Print();
		Player* player = this->getPlayerInTurn();
		cout << player->getName()<<" ("<<player->getColor()<<") " << "'s turn: \n";
		bool LegalMove, SelfCheckMove;

		int srccol, srcrow, descol, desrow;
		do {
			player->selectChessPiece(this->cb, srcrow, srccol);
			player->selectDest(this->cb, srcrow, srccol, desrow, descol);
			LegalMove = this->cb->cp[srcrow][srccol]->isLegalMove(srcrow, srccol, desrow, descol, this->cb->cp);
			SelfCheckMove = this->IsSelfCheckMove(srcrow, srccol, desrow, descol);
			if (!LegalMove) {
				cout << "Not a legal move!\n";
			}
			if (SelfCheckMove) {
				cout << "This move make your king in check!\n";
			}
		} while (!LegalMove || SelfCheckMove);
		this->Move(srcrow, srccol, desrow, descol);
		this->changeTurn();
		system("cls");
	} while (!this->IsGameOver());
	this->cb->Print();
	Player* winner;
	if (this->turn == this->player1->getColor()) {
		winner = this->player2;
	}
	else {
		winner = this->player1;
	}
	cout << "The winner is " << winner->getName() << endl;
}