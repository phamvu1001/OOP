#include "ChessPiece.h"

ChessPiece::ChessPiece(char color) {
	this->color = color;
}

char ChessPiece::getColor() {
	return this->color;
}
