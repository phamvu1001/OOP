#include "Computer.h"
#include "ChessBoard.h"
#include <cstdlib>

Computer::Computer(string name, char color) : Player(name, color) {

}

// return: row 0->7; col: 0->7
void Computer::selectChessPiece(ChessBoard* cb, int& srcRow, int& srcCol) {
    srand((unsigned)time(0));
    bool LegalSelected = true;

    do {

            LegalSelected = true;
            //... xu ly de tra ve ket qua
            srcRow = srcRow;
            srcCol = srcCol;
            ChessPiece* currentPiece = cb->cp[srcRow][srcCol];
            // truong hop vi tri duoc chon la vi tri trong hoac la vi tri cua quan co doi thu
            if (currentPiece == 0 || (currentPiece->getColor() != this->color)) {
                LegalSelected = false;
            }
    } while (LegalSelected == false);
}

void Computer::selectDest(ChessBoard* cb, int srcRow, int srcCol, int& destRow, int& destCol) {
    srand((unsigned)time(0));
    bool inRange = true;
    // bool LegalMove = true;

    do {
            inRange = true;
            //... xu ly de tra ve ket qua 
            destRow = destRow;
            destCol = destCol;
            ChessPiece* dest = cb->cp[destRow][destCol];

    } while (inRange == false); //(inRange == false || LegalMove == false);
}
