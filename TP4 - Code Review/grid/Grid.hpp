#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "../utils/Vec2.hpp"

class Grid
{
	public:
		Grid(int x, int y);
		~Grid();

		int get_element(int x, int y);
		int get_element_by_index(int index);
		void set_element(int x, int y, int value);
		void set_element_by_index(int index, int value);
		
		int get_width();
		int get_height();

		void display();

	private:
		std::vector<std::vector<int>> elements;
};
