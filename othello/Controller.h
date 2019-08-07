#pragma once
#include "Model.h"
class Controller :public Model
{
public:
	int toscreeny(int cols);
	int toscreenx(int rows);
	int restrictStone(int cols, int rows, int turn);
	int changeStone(int cols, int rows, int turn);
	void moveKey();
	int checkDirection(int cols, int rows, int drows, int dcols, int turn);
	void stoneOption(int cols, int rows);
	void printStone();
	void turnAlerm(int turn);
	void scoreCurrent();
	void cputurn(int turn);
	int getKey();
	void isEmpty();
};
