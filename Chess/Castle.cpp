#include "Castle.h"

bool Castle::isLegalMove(int srcRow, int srcCol, int destRow, int destCol, ChessPiece* cp[8][8]) {
	ChessPiece* dest = cp[destRow][destCol];
	// trường hợp ô đi đến là quân cờ cùng màu
	if (dest->getColor() == this->getColor()) {
		return false;
	}

	// đi theo chiều ngang
	if (srcRow == destRow)
	{
		// kiểm tra xem trên đường đi tới dest có quân cờ nào cản không
		// nếu có thì không đi được -> return false
		int colOffset = (destCol - srcCol > 0) ? 1 : -1;
		for (int checkCol = srcCol + colOffset; checkCol != destCol; checkCol += colOffset)
		{
			if (cp[srcRow][checkCol] != 0)
				return false;
		}
		return true;
	}
	// đi theo chiều dọc
	else if (destCol == srcCol)
	{
		// kiểm tra xem trên đường đi tới dest có quân cờ nào cản không
		// nếu có thì không đi được -> return false
		int rowOffset = (destRow - srcRow > 0) ? 1 : -1;
		for (int checkRow = srcRow + rowOffset; checkRow != destRow; checkRow += rowOffset)
		{
			if (cp[checkRow][srcCol] != 0)
				return false;
		}
		return true;
	}
	return false;
}
