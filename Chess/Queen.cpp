﻿#include "Queen.h"

char Queen::getPiece() {
    return 'Q';
}



bool Queen::isLegalMove(int cur_x, int cur_y, int des_x, int des_y, ChessPiece* cp[8][8]) {
    //Kiểm tra: Bước đi có hợp lệ với luật của quân cờ không?
    int d_x = des_x - cur_x;
    int d_y = des_y - cur_y;
    if (d_x == 0 && d_y == 0) return false;

    //Kiểm tra: Tại đích đến có quân cờ nào cùng màu không?
    ChessPiece* dest = cp[des_x][des_y];
    if (dest != 0) {
        if (dest->getColor() == this->getColor()) {
            return false;
        }
    }

    if (abs(d_x) == abs(d_y)) {
        //Kiểm tra: Trên đường đến đích (chéo) có quân cờ nào cản đường không?
        for (int i = 1; i < abs(d_x); i++) {
            int x = 0, y = 0;;

            if (d_x > 0) x = cur_x + i;
            else x = cur_x - i;
            if (d_y > 0) y = cur_y + i;
            else y = cur_y - i;

            if (cp[x][y] != 0)
                return false;
        }
        return true;
    }

    if (d_x == 0 || d_y == 0) {
        if (d_y == 0) {
            //Kiểm tra: Trên đường đến đích (ngang) có quân cờ nào cản đường không?
            for (int i = 1; i < abs(d_x); i++) {
                int x = 0;
                if (d_x > 0) x = cur_x + i;
                else x = cur_x - i;

                if (cp[x][cur_y] != 0)
                    return false;
            }
        }
        else {
            //Kiểm tra: Trên đường đến đích (dọc) có quân cờ nào cản đường không?
            for (int i = 1; i < abs(d_y); i++) {
                int y = 0;
                if (d_y > 0) y = cur_y + i;
                else y = cur_y - i;

                if (cp[cur_x][y] != 0)
                    return false;
            }
        }
        return true;
    }
    return false;
}
