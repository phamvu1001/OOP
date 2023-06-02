#ifndef _PAWN_H
#define _PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece
{
public:
	Pawn(char color) : ChessPiece(color) {}
	~Pawn() {}
	virtual char getPiece() { return 'P'; }
	bool isLegalMove(int srcRow, int srcCol, int destRow, int destCol, ChessPiece* cp[8][8]);
	int getValue();
};

#endif
