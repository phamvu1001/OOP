#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {
public:
    Computer(string name, char color);
    void selectChessPiece(ChessBoard* cb, int& srcRow, int& srcCol);
    void selectDest(ChessBoard* cb, int srcRow, int srcCol, int& destRow, int& destCol);
};

#endif
