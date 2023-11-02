#pragma once

#include "Game.hpp"

class Othello : public Game
{
public:
	Othello();
	~Othello();

	void run(int& mode);
	void display_grid();
	void check_win(bool& checker, int& winner);

private:
	void set_start_case();
	void replace_symbolBetween(int& symbol, int& column, int& line);
	void play_solo(int& symbol);
	void play_multi(int& symbol);
	void saisir_case(int& symbol, int& column, int& line);
	bool empty_case(int& column, int& line);
	void tour_ia(int& symbol);
};
