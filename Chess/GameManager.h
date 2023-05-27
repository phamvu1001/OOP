#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "ChessBoard.h"
#include <string.h>
#include <sstream>
#include "Person.h"
#include <iostream>
using namespace std;
class GameManager {
	Player* player1, *player2;
	ChessBoard* cb;
	char turn;
public:
	GameManager();
	void getPlayerInformation();
	void handle();
	Player* getPlayerInTurn();
	void changeTurn();
	bool IsGameOver();
	bool IsSelfCheckMove(int,int,int,int);
	void Move(int, int, int, int);
	bool QueenPromotion(int,int);
};

#endif
