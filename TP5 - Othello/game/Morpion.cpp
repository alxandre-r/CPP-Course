#include "Morpion.hpp"

Morpion::Morpion()
{
	grid = new Grid(3, 3);
}

Morpion::~Morpion()
{
}

void Morpion::run(int& mode)
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

void Morpion::play_solo(int& symbol)
{
	bool player_win = false;
	int winner;
	bool ia = false;
	int ia_symbol = symbol == 1 ? 2 : 1;
	while (!player_win)
	{
		display_grid();
		if (ia == true)
		{
			tour_ia(ia_symbol);
			ia = false;
		}
		else
		{
			saisir_case(symbol);
			ia = true;
		}
		check_win(player_win, winner);
	}
	display_grid();
	end_screen(symbol, winner);
}

void Morpion::play_multi(int& symbol)
{
	bool player_win = false;
	int winner;
	while (!player_win)
	{
		display_grid();
		saisir_case(symbol);
		check_win(player_win, winner);
		if (symbol == 1)
			symbol = 2;
		else
			symbol = 1;
	}
	end_screen(symbol, winner);
}

void Morpion::saisir_case(int& symbol)
{
	int s;
	if(symbol == 1)
		std::cout << "Joueur 1 (X)\n";
	else
		std::cout << "Joueur 2 (O)\n";

		std::cout << "Entrez le numéro de la case dans laquelle vous voulez placer votre symbole : (1-9).\n";
		std::cin >> s;
		verif_IsIntegerBetween(s, 1, 9);

	grid->set_element_by_index(s-1, symbol);
}

void Morpion::tour_ia(int& symbol)
{
	int s;
	int safe = 0;
	while (!safe)
	{
		s = rand() % 9;
		if (grid->get_element_by_index(s) == 0)
			safe = 1;
	}
	grid->set_element_by_index(s, symbol);
}

void Morpion::display_grid()
{
	grid->display();
}

bool Morpion::check_rows(int& winner)
{
	for(int i = 0; i < grid->get_width(); i++)
	{
		if (grid->get_element(i, 0) == grid->get_element(i, 1) && grid->get_element(i, 0) == grid->get_element(i, 2) && grid->get_element(i, 0) != 0)
		{
			winner = grid->get_element(i, 0);
			return true;
		}
	}
	return false;
}

bool Morpion::check_columns(int& winner)
{
	for (int i = 0; i < grid->get_width(); i++)
	{
		if (grid->get_element(0, i) == grid->get_element(1, i) && grid->get_element(0, i) == grid->get_element(2, i) && grid->get_element(0, i) != 0)
		{
			winner = grid->get_element(0, i);
			return true;
		}
	}
	return false;
}

bool Morpion::check_diag(int& winner)
{
	if (grid->get_element(0, 0) == grid->get_element(1, 1) && grid->get_element(0, 0) == grid->get_element(2, 2) && grid->get_element(0, 0) != 0)
	{
		winner = grid->get_element(0, 0);
		return true;
	}
	if (grid->get_element(0, 2) == grid->get_element(1, 1) && grid->get_element(0, 2) == grid->get_element(2, 0) && grid->get_element(0, 2) != 0)
	{
		winner = grid->get_element(0, 2);
		return true;
	}
	return false;
}

void Morpion::check_win(bool& checker, int& winner)
{
	if(check_diag(winner) || check_rows(winner) || check_columns(winner))
		checker = true;
}