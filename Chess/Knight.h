#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "ChessPiece.h"
using namespace std;

class  Knight: public ChessPiece
{
public:
	 Knight();
	~ Knight();
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece** cb);

};


#endif 



