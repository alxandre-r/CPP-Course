#pragma once

#include "../grid/Grid.hpp"
#include "../utils/Utils.hpp"

class Game
{
	public:		
		virtual void run(int& mode) = 0;
		virtual void display_grid() = 0;
		virtual void check_win(bool& checker, int& winner) = 0;

	protected:
		Grid* grid;
};
