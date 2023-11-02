#include "Puissance4.hpp"

Puissance4::Puissance4()
{
	grid = new Grid(6, 7);
}

Puissance4::~Puissance4()
{
	
}

void Puissance4::run(int& mode)
{
	int symbol;
	switch (mode)
	{
	default:
		std::cerr << "Mode switcher error.\n";
		break;

	case 1:
		std::cout << "You are playing against the computer.\n";
		choose_symbol(symbol);
		play_solo(symbol);
		break;

	case 2:
		std::cout << "You are playing against another player.\n";
		choose_symbol(symbol);
		play_multi(symbol);
		break;
	}
}

void Puissance4::play_solo(int& symbol)
{
	bool player_win = false;
	int winner;
	bool ia = false;
	int ia_symbol = symbol == 1 ? 2 : 1;
	while (!player_win)
	{
		display_grid();
		if (ia)
		{
			tour_ia(ia_symbol);
			ia = false;
		}
		else
		{
			saisir_col(symbol);
			ia = true;
		}
	}
	display_grid();
	end_screen(symbol, winner);
}

void Puissance4::play_multi(int& symbol)
{
	bool player_win = false;
	int winner;
	while (!player_win)
	{
		display_grid();
		saisir_col(symbol);
		check_win(player_win, winner);
		if (symbol == 1)
			symbol = 2;
		else
			symbol = 1;
	}
	end_screen(symbol, winner);
}

void Puissance4::display_grid()
{
	grid->display();
}

void Puissance4::check_win(bool& checker, int& winner)
{
}

void Puissance4::saisir_col(int& symbol)
{
	int col;
	while (true)
	{
		std::cout << "Choose a column (1-7):";
		std::cin >> col;
		verif_IsIntegerBetween(col, 1, 7);
		col--;
		for (int i = 5; i >= 0; i--)
		{
			if (grid->get_element(i, col) == 0)
			{
				grid->set_element(i, col, symbol);
				return;
			}
		}
		std::cout << "This column is full.\n";
	}
}

void Puissance4::tour_ia(int& symbol)
{
	int col;
	while (true)
	{
		col = rand() % 6;
		for (int i = 5; i >= 0; i--)
		{
			if (grid->get_element(i, col) == 0)
			{
				grid->set_element(i, col, symbol);
				return;
			}
		}
	}
}