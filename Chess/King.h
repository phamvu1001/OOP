#ifndef _KING_H
#define _KING_H
#include <math.h>
#include "ChessPiece.h"

class King : public ChessPiece
{
public:
	//constructors
	King(char color) : ChessPiece(color) {};

	//deconstructor
	~King() {};

	//get piece type (King -> K)
	char getPiece();

	//check if the move is legal
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]);

};

#endif // !KING

