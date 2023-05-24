#ifndef PLAYER_H
#define PLAYER_H

#include "ChessBoard.h"
#include <iostream>
#include <string>
using namespace std;

class Player {
protected:
    string name;
    char color;
public:
    Player(string name, char color);
    void setName(string name);
    void setColor(char color);
    string getName();
    char getColor();
    virtual void selectChessPiece(ChessBoard* cb, int& srcRow, int& srcCol) = 0;
    virtual void selectDest(ChessBoard* cb, int srcRow, int srcCol, int& destRow, int& destCol) = 0;
};

#endif 