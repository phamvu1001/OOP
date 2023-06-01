#include "Computer.h"
Computer::Computer(char color):Player(string("Computer(Easy)"), color) {
}
void Computer::selectChessPieceAndDest(ChessBoard* cb, int& srcRow, int& srcCol, int& desrow, int& descol) {
	vector <int> validmove;
	for (int i = 7; i >= 0; i--)
	{

		for (int j = 7; j >= 0; j--)
		{
			ChessPiece* currentPiece = cb->cp[i][j];
			if (currentPiece != NULL && currentPiece->getColor() == this->color) {
				for (int k = 7; k >= 0; k--)
				{
					for (int l = 7; l >= 0; l--)
					{
						ChessPiece* dest = cb->cp[k][l];
						bool LegalMove = cb->cp[i][j]->isLegalMove(i, j, k, l,cb->cp);
						cb->cp[k][l] = currentPiece;
						cb->cp[i][j] = NULL;
						bool SelfCheckMove = cb->isInCheck(this->color);
						cb->cp[i][j] = currentPiece;
						cb->cp[k][l] = dest;
						if (LegalMove && !SelfCheckMove)
						{
							validmove.push_back(i*1000+j*100+k*10+l);
						}
					}

				}
			}

		}
	}
	srand(time(0));
	int index = rand() % validmove.size() + 0;
	int chosen = *(validmove.begin() + index);
	srcRow = chosen / 1000;
	srcCol = (chosen / 100) % 10;
	desrow = (chosen / 10) % 10;
	descol = chosen % 10;
}