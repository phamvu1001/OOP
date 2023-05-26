#ifndef _QUEEN_H
#define _QUEEN_H

#include <math.h>
#include "ChessPiece.h"

class Queen : public ChessPiece
{
public:
	//constructors
	Queen(char color) : ChessPiece(color) {};

	//deconstructor
	~Queen() {};

	//get piece type (Queen -> Q)
	char getPiece();

	//check if the move is legal
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]);

};

#endif // !QUEEN_H
