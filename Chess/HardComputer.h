#ifndef _HARDCOMPUTER_H
#define _HARDCOMPUTER_H
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Player.h"
using namespace std;
class HardComputer :public Player {
public:
	HardComputer(char color);
	void selectChessPieceAndDest(ChessBoard* cb, int& srcRow, int& srcCol, int& desrow, int& descol);
};
struct Node {
	int srcrow, srccol, desrow, descol;
	int weight;
	vector <Node*> pNext;
};
void  insertNode(Node*&root,Node* add);
void Minimax(Node* root, char color);
void GameTreeTraversal(Node* root,char color);
void DeleteGameTree(Node* root);
Node* createGameTree(ChessBoard*cb,char color,int depth,int maxdepth);
#endif