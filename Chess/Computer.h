#ifndef COMPUTER_H
#define COMPUTER_H
#include <vector>
#include "Player.h"
#include <Windows.h>
class Computer : public Player {
public:
    Computer(char color);
    void selectChessPieceAndDest(ChessBoard* cb, int& srcRow, int& srcCol, int& desrow, int& descol);
};

#endif