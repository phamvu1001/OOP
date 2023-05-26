#ifndef BISHOP_H
#define BISHOP_H
#include <math.h>
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
	//constructors
	Bishop(char color) : ChessPiece(color) {};

	//deconstructor
	~Bishop() {};

	//get piece type (Bishop -> B)
	char getPiece();

	//check if the move is legal
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]);

};


#endif // !BISHOP_H
