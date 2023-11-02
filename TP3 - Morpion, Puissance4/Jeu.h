#pragma once
#include <string>
using namespace std;

//classe abstraite Jeu qui contient les fonctions virtuelles pures pour le fonctionnement des classes moprions et puissance4
class Jeu
{
public:
	//constructeur
	Jeu();
	//destructeur
	~Jeu();

	string getFormeJoueur() const;
	string getFormeOrdinateur(string formeJoueur) const;

};

