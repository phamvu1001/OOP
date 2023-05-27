#include "GameManager.h"
GameManager::GameManager() {
	this->player1 = this->player2 = NULL;
	this->cb = new ChessBoard;
	this->turn = 'W';
}
GameManager::~GameManager() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->cb->cp[i][j] != NULL) {
				delete this->cb->cp[i][j];
			}
		}
	}
	if (this->player1 != NULL) {
		delete this->player1;
	}
	if (this->player2 != NULL) {
		delete this->player2;
	}
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
	if (!this->cb->canMove(this->turn)) {
		return 1;
	}
	if (this->cb->isInCheck(this->turn) && this->cb->canMove(this->turn)==0) {
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
	int move=0;
	this->capturedChessPiece.push(this->cb->cp[desrow][descol]);

	this->cb->cp[desrow][descol] = this->cb->cp[srcrow][srccol];
	this->cb->cp[srcrow][srccol] = NULL;

	bool queenPromote=this->QueenPromotion(desrow, descol);
	if (queenPromote) { 
		move = 1; 
	}
	this->move_his.push(move * 10000 + srcrow * 1000 + srccol * 100 + desrow * 10 + descol);
}
bool GameManager::QueenPromotion(int row, int col) {
	if (row!=0 && row!=7) {
		return 0;
	}
	if (this->cb->cp[row][col]->getPiece()!='P') {
		return 0;
	}
	char color = this->cb->cp[row][col]->getColor();
	delete this->cb->cp[row][col];
	this->cb->cp[row][col] = new Queen(color);
	return 1;
}
void GameManager::Undo(stack<int> &undo_his,stack <ChessPiece*>&undo_capture) {
	if (this->move_his.size() == 0) {
		return;
	}
	this->changeTurn();

	int step = this->move_his.top();
	this->move_his.pop();
	undo_his.push(step);
	int move = step / 10000;
	int srcrow = (step / 1000) % 10, srccol = (step / 100) % 10, desrow = (step / 10) % 10, descol = step % 10;
	if (move == 0) {
		this->cb->cp[srcrow][srccol] = this->cb->cp[desrow][descol];
		this->cb->cp[desrow][descol] = this->capturedChessPiece.top();
		undo_capture.push(this->capturedChessPiece.top());
		this->capturedChessPiece.pop();
		return;
	}
	if (move == 1) {
		ChessPiece* piece = this->capturedChessPiece.top();
		this->capturedChessPiece.pop();
		delete this->cb->cp[desrow][descol];
		this->cb->cp[srcrow][srccol] = new Pawn(this->turn);
		this->cb->cp[desrow][descol] = piece;
		undo_capture.push(piece);
		return;
	}
	
}
void GameManager::Redo(stack <int>& undo_his, stack <ChessPiece*>& undo_capture) {
	if (undo_his.size() == 0) {
		return;
	}
	this->changeTurn();
	int step = undo_his.top();
	cout << undo_his.size() << undo_capture.size() << endl;
	undo_his.pop();
	undo_capture.pop();
	int srcrow = (step / 1000) % 10, srccol = (step / 100) % 10, desrow = (step / 10) % 10, descol = step % 10;
	this->Move(srcrow, srccol, desrow, descol);
}
void GameManager::displayTurn(stack <int> &undo_his, stack <ChessPiece*> &undo_capture) {
	Player* player = this->getPlayerInTurn();
	cout << player->getName() << " (" << player->getColor() << ") " << "'s turn: \n";
	int choice=0;
	do {
		cout << "1.Undo\n";
		cout << "2.Redo\n";
		cout << "3.Move\n";
		cout << "Your choice: ";
		cin >> choice;
	} while (choice > 3 || choice < 1);
	if (choice == 3) {
		while (undo_his.size() > 0) {
			undo_his.pop();
		}
		while (undo_capture.size() > 0) {
			undo_capture.pop();
		}
	}
	switch (choice) {
	case 3: {
		bool LegalMove, SelfCheckMove;
		if (this->cb->isInCheck(player->getColor())) {
			cout << "Your king is in check!!\n";
		}
		//make move
		int srccol, srcrow, descol, desrow;
		do {
			player->selectChessPieceAndDest(this->cb, srcrow, srccol,desrow,descol);
			LegalMove = this->cb->cp[srcrow][srccol]->isLegalMove(srcrow, srccol, desrow, descol, this->cb->cp);
			SelfCheckMove = this->IsSelfCheckMove(srcrow, srccol, desrow, descol);
			if (!LegalMove) {
				cout << "Not a legal move!\n";
			}
			if (SelfCheckMove) {
				cout << "Don't leave your king in check!\n";
			}
		} while (!LegalMove || SelfCheckMove);
		this->Move(srcrow, srccol, desrow, descol);
		this->changeTurn(); 
		return;
	}
	case 1: {
		this->Undo(undo_his,undo_capture);
		return;
	}
	case 2: {
		this->Redo(undo_his,undo_capture);
		return;
	}
	}
}
void GameManager::Replay() {
	stack <int>move;
	while (this->capturedChessPiece.size() > 0) {
		ChessPiece* cp = this->capturedChessPiece.top();
		this->capturedChessPiece.pop();
		if (cp) {
			delete cp;
		}
	}
	while (this->move_his.size() > 0) {
		move.push(this->move_his.top());
		this->move_his.pop();
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->cb->cp[i][j]) {
				delete this->cb->cp[i][j];
			}
		}
	}
	this->cb = new ChessBoard;
	while (move.size() > 0) {
		this->cb->Print();
		Sleep(2000);
		int step = move.top();
		move.pop();
		int srcrow = (step / 1000) % 10, srccol = (step / 100) % 10, desrow = (step / 10) % 10, descol = step % 10;
		this->Move(srcrow,srccol, desrow, descol);
		system("cls");
	}
}
void GameManager::handle() {
	stack <int> undo_his;
	stack <ChessPiece*> undo_capture;
	this->getPlayerInformation();
	system("cls");
	do {
		this->cb->Print();
		this->displayTurn(undo_his,undo_capture);
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
	cout << "The winner is "<<winner->getColor()<<": " << winner->getName() << endl;
	cout << "Replay the game: \n";
	int choice;
	cout << "1.Yes\n";
	cout << "2.No\n";
	do {
		cout << "Your choice\n";
		cin >> choice;
	} while (choice != 0 && choice != 1);
	system("cls");
	if (choice == 1) {
		this->Replay();
		this->cb->Print();
		cout << "The winner is " << winner->getColor() << ": " << winner->getName() << endl;
	}
}