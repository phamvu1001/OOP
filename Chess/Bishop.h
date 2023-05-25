#ifndef BISHOP_H
#define BISHOP_H

#include <iostream> 
#include "ChessPiece.h"
using namespace std;

class Bishop: public ChessPiece
{
public:
	Bishop();
	~Bishop();
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece** cb);

};


#endif // !BISHOP_H
