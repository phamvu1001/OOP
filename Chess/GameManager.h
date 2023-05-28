#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "ChessBoard.h"
#include <string.h>
#include <sstream>
#include <stack>
#include <fstream>
#include "Person.h"
#include <iostream>
#include <Windows.h>
using namespace std;
class GameManager {
	Player* player1, * player2;
	ChessBoard* cb;
	char turn;
	stack <int> move_his;
	stack<ChessPiece*> capturedChessPiece;
public:
	GameManager();
	~GameManager();
	void getPlayerInformation();
	void handle();
	Player* getPlayerInTurn();
	void changeTurn();
	bool IsGameOver();
	bool IsSelfCheckMove(int, int, int, int);
	void Move(int, int, int, int);
	bool QueenPromotion(int, int);
	void Undo(stack<int>& undo_his, stack<ChessPiece*>& undo_capture);
	void Redo(stack <int>& undo_his, stack <ChessPiece*>& undo_capture);
	void displayTurn(stack <int>& undo_his, stack <ChessPiece*>& undo_capture);
	void Replay();

	// lưu và đọc game trước 
	void ReadLastGame(bool& status, int& mode, string fileName);
	void Save(bool status, int mode, string fileName);
};

#endif