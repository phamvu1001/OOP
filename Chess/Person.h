#ifndef PERSON_H
#define PERSON_H

#include "Player.h"

class Person : public Player {
public:
    Person(string name, char color);
    void selectChessPiece(ChessBoard* cb, int& srcRow, int& srcCol);
    void selectDest(ChessBoard* cb, int srcRow, int srcCol, int& destRow, int& destCol);
};

#endif
