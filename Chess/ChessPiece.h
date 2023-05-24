#ifndef  CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <ChessBoard.h>

using namespace std;

class ChessPiece
{
protected:
	//Color of the piece, 1 Upper case character, Ex: "W" for White
	char Color;

public:
	//constructors
		ChessPiece();
		ChessPiece(char Color);

	//deconstructor
		virtual ~ChessPiece() {};

	//
		virtual bool isLegalMove(int, int, int, int, ChessBoard* cb) = 0;
};

ChessPiece::ChessPiece()
{
	this->Color = 'W';
}

ChessPiece::ChessPiece(char Color) {
	this->Color = Color;
}

#endif // ! CHESSPIECE_H
