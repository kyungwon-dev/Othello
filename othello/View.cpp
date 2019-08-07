#include <iostream>
#include <conio.h>
#include "Consola.h"
#include "View.h"
#define M_LEFTKEY  0xe04b
#define M_RIGHTKEY  0xe04d
#define M_UPKEY    0xe048
#define M_DOWNKEY  0xe050
#define M_ENTER 0x0d
using namespace std;

void View::fillBox(int x1, int y1, int x2, int y2, int color)
{
	textbackground(color);
	for (int y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		for (int x = x1; x <= x2; x += 2)
			cout << " ";
	}
}
void View::thirdPhase()
{
	playerStatement();
	fillBox(24, 6, 56, 22, 10);
	printSquare(24, 6, 56, 22, 1);
	gotoxy(26, 7);
	scoreCurrent();
	View::printStone();
	moveKey();
}
void View::printSquare(int x1, int y1, int x2, int y2, int board = 0)
{
	for (int x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		cout << ((x == x1) ? "┏" : ((x == x2) ? "┓" : "━"));
		gotoxy(x, y2);
		cout << ((x == x1) ? "┗" : ((x == x2) ? "┛" : "━"));
	}
	for (int y = (y1 + 1); y<y2; y++)
	{
		gotoxy(x2, y);
		cout << "┃";
		gotoxy(x1, y);
		cout << "┃";
	}
	if (board)
		printBoard(x1, y1, x2, y2);
}
void View::fourthPhase()
{
	printSquare(18, 3, 68, 27);
	gotoxy(33, 8);
	cout << _player1 << " SCORE: " << _player1score;
	gotoxy(33, 13);
	cout << _player2 << " SCORE: " << _player2score;
	gotoxy(33, 17);
	cout << ((_player1score > _player2score) ? ((_player1score == _player2score) ? "DRAW" : _player1) : _player2) << " WIN!!!!";
	gotoxy(33, 22);
	cout << "게임을 종료합니다";
	gotoxy(1, 1);
	textcolor(0);
}
void View::printBoard(int x1, int y1, int x2, int y2)
{
	for (int x = x1 + 4; x<x2 - 2; x += 4)
	{
		gotoxy(x, y1);
		cout << "┳";
		gotoxy(x, y2);
		cout << "┻";
	}
	for (int y = (y1 + 2); y<y2; y += 2)
	{
		gotoxy(x1, y);
		cout << "┣";
		gotoxy(x2, y);
		cout << "┫";
	}
	for (int y = y1 + 1; y<y2; y += 1)
	{
		if (y % 2 == 0)
		{
			gotoxy(x1 + 2, y);
			cout << "━";
		}
		for (int x = x1 + 4; x<x2 - 2; x += 4)
		{
			gotoxy(x, y);
			cout << (((y % 2) == 1) ? "┃  " : "╋━");
		}
	}
}
void View::secondPhase()
{
	gotoxy(20, 10);
	cout << "첫번째 플레이어의 이름을 작성하시오(3글자):";
	cin >> _player1;
	if (!_next)
		return;
	gotoxy(20, 20);
	cout << "두번째 플레이어의 이름을 작성하시오(3글자):";
	cin >> _player2;
}
void View::playerStatement()
{
	printSquare(1, 4, 19, 25, 0);
	printSquare(61, 4, 79, 25, 0);
	gotoxy(8, 7);
	cout << _player1;
	gotoxy(68, 7);
	cout << _player2;
}
