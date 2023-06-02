#include "Pawn.h"
int Pawn::getValue() {
	return 10;
}
bool Pawn::isLegalMove(int srcRow, int srcCol, int destRow, int destCol, ChessPiece* cp[8][8]) {
	ChessPiece* dest = cp[destRow][destCol];

	// trường hợp ô đi đến không có quân cờ nào
	if (dest == 0)
	{
		// trường hợp đi trên cùng 1 cột
		if (srcCol == destCol)
		{
			// quân trắng: được đi tới 1 ô (row++)
			if (getColor() == 'W')
			{
				if (destRow == srcRow + 1) {
					return true;
				}
				// trường hợp là nước đi đầu tiên của quân tốt đó -> được đi 2 bước
				if (srcRow == 1 && destRow == srcRow + 2) {
					return true;
				}
			}
			// quân đen: được đi tới 1 ô (row--)
			else
			{
				if (destRow == srcRow - 1) {
					return true;
				}

				// trường hợp là nước đi đầu tiên của quân tốt đó -> được đi 2 bước
				if (srcRow == 6 && destRow == srcRow - 2) {
					return true;
				}
			}
		}
	}
	// trường hợp ô đi đến có quân cờ
	else
	{
		// trường hợp ô đi đến là quân cờ cùng màu
		if (dest->getColor() == this->getColor()) {
			return false;
		}

		// trường hợp ô đi đến là quân cờ màu đối nghịch
		// đi chéo lên phía trước 1 ô
		if ((srcCol == destCol + 1) || (srcCol == destCol - 1))
		{
			// cờ trắng ăn cờ đen
			if (getColor() == 'W')
			{
				if (destRow == srcRow + 1) {
					return true;
				}
			}
			// cờ đen ăn cờ trắng
			else
			{
				if (destRow == srcRow - 1) {
					return true;
				}
			}
		}
	}

	return false;
}