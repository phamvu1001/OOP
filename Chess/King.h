#ifndef KING_H
#define KING_H

#include <iostream>
#include <cstdlib>
#include "ChessPiece.h"
using namespace std;

class King: public ChessPiece
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

