#include "King.h"


char King::getPiece() {
    return 'K';
}

bool King::isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]) {
    //Kiểm tra: Bước đi có hợp lệ với luật của quân cờ không?
    int d_x = des_x - cur_x;
    int d_y = des_y - cur_y;
    if (d_x == 0 && d_y == 0) return false;
    if (abs(d_x) > 1 || abs(d_y) > 1)return false; ;

    //Kiểm tra: Tại đích đến có quân cờ nào cùng màu không?
    ChessPiece* dest = cp[des_x][des_y];
    if (dest->getColor() == this->getColor()) {
        return false;
    }

    return true;
}
