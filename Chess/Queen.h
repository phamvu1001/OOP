#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "ChessPiece.h"

using namespace std;

class Queen : public ChessPiece
{
public:
	Queen();
	~Queen();
	bool isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece** cb);

};

#endif // !QUEEN_H
