#pragma once

#include "Game.hpp"

class Puissance4 : public Game
{
	public:
		Puissance4();
		~Puissance4();

		void run(int& mode);
		void display_grid();
		void check_win(bool& checker, int& winner);
		
	private:
		void play_solo(int& symbol);
		void play_multi(int& symbol);
		void saisir_col(int& symbol);
		void tour_ia(int& symbol);
};
