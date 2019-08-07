#pragma once
#include "Controller.h"
class View :public Controller
{
public:
	void fillBox(int x1, int y1, int x2, int y2, int color);
	void thirdPhase();
	void printSquare(int x1, int y1, int x2, int y2, int board);
	void fourthPhase();
	void printBoard(int x1, int y1, int x2, int y2);
	void secondPhase();
	void playerStatement();
};
