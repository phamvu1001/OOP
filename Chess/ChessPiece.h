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
	ChessPiece(char Color);
	//deconstructor
	virtual ~ChessPiece() {};
	//getter
	char getColor();
	virtual char getPiece() = 0;
	// logic check
	virtual bool isLegalMove(int, int, int, int, ChessPiece* cp[8][8]) = 0;
	virtual int getValue() = 0;
};

#endif // ! CHESSPIECE_H
