#pragma once
#include <iostream>
#include "Player.hpp"

class Player {
public:
	Player(std::string name, char symbol);
	std::string getName();
	char getSymbol();
private:
	std::string name;
	char symbol;
};

