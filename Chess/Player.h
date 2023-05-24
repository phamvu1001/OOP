#ifndef PLAYER_H
#define PLAYER_H

#include "ChessBoard.h"

class Player {
    string name;
    char color;
public:
    Player(string name, char color);
    void setName(string name);
    void setColor(char color);
    string getName();
    char getColor();
    virtual void selectChessPiece(ChessBoard* cb, int& row, int& col) = 0;
    virtual void selectDest(ChessBoard* cb, int& row, int& col) = 0;
};

#endif 