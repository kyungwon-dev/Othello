#include <iostream>
#include "Consola.h"
#include "Interface.h"
using namespace std;

int main()
{
	cout << "Game Start" << "\n";
	View view;
	Interface interfaces;
	for (; interfaces.firstPhase() == 2; clrscr())
		interfaces.option();
	clrscr();
	view.secondPhase();
	clrscr();
	view.thirdPhase();
	clrscr();
	view.fourthPhase();
	return 0;
}
