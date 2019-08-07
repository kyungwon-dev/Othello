#include <iostream>
#include "Interface.h"
#include "Consola.h"
#define M_LEFTKEY  0xe04b
#define M_RIGHTKEY  0xe04d
#define M_UPKEY    0xe048
#define M_DOWNKEY  0xe050
#define M_ENTER 0x0d
using namespace std;
int Interface::option()
{
	int ch = 0;
	gotoxy(24, 24);
	cout << "▷사용하고 싶은 말을 선택해 주세요";
	gotoxy(24, 25);
	cout << "●  ★  ♠  ♥  ☎  돌";
	for (int x = 24;;)
	{
		gotoxy(x, 25);
		switch ((ch = getKey()))
		{
		case M_RIGHTKEY:
			x = ((x >= 44) ? 24 : x + 4);
			break;
		case M_ENTER:
			return _choice = (x - 24) / 4;
		}
	}
}
int Interface::firstPhase()
{
	int ch = 0;
	_setcursortype(2);
	printSquare(10, 3, 70, 28, 0);
	printSquare(20, 13, 60, 26, 0);
	gotoxy(14, 5); cout << "■■■  ■■■  ■  ■  ■■■  ■      ■      ■■■\n";
	gotoxy(14, 6); cout << "■  ■    ■    ■  ■  ■      ■      ■      ■  ■\n";
	gotoxy(14, 7); cout << "■  ■    ■    ■  ■  ■      ■      ■      ■  ■\n";
	gotoxy(14, 8); cout << "■  ■    ■    ■■■  ■■■  ■      ■      ■  ■\n";
	gotoxy(14, 9); cout << "■  ■    ■    ■  ■  ■      ■      ■      ■  ■\n";
	gotoxy(14, 10); cout << "■  ■    ■    ■  ■  ■      ■      ■      ■  ■\n";
	gotoxy(14, 11); cout << "■■■    ■    ■  ■  ■■■  ■■■  ■■■  ■■■\n";
	gotoxy(24, 15); cout << "▶ PLAYER VS COMPUTER";
	gotoxy(24, 19); cout << "▶ PLAYER VS PLAYER";
	gotoxy(24, 23); cout << "▶ SETTING";
	for (int y = 15;;)
	{
		gotoxy(24, y);
		switch ((ch = getKey()))
		{
		case M_DOWNKEY:
			y = ((y>22) ? 15 : y + 4);
			break;
		case M_ENTER:
			return _next = (y - 15) / 4;
		}
	}
}