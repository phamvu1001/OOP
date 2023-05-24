#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
using namespace std;

class ChessBoard
{
public:
	ChessPiece* cp[8][8];
	ChessBoard()
	{
		// thiet lap quan den
		cp[0][0] = new ChessPiece('B');
		//...
		// thiet lap quan trang
		cp[7][7] = new ChessPiece('W');
		//...
	}
	~ChessBoard()
	{
		//ham huy 
		delete cp[0][0];
		cp[0][0] = 0;
		//...
	}
	void Print()
	{
		//...
	}
};
#endif // !CHESSBOARD_H
