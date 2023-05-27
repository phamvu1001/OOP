#include "Person.h"
#include "ChessBoard.h"

Person::Person(string name, char color) : Player(name, color) {

}

// return: row 0->7; col: 0->7
void Person::selectChessPieceAndDest(ChessBoard* cb, int &srcRow, int &srcCol, int& destRow, int& destCol) {
    string startMove;
    int square_num;
    bool LegalSelected = true;

    do {
        cout << "Select Chess Piece(A1 -> H8): ";
        cin >> startMove;
        square_num = 8 * ((int)startMove[1] - 49) + (int)startMove[0] - 64; //A1 = 1, B2 = 10, H8 = 64
        // truong hop vi tri chon nam ngoai ban co
        if (startMove.length() != 2 || square_num < 1 || square_num > 64) {
            cout << "Invalid Chess Piece!" << endl;
            LegalSelected = false;
        }
        else {
            LegalSelected = true;
            //... xu ly de tra ve ket qua
            srcRow = (int)startMove[1] - 49; // 1-8 <=> 0-7
            srcCol = (int)startMove[0] - 65; // A-H <=> 0-7
            ChessPiece* currentPiece = cb->cp[srcRow][srcCol];
            // truong hop vi tri duoc chon la vi tri trong hoac la vi tri cua quan co doi thu
            if (currentPiece == 0 || (currentPiece->getColor() != this->color)) {
                cout << "Invalid Chess Piece!" << endl;
                LegalSelected = false;
            }
        }
    } while (LegalSelected == false);

    string endMove;
    bool inRange = true;
    // bool LegalMove = true;

    do {
        cout << "Move to(A1->H8): ";
        cin >> endMove;
        square_num = 8 * ((int)endMove[1] - 49) + (int)endMove[0] - 64; //A1 = 1, B2 = 10, H8 = 64
        // truong hop vi tri chon nam ngoai ban co
        if (endMove.length() != 2 || square_num < 1 || square_num > 64) {
            cout << "Invalid Move!" << endl;
            inRange = false;
        }
        else {
            inRange = true;
            //... xu ly de tra ve ket qua 
            destRow = (int)endMove[1] - 49; // 1-8 <=> 0-7
            destCol = (int)endMove[0] - 65; // A-H <=> 0-7
            ChessPiece* dest = cb->cp[destRow][destCol];
        }
    } while (inRange == false); //(inRange == false || LegalMove == false);
}
