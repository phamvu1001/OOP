#ifndef _KNIGHT_H
#define _KNIGHT_H
#include <math.h>
#include "ChessPiece.h"

class  Knight : public ChessPiece
{
public:
	//constructors
	Knight(char color) : ChessPiece(color) {};

	//deconstructor
	~Knight() {};

	//get piece type (Knight -> k)
	char getPiece();

	//check if the move is legal
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]);

};


#endif 



