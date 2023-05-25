#ifndef BISHOP_H
#define BISHOP_H

#include <iostream> 
#include <cstdlib>
#include "ChessPiece.h"
using namespace std;

class Bishop: public ChessPiece
{
public:
	//constructors
	Bishop() {};
	Bishop(char color) : ChessPiece(color) {};

	//deconstructor
	~Bishop() {};

	//check if the move is legal
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]);

};


#endif // !BISHOP_H
