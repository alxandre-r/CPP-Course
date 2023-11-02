#include "Othello.hpp"

Othello::Othello()
{
	grid = new Grid(8, 8);
}

void Othello::run(int& mode)
{
	int symbol;
	switch (mode)
	{
	default:
		verif_IsIntegerBetween(mode, 1, 2);
		break;

	case 1:
		std::cout << "You are playing against the computer.\n";
		choose_symbol(symbol);
		set_start_case();
		play_solo(symbol);
		break;

	case 2:
		std::cout << "You are playing against another player.\n";
		choose_symbol(symbol);
		set_start_case();
		play_multi(symbol);
		break;
	}
}

void Othello::play_solo(int& symbol)
{
	bool player_win = false;
	int winner;
	bool ia = false;
	int ia_symbol = symbol == 1 ? 2 : 1;
	int turn = 0;
	
	while (!player_win)
	{
		turn++;
		int column = 0;
		int line = 0;
		display_grid();
		if (ia == true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			tour_ia(ia_symbol);
			replace_symbolBetween(ia_symbol, column, line);
			display_info(symbol, turn);
			ia = false;
		}
		else
		{
			saisir_case(symbol, column, line);
			replace_symbolBetween(symbol, column, line);
			display_info(symbol, turn);
			ia = true;
		}
		check_win(player_win, winner);
	}
	display_grid();
	end_screen(symbol, winner);
}

void Othello::play_multi(int& symbol)
{
	bool player_win = false;
	int winner;
	while (!player_win)
	{
		int column = 0;
		int line = 0;
		display_grid();
		saisir_case(symbol, column, line);
		replace_symbolBetween(symbol, column, line);
		check_win(player_win, winner);
		
		symbol = symbol == 1 ? 2 : 1;
	}
	end_screen(symbol, winner);
}

void Othello::saisir_case(int& symbol, int& column, int& line)
{
	char column_char;
	std::cout << "Enter the column (A to H) and the line (1 to 8) of the case you want to play.\n";
	std::cin >> column_char >> line;

	//verif des entrees
	verif_IsLetterBetween(column_char, 'A', 'H');
	verif_IsIntegerBetween(line, 1, 8);
	
	//convertion de la lettre colonne en chiffre de 0 a 7
	column = column_char - 65;
	line -= 1;

	//on place le symbole si la case est vide ET que la case est adjacente a un symbole adverse ET que remplacer le symbole adverse est possible
	if (grid->get_element(line, column) == 0 && is_adjacentTo(symbol, column, line) && is_replacePossible(symbol, column, line))
	{
		grid->set_element(line, column, symbol);
	}
	else
	{
		//error message
		std::cout << "You can't play here, ";
		if (grid->get_element(line, column) != 0){std::cout << "this case is not empty.\n";}
		else if (!is_adjacentTo(symbol, column, line)){std::cout << "this case is not adjacent to an opponent's symbol.\n";}
		else if (!is_replacePossible(symbol, column, line)){std::cout << "there is no opponent's symbol to replace between this location and one of your symbol.\n";}
		else {std::cout << "unknown reason. \n";}
		
		saisir_case(symbol, column, line);
	}
}

bool Othello::is_adjacentTo(int& symbol, int& column, int& line)
{
	//tableau des cases adjacentes
	const int adjacent[8][2] = { {line - 1, column - 1}, {line - 1, column}, {line - 1, column + 1}, {line, column - 1}, {line, column + 1}, {line + 1, column - 1}, {line + 1, column}, {line + 1, column + 1} };
	
	//pour chaque case adjacente
	for (int i = 0; i < 8; i++)
	{
		//si la case adjacente est une case de la grille
		if (adjacent[i][0] >= 0 && adjacent[i][0] <= 7 && adjacent[i][1] >= 0 && adjacent[i][1] <= 7)
		{
			//si la case adjacente est un symbole adverse
			if (grid->get_element(adjacent[i][0], adjacent[i][1]) != 0 && grid->get_element(adjacent[i][0], adjacent[i][1]) != symbol)
			{
				return true;
			}
		}
	}
	return false;
}

//renvoie true si il y a un symbole adverse entre la case jouee et un symbole du joueur
bool Othello::is_replacePossible(int& symbol, int& column, int& line)
{
	const int adjacent[8][2] = { {line - 1, column - 1}, {line - 1, column}, {line - 1, column + 1}, {line, column - 1}, {line, column + 1}, {line + 1, column - 1}, {line + 1, column}, {line + 1, column + 1} };
	
	for (int i = 0; i < 8; i++)
	{
		//si la case adjacente est une case de la grille
		if (adjacent[i][0] >= 0 && adjacent[i][0] <= 7 && adjacent[i][1] >= 0 && adjacent[i][1] <= 7)
		{
			//si la case adjacente est un symbole adverse
			if (grid->get_element(adjacent[i][0], adjacent[i][1]) != 0 && grid->get_element(adjacent[i][0], adjacent[i][1]) != symbol)
			{
				//continue dans la direction jusqu'à être au bord ou trouver un symbole du joueur
				int j = 1;
				while (adjacent[i][0] + j * (adjacent[i][0] - line) >= 0 && adjacent[i][0] + j * (adjacent[i][0] - line) <= 7 && adjacent[i][1] + j * (adjacent[i][1] - column) >= 0 && adjacent[i][1] + j * (adjacent[i][1] - column) <= 7)
				{
					if (grid->get_element(adjacent[i][0] + j * (adjacent[i][0] - line), adjacent[i][1] + j * (adjacent[i][1] - column)) == symbol)
					{
						return true;
					}
					j++;
				}
			}
		}
	}
	return false;
}

void Othello::replace_symbolBetween(int& symbol, int& column, int& line)
{
	if (is_replacePossible(symbol, column, line))
	{
		int symbol_opposite = symbol == 1 ? 2 : 1;
		const int directions[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

		char column_char = column + 65;
		std::cout << itos(grid->get_element(line, column)) << " placed at " << column_char << line + 1 << std::endl;
		
		//pour chaque direction
		for (int i = 0; i < 8; i++)
		{
			int column_temp = column;
			int line_temp = line;
			bool is_replacePossible = false;

			//tant que direction+1 == symbole inverse, direction+1
			while (grid->get_element(line_temp + directions[i][0], column_temp + directions[i][1]) == symbol_opposite)
			{
				column_temp += directions[i][1];
				line_temp += directions[i][0];
			}
			
			//si direction+1 == symbole, remplace les symboles entre
			if (grid->get_element(line_temp + directions[i][0], column_temp + directions[i][1]) == symbol)
			{
				while (grid->get_element(line_temp, column_temp) == symbol_opposite)
				{
					grid->set_element(line_temp, column_temp, symbol);
					column_temp -= directions[i][1];
					line_temp -= directions[i][0];
				}
			}
		}
	}
}

//tour ia
void Othello::tour_ia(int& symbol)
{
	//place le symbole dans une case aleatoire vide, adjacente et entourant un symbole adverse
	int column = rand() % 8;
	int line = rand() % 8;
	while (!is_adjacentTo(symbol, column, line) || grid->get_element(line, column) != 0)
	{
		column = rand() % 8;
		line = rand() % 8;
	}
	grid->set_element(line, column, symbol);
	replace_symbolBetween(symbol, column, line);
}

//affiche les infos du jeu : nombre de symbole pour chaque joueur, le numéro du tour, qui joue...
void Othello::display_info(int& symbol, int& turn)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "          " << itos(symbol) << " plays" << std::endl;
	std::cout << "----------------------------------\n" << std::endl;
	std::cout << "Number of symbols : Player 1 has " << grid->count_symbol(1) << "pieces, Player 2 has " << grid->count_symbol(2) <<" pieces" << std::endl;
}

//verifie si la case est vide
bool Othello::empty_case(int& column, int& line)
{
	if (grid->get_element(column, line) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Othello::check_win(bool& checker, int& winner) {

	int x = 0;
	int o = 0;
	
	//parcours la grille et compte le nombre de chaque symbole
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid->get_element(i, j) == 1)
			{
				x++;
			}
			else if (grid->get_element(i, j) == 2)
			{
				o++;
			}
		}
	}

	//si nombre de symbole dans le tableau = 64
	if (x + o == 64)
	{
		checker = true;
		if (x > o)
		{
			winner = 1;
		}
		else if (x < o)
		{
			winner = 2;
		}
		else
		{
			winner = 0;
		}
	}
}

void Othello::set_start_case() 
{
		grid->set_element(3, 3, 1);
		grid->set_element(3, 4, 2);
		grid->set_element(4, 3, 2);
		grid->set_element(4, 4, 1);
}

void Othello::display_grid()
{
	grid->display();
}