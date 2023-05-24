#ifndef  CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>

using namespace std;

class ChessPiece
{
protected:
	//Color of the piece, 1 Upper case character, Ex: "W" for White
	char color;

public:
	//constructors
		ChessPiece();
		ChessPiece(char Color);

	//deconstructor
		virtual ~ChessPiece() {};
    //getter
        char getColor();

	//
		virtual bool isLegalMove(int, int, int, int, ChessPiece* cp[8][8]) = 0;
};

ChessPiece::ChessPiece()
{
	this->color = 'W';
}

ChessPiece::ChessPiece(char color) {
	this->color = color;
}

char ChessPiece::getColor() {
    return this->color;
}

#endif // ! CHESSPIECE_H