#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "ChessPiece.h"

using namespace std;

class Queen : public ChessPiece
{
public:
	//constructors
	Queen() {};
	Queen(char color) : ChessPiece(color) {};

	//deconstructor
	~Queen() {};

	//check if the move is legal
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]);

};

#endif // !QUEEN_H
