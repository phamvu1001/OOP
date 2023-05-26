#include "Knight.h"


char Knight::getPiece() {
    return 'N';
}

bool Knight::isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]) {

    //Kiểm tra: Bước đi có hợp lệ với luật của quân cờ không?
    int d_x = abs(cur_x - des_x);
    int d_y = abs(cur_y - des_y);
    //
    if ((d_x + d_y) != 3) return false;
    else {
        if (d_x == 3 || d_y == 3) return false;
    }

    //Kiểm tra: Tại đích đến có quân cờ nào cùng màu không?
    ChessPiece* dest = cp[des_x][des_y];
    if (dest->getColor() == this->getColor()) {
        return false;
    }
    dest = nullptr;
    return true;
}
