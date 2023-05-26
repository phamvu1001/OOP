#include "ChessBoard.h"
#include "Castle.h"
#include "Bishop.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"

ChessBoard::ChessBoard()
{
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
			cp[row][col] = 0;
	}

	// thiet lap quan den
	cp[0][0] = new Castle('B');
	cp[0][1] = new Knight('B');
	cp[0][2] = new Bishop('B');
	cp[0][3] = new Queen('B');
	cp[0][4] = new King('B');
	cp[0][5] = new Bishop('B');
	cp[0][6] = new Knight('B');
	cp[0][7] = new Castle('B');

	// thiet lap tot den
	cp[1][0] = new Pawn('B');
	cp[1][1] = new Pawn('B');
	cp[1][2] = new Pawn('B');
	cp[1][3] = new Pawn('B');
	cp[1][4] = new Pawn('B');
	cp[1][5] = new Pawn('B');
	cp[1][6] = new Pawn('B');
	cp[1][7] = new Pawn('B');

	// thiet lap hang tot trang
	cp[6][0] = new Pawn('W');
	cp[6][1] = new Pawn('W');
	cp[6][2] = new Pawn('W');
	cp[6][3] = new Pawn('W');
	cp[6][4] = new Pawn('W');
	cp[6][5] = new Pawn('W');
	cp[6][6] = new Pawn('W');
	cp[6][7] = new Pawn('W');

	// thiet lap quan trang
	cp[7][0] = new Castle('W');
	cp[7][1] = new Knight('W');
	cp[7][2] = new Bishop('W');
	cp[7][3] = new Queen('W');
	cp[7][4] = new King('W');
	cp[7][5] = new Bishop('W');
	cp[7][6] = new Knight('W');
	cp[7][7] = new Castle('W');
	//...
}
ChessBoard::~ChessBoard()
{
	//ham huy 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete cp[i][j];
			cp[i][j] = 0;
		}
	}
}
void ChessBoard::Print()
{
	{
		// and let's try this here
		using namespace std;

		const int squareHeight = 3;
		const int squareWidth = 4;

		for (int row = 0; row < 8 * squareHeight; ++row)
		{
			int squareRow = row / squareHeight;
			// print side border with numbering
			if (row % 3 == 1)
			{
				cout << '-' << (char)('1' + 7 - squareRow) << '-';
			}
			else
			{
				cout << "---";
			}
			// print the chess board
			for (int col = 0; col < 8 * squareWidth; col++)
			{
				int squareCol = col / squareWidth;
				if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && cp[7 - squareRow][squareCol] != 0)
				{
					if ((col % 4) == 1)
					{
						cout << cp[7 - squareRow][squareCol]->getColor();
					}
					else
					{
						cout << cp[7 - squareRow][squareCol]->getPiece();
					}
				}
				else
				{
					if ((squareRow + squareCol) % 2 == 1)
					{
						cout << ':';
					}
					else
					{
						cout << ' ';
					}
				}
			}
			cout << endl;
		}
		// print the bottom border with numbers
		for (int row = 0; row < squareHeight; row++)
		{
			if (row % 3 == 1)
			{
				cout << "---";
				for (int col = 0; col < 8 * squareWidth; col++)
				{
					int squareCol = col / squareWidth;
					if ((col % 4) == 1)
					{
						cout << (squareCol + 1);
					}
					else
					{
						cout << '-';
					}
				}
				cout << endl;
			}
			else
			{
				for (int col = 1; col < 9 * squareWidth; col++)
				{
					cout << '-';
				}
				cout << endl;
			}
		}
	}
}


bool ChessBoard::isInCheck(char color)
{
	// find the king
	int kingRow = 0;
	int kingCol = 0;
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (cp[row][col] != 0)
			{
				if (cp[row][col]->getColor() == color)
				{
					if (cp[row][col]->getPiece() == 'K')
					{
						kingRow = row;
						kingCol = col;
					}
				}
			}
		}
	}

	// run through the opponent's pieces and see if any can take the king
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (cp[row][col] != 0)
			{
				if (cp[row][col]->getColor() != color)
				{
					if (cp[row][col]->isLegalMove(row, col, kingRow, kingCol, cp))
						return true;
				}
			}
		}
	}

	return false;
}

bool ChessBoard::canMove(char color)
{
	// run through all pieces
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (cp[row][col] != 0)
			{
				// if it is a piece of the current player, see if it has a legal move
				if (cp[row][col]->getColor() == color)
				{
					for (int moveRow = 0; moveRow < 8; ++moveRow)
					{
						for (int moveCol = 0; moveCol < 8; ++moveCol)
						{
							if (cp[row][col]->isLegalMove(row, col, moveRow, moveCol, cp))
							{
								// make move and check whether king is in check
								ChessPiece* temp = cp[moveRow][moveCol];
								cp[moveRow][moveCol] = cp[row][col];
								cp[row][col] = 0;
								bool boolCanMove = !isInCheck(color);

								// undo the move
								cp[row][col] = cp[moveRow][moveCol];
								cp[moveRow][moveCol] = temp;

								if (boolCanMove)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
