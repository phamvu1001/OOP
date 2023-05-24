#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <ChessBoard.h>
#include <iostream>

class ChessPiece
{
protected:
    char color;
public:
    char color;
    ChessPiece(char color);
    virtual ~ChessPiece() {}
    char getColor() {return this->color;}
    virtual bool isLegalMove(int, int, int, int, ChessBoard* cb) = 0;
};

#endif
