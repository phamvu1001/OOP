#include "GameManager.h"
GameManager::GameManager() {
	this->mode = 0;
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
	while (this->capturedChessPiece.size() > 0) {
		ChessPiece* cp = this->capturedChessPiece.top();
		this->capturedChessPiece.pop();
		if (cp) {
			delete cp;
		}
	}
}
void GameManager::getPlayerInformation() {
	int mode;
	int status=1;
	ifstream fi("lastgame.txt");
	if (fi) {
		fi >> status;
		fi.close();
	}
	system("cls");
	do {
		cout << "Mode: \n";
		cout << "1. Two players\n";
		cout << "2. Computer(Easy)\n";
		cout << "3. Computer(Hard)\n";
		if (status == 0)
			cout << "4. Last game\n";
		cout << "Your choice: ";
		cin >> mode;
	} while (mode < 1 || mode>4);


	switch (mode) {
	case 1: {
		string name1, name2;
		cin.ignore();
		cout << "First-player's name: ";
		getline(cin, name1, '\n');
		cout << "Second-player's name: ";
		getline(cin, name2, '\n');
		srand(time(0));
		int turn = rand() % 2 + 0;
		if (turn == 0) {
			this->player1 = new Person(name1, 'B');
			this->player2 = new Person(name2, 'W');
		}
		else {
			this->player1 = new Person(name1, 'W');
			this->player2 = new Person(name2, 'B');
		}
		this->mode = 1;
		return;
	}
	case 2: {
		string name;
		cout << "Enter your name: ";
		cin.ignore();
		getline(cin, name, '\n');
		srand(time(0));
		int turn = rand() % 2 + 0;
		if (turn == 0) {
			this->player1 = new Person(name, 'B');
			this->player2 = new Computer('W');
		}
		else {
			this->player1 = new Person(name, 'W');
			this->player2 = new Computer('B');
		}
		this->mode = 2;
		return;
	}
	case 3: {
		string name;
		cout << "Enter your name: ";
		cin.ignore();
		getline(cin, name, '\n');
		srand(time(0));
		int turn = rand() % 2 + 0;
		if (turn == 0) {
			this->player1 = new Person(name, 'B');
			this->player2 = new HardComputer('W');
		}
		else {
			this->player1 = new Person(name, 'W');
			this->player2 = new HardComputer('B');
		}
		this->mode = 3;
		return;
	}
	case 4:
	{
		this->ReadLastGame("lastGame.txt");
		return;
	}
	default: {
		return;
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
	if (this->cb->isInCheck(this->turn) && this->cb->canMove(this->turn) == 0) {
		return 1;
	}
	return 0;
}
bool GameManager::IsSelfCheckMove(int srcrow, int srccol, int desrow, int descol) {
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
	int move = 0;
	this->capturedChessPiece.push(this->cb->cp[desrow][descol]);

	this->cb->cp[desrow][descol] = this->cb->cp[srcrow][srccol];
	this->cb->cp[srcrow][srccol] = NULL;

	bool queenPromote = this->QueenPromotion(desrow, descol);
	if (queenPromote) {
		move = 1;
	}
	this->move_his.push(move * 10000 + srcrow * 1000 + srccol * 100 + desrow * 10 + descol);
}
bool GameManager::QueenPromotion(int row, int col) {
	if (row != 0 && row != 7) {
		return 0;
	}
	if (this->cb->cp[row][col]->getPiece() != 'P') {
		return 0;
	}
	char color = this->cb->cp[row][col]->getColor();
	delete this->cb->cp[row][col];
	this->cb->cp[row][col] = new Queen(color);
	return 1;
}
void GameManager::Undo(stack<int>& undo_his, stack <ChessPiece*>& undo_capture) {
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
	undo_his.pop();
	undo_capture.pop();
	int srcrow = (step / 1000) % 10, srccol = (step / 100) % 10, desrow = (step / 10) % 10, descol = step % 10;
	this->Move(srcrow, srccol, desrow, descol);
}
void GameManager::displayTurn(stack <int>& undo_his, stack <ChessPiece*>& undo_capture) {
	Player* player = this->getPlayerInTurn();
	cout << player->getName() << " (" << player->getColor() << ") " << "'s turn: \n";
	int choice = 0;
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
			ChessPiece* cp=undo_capture.top();
			undo_capture.pop();
			if(cp){
				delete cp;
			}
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
			player->selectChessPieceAndDest(this->cb, srcrow, srccol, desrow, descol);
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
		this->Undo(undo_his, undo_capture);
		return;
	}
	case 2: {
		this->Redo(undo_his, undo_capture);
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
	delete this->cb;
	this->cb = new ChessBoard;
	while (move.size() > 0) {
		this->cb->Print();
		Sleep(2000);
		int step = move.top();
		move.pop();
		int srcrow = (step / 1000) % 10, srccol = (step / 100) % 10, desrow = (step / 10) % 10, descol = step % 10;
		this->Move(srcrow, srccol, desrow, descol);
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
		this->displayTurn(undo_his, undo_capture);
		this->Save(0,"lastGame.txt");
		system("cls");
	} while (!this->IsGameOver());
	this->Save(1, "lastGame.txt");
	this->cb->Print();
	Player* winner;
	if (this->turn == this->player1->getColor()) {
		winner = this->player2;
	}
	else {
		winner = this->player1;
	}
	cout << "The winner is " << winner->getColor() << ": " << winner->getName() << endl<<endl<<endl;
	cout << "Replay the game: \n";
	int choice;
	cout << "1.Yes\n";
	cout << "2.No\n";
	do {
		cout << "Your choice\n";
		cin >> choice;
	} while (choice != 2 && choice != 1);
	system("cls");
	if (choice == 1) {
		this->Replay();
		this->cb->Print();
		cout << "The winner is " << winner->getColor() << ": " << winner->getName() << endl<<endl<<endl;
	}

}

bool GameManager::ReadLastGame( string fileName)
{
	ifstream fi(fileName);
	//check if file not exist
	if (!fi)
	{
		return 0;
	}
	//check if the last game is over
	int status;
	fi >> status;
	if (status == 1) 
		return 0;
	//delete chessboard
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->cb->cp[i][j]) {
				delete this->cb->cp[i][j];
				this->cb->cp[i][j] = NULL;
			}
		}
	}
	//get mode of the last game
	int mode;
	fi>> mode;
	this->mode = mode;
	fi >> this->turn;
	string temp;
	getline(fi, temp);
	//get 2 player information
	string play1info, play2info, play1name, play2name;
	getline(fi, play1info);
	string color;
	stringstream ss(play1info);
	getline(ss, color, '|');
	getline(ss, play1name, '|');
	ss >> play1name;
	this->player1 = new Person(play1name, color[0]);
	getline(fi, play2info);
	stringstream ss1(play2info);
	getline(ss1, color, '|');
	getline(ss1, play2name, '|');
	if (mode == 1) {
		this->player2 = new Person(play2name, color[0]);
	}
	else if (mode == 2)
	{
		this->player2 = new Computer(color[0]);
	}
	else {
		this->player2 = new HardComputer(color[0]);
	}
	//get last chessboard
	for (int i = 0; i < 8; i++)
	{
		getline(fi, temp);
		stringstream s(temp);
		string temp2;
		int j = 0;
		while (s >> temp2)
		{
			if (temp2 != "0")
			{
				char color = temp2[0];
				char piece = temp2[1];
				if (piece == 'C')
					this->cb->cp[i][j] = new Castle(color);
				else if (piece == 'N')
					this->cb->cp[i][j] = new Knight(color);
				else if (piece == 'Q')
					this->cb->cp[i][j] = new Queen(color);
				else if (piece == 'K')
					this->cb->cp[i][j] = new King(color);
				else if (piece == 'B')
					this->cb->cp[i][j] = new Bishop(color);
				else if (piece == 'P')
					this->cb->cp[i][j] = new Pawn(color);
			}
			else
			{
				this->cb->cp[i][j] = NULL;
			}
				j++;;
		}
	}
	fi.close();
	return 1;
}
bool GameManager::Save(bool status,string fileName)
{
	ofstream fo(fileName);
	if (!fo)
	{
		return 0;
	}
	if (status == 1) { 
		fo << "1";  
		return 1; 
	}
	fo << status << endl;
	fo << this->mode << endl;
	fo << this->turn << endl;
	//the first player in lastgame.txt is always a person
	if (dynamic_cast<Person*>(this->player1)) {
		fo << this->player1->getColor() << "|" << this->player1->getName() << endl;
		fo << this->player2->getColor() << "|" << this->player2->getName() << endl;
	}
	else {
		fo << this->player2->getColor() << "|" << this->player2->getName() << endl;
		fo << this->player1->getColor() << "|" << this->player1->getName() << endl;
	}
	//save chessboard
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->cb->cp[i][j] != NULL)
				fo << this->cb->cp[i][j]->getColor() << this->cb->cp[i][j]->getPiece() << " ";
			else fo << "0" << " ";
		}
		fo << endl;
	}
	fo.close();
	return 1;
}
