#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include "Castle.h"
#include "Bishop.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
using namespace std;

class ChessBoard
{
public:
	ChessPiece* cp[8][8];
	ChessBoard();
	~ChessBoard();
	void Print();

	bool isInCheck(char color);
	bool canMove(char color);
};
#endif // !CHESSBOARD_H
