#include <iostream>
#include <conio.h>
#include "Consola.h"
#include "Controller.h"
#include <Windows.h>
#define M_LEFTKEY  0xe04b
#define M_RIGHTKEY  0xe04d
#define M_UPKEY    0xe048
#define M_DOWNKEY  0xe050
#define M_ENTER 0x0d
using namespace std;
int Controller::toscreeny(int cols)
{
	return (2 * cols) + 7;
}
int Controller::toscreenx(int rows)
{
	return (4 * rows) + 26;
}
int Controller::restrictStone(int cols, int rows, int turn)
{
	return ((_map[cols][rows] == 0) ? Controller::changeStone(cols, rows, turn) : 0);
}
int Controller::changeStone(int cols, int rows, int turn)
{
	_changestone = 0;
	_changestone += Controller::checkDirection(cols, rows, -1, -1, turn);
	_changestone += Controller::checkDirection(cols, rows, -1, 0, turn);
	_changestone += Controller::checkDirection(cols, rows, -1, 1, turn);
	_changestone += Controller::checkDirection(cols, rows, 0, -1, turn);
	_changestone += Controller::checkDirection(cols, rows, 0, 1, turn);
	_changestone += Controller::checkDirection(cols, rows, 1, -1, turn);
	_changestone += Controller::checkDirection(cols, rows, 1, 0, turn);
	_changestone += Controller::checkDirection(cols, rows, 1, 1, turn);
	return  _changestone;
}
void Controller::moveKey()
{
	int ch = 0;
	for (int cols = 0, rows = 0; ch != 'q' && (_player1score) && (_player2score) && (_turn != 60);)
	{
		turnAlerm((_turn % 2) + 1);
		gotoxy(Controller::toscreenx(rows), Controller::toscreeny(cols));
		switch ((ch = Controller::getKey()))
		{
		case M_UPKEY:
			cols = ((cols <= 0) ? 0 : cols - 1);
			break;
		case M_DOWNKEY:
			cols = ((cols >= 7) ? 7 : cols + 1);
			break;
		case M_LEFTKEY:
			rows = ((rows <= 0) ? 0 : rows - 1);
			break;
		case M_RIGHTKEY:
			rows = ((rows >= 7) ? 7 : rows + 1);
			break;
		case M_ENTER:
			textbackground(0);
			_next++;
			if (Controller::restrictStone(cols, rows, (_turn % 2) + 1) > 0)
			{
				_map[cols][rows] = ((_turn++) % 2) + 1;
				gotoxy(30, 25);
				cout << "                       ";
				_next--;
				if (!_next)
					cputurn(((_turn++) % 2) + 1);
			}
			else
			{
				_next--;
				gotoxy(30, 25);
				cout << "\a\a이곳엔 놓을 수 없습니다";
			}
			textbackground(10);
			scoreCurrent();
			printStone();
			break;
		}
	}
	textbackground(0);
	gotoxy(21, 27);
	cout << "게임이 끝났습니다.점수화면으로 넘어갑니다.";
	getchar();
}
int Controller::checkDirection(int cols, int rows, int drows, int dcols, int turn)
{
	for (int change = 0, count = 0, checkrows = rows + drows, checkcols = cols + dcols;
		(checkrows >= 0 && checkrows <= 7) && (checkcols >= 0 && checkcols <= 7) && (_map[checkcols][checkrows] == (turn % 2) + 1)
		; checkrows += drows, checkcols += dcols)
	{
		++count;
		if ((checkrows + drows >= 0 && checkrows + drows <= 7) && (checkcols + dcols >= 0 && checkcols + dcols <= 7) && _map[checkcols + dcols][checkrows + drows] == turn)
		{
			for (checkrows = rows + drows, checkcols = cols + dcols;
				(checkrows >= 0 && checkrows <= 7) && (checkcols >= 0 && checkcols <= 7) && count>0;
				count--, checkrows += drows, checkcols += dcols)
			{
				if (_next)
					_map[checkcols][checkrows] = turn;
				change++;
			}
			return change;
		}
	}
	return 0;
}
void Controller::printStone()
{
	for (int cols = 0; cols<8; cols++)
	{
		for (int rows = 0; rows<8; rows++)
			(_map[cols][rows] != 0) ? (stoneOption(cols, rows)) : isEmpty();
	}
	textcolor(15);
}
void Controller::turnAlerm(int turn)
{
	textbackground(0);
	gotoxy(34, 4);
	cout << ((turn == 1) ? _player1 : _player2) << "의 차례입니다";
	textbackground(15);
}
void Controller::isEmpty() {

}
void Controller::stoneOption(int cols, int rows)
{
	gotoxy(toscreenx(rows), toscreeny(cols));
	textcolor(((_map[cols][rows] == 1) ? 0 : 15));
	cout << _stone[_choice];
}
void Controller::cputurn(int turn)
{
	int max = 0;
	int find = 0;
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			max = (max <restrictStone(i, j, turn) ? restrictStone(i, j, turn) : max);
		}
	}
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			if (max == restrictStone(i, j, turn))
			{
				_next++;
				restrictStone(i, j, turn);
				_map[i][j] = turn;
				_next--;
				return;
			}
		}
	}
}
void Controller::scoreCurrent()
{
	_player1score = 0;
	_player2score = 0;
	for (int cols = 0; cols<8; cols++)
	{
		for (int rows = 0; rows<8; rows++)
			(_map[cols][rows] == 1 ? _player1score++ : (_map[cols][rows] == 2 ? _player2score++ : NULL));
	}
	textbackground(0);
	gotoxy(6, 15);
	cout << "돌개수:";
	cout.width(2);
	cout << _player1score;
	gotoxy(66, 15);
	cout << "돌개수:";
	cout.width(2);
	cout << _player2score;
	textbackground(10);
}
int Controller::getKey()
{
	int ch = _getch();
	if (ch == 0xe0)
		ch = (ch << 8) | _getch();
	return ch;
}
