#ifndef CASTLE_H
#define CASTLE_H

#include "ChessPiece.h"

class Castle : public ChessPiece
{
public:
	Castle(char color) : ChessPiece(color) {}
	~Castle() {}
	char getPiece() {return 'C';}   
	bool isLegalMove(int srcRow, int srcCol, int destRow, int destCol, ChessPiece* cp[8][8]);    
};

#endif