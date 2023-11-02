#include "Player.hpp"

//pour chaque jeu, il y a 2 joueurs
//chaque joueur a un nom, un symbole
//les players sont créer dans le main

//constructeur
Player::Player(std::string name, char symbol)
{
	this->name = name;
	this->symbol = symbol;
}

//getters
std::string Player::getName()
{
	return name;
}

char Player::getSymbol()
{
	return symbol;
}
