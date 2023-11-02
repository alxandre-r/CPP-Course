#pragma once

#include "Game.hpp"

class Morpion : public Game
{
	public:
		Morpion();
		~Morpion();

		void run(int& mode);
		void display_grid();
		void check_win(bool& checker, int& winner);
	
	private:
		bool check_rows(int& winner);
		bool check_columns(int& winner);
		bool check_diag(int& winner);
		void play_solo(int& symbol);
		void play_multi(int& symbol);
		void saisir_case(int& symbol);
		void tour_ia(int& symbol);
};