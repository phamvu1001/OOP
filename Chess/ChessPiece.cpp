#include "ChessPiece.h"

ChessPiece::ChessPiece()
{
	this->color = 'W';
}

ChessPiece::ChessPiece(char color) {
	this->color = color;
}

char ChessPiece::getColor() {
    return this->color;
}