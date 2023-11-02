#include "Utils.hpp"

void clear_screen()
{
#ifdef _WIN32
	system("cls");
#else 
	system("clear");
#endif
}

//symbol to integer
int stoi(char symbol)
{
	switch (symbol)
	{
	case 'X':
		return 1;
		break;
	case 'O':
		return 2;
		break;
	default:
		return -1;
		std::cout << "error in switch stoi : symbol = " << symbol << std::endl;
		break;
	}
}

//integer to symbol
char itos(int number)
{
	switch (number)
	{
	case 1:
		return 'X';
		break;
	case 2:
		return 'O';
		break;
	default:
		return ' ';
		std::cout << "error in switch itos : number = " << number << std::endl;
		break;
	}
}

void verif_IsIntegerBetween(int& number, int number1, int number2)
{
	while (std::cin.fail() || number < number1 || number > number2)
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Please enter a valid number: ";
		std::cin >> number;
	}
}

void verif_IsLetterBetween(char& letter, char letter1, char letter2)
{
	letter = toupper(letter);
	
	while (std::cin.fail() || letter < letter1 || letter > letter2)
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Please enter a valid letter: ";
		std::cin >> letter;
		letter = toupper(letter);
	}
}

char verif_IsSymbolRight(char& symbol)
{
	while (std::cin.fail() || (symbol != 'x' && symbol != 'X' && symbol != 'o' && symbol != 'O'))
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Please enter a valid symbol: ";
		std::cin >> symbol;
	}
	return symbol;
}

void choose_symbol(int& n)
{
	char symbol;
	std::cout << "Choose your symbol : X/O\n";
	std::cin >> symbol;

	symbol = toupper(verif_IsSymbolRight(symbol));
	n = stoi(symbol);
	
	std::cout << "You are playing with " << symbol << ".\n";
}

void main_menu(int& mode, int& mode2)
{
	clear_screen();
	int safe = 0;
	
	std::cout << "----- Menu principal -----" << std::endl;
	std::cout << "Veuillez choisir un jeu :\n";
	std::cout << "\t- Morpion (1)\n";
	std::cout << "\t- Puissance 4 (2)\n";
	std::cout << "\t- Othello (3)\n";
	std::cin >> safe;

	verif_IsIntegerBetween(safe, 1, 3);

	mode = safe;
	clear_screen();

	std::cout << "Veuillez choisir le mode de jeu :\n";
	std::cout << "\t- Solo (1)\n";
	std::cout << "\t- Multijoueur (2)\n";
	std::cin >> safe;

	verif_IsIntegerBetween(safe, 1, 2);
	
	mode2 = safe;
	clear_screen();
}

void end_screen(int& symbol, int& winner)
{
	if(symbol == winner)
		std::cout << "Victoire des " << itos(symbol) << " !\n";
	else
		std::cout << "Défaite des " << itos(symbol) << " !\n";

	
	char ask;
	std::cout << "Voulez vous rejouer ? (Y/n)\n";
	std::cin >> ask;
	
	if (ask == 'n')
		return;
}