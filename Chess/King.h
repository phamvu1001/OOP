#ifndef KING_H
#define KING_H

#include <iostream>
#include "ChessPiece.h"
using namespace std;

class King: public ChessPiece
{
public:
	King();
	~King();
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece** cb);


};

#endif // !KING

