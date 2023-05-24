#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <ChessBoard.h>
#include <iostream>

class ChessPiece
{
public:
    char color;
    ChessPiece(char color) : color(color) {}
    virtual ~ChessPiece() {}
    char getColor() {return this->color;}
    virtual bool isLegalMove(int, int, int, int, ChessBoard* cb) = 0;
};

#endif