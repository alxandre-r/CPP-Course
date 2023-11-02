#include <iostream>
#include <windows.h>
#include "MainMethods.h"


using namespace std;

//méthodes pour clear screen
void pos(short Croix, short Rond)
{
	COORD xy;
	xy.X = Croix;
	xy.Y = Rond;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void clear()
{
	pos(0, 0);
	for (int j = 0; j < 100; j++)
		std::cout << string(100, ' ');
	pos(0, 0);
}

void isNbJoueurInt1or2(int joueur) {

	//tant que input n'est pas 1 ou 2
	while (cin.fail() || (joueur != 1 && joueur != 2))
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Veuillez entrer un nombre valide" << endl;
		std::cin >> joueur;
	}
}