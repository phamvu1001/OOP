#ifndef  CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>

using namespace std;

class Pos {
public:
	int x, y;
	Pos() {
		this->x = this->y = -1;
	}
	~Pos() {};
};

class ChessPiece
{
public:
	//Color of the piece, 1 Upper case character, Ex: "W" for White
	char Color;
	Pos pos;

public:
	//constructors
		ChessPiece();
		ChessPiece(char Color);

	//deconstructor
		~ChessPiece() {};

	//
	virtual bool IsLegalMove() = 0;
};

ChessPiece::ChessPiece()
{
	this->Color = 'W';
}

ChessPiece::ChessPiece(char Color) {
	this->Color = Color;
}

#endif // ! CHESSPIECE_H
