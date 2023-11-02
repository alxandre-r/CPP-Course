#include "Jeu.h"
#include <iostream>
#include <string>
#include "MainMethods.h"
using namespace std;

//classe abstraite
Jeu::Jeu()
{
}

Jeu::~Jeu()
{
}

//retourne la forme du joueur
string Jeu::getFormeJoueur() const
{
	//définition de la forme du joueur
	string formeJoueur;
	std::cout << "Choisissez votre forme (X ou O)" << endl;
	std::cin >> formeJoueur;

	//test entree de la forme
	while (formeJoueur != "X" && formeJoueur != "O") {
		clear();
		std::cout << "Choisissez votre forme (X ou O)" << endl;
		std::cout << "Veuillez entrer X ou O" << endl;
		std::cin >> formeJoueur;
	}
	return formeJoueur;
}

//retourne la forme de l'ordinateur d'après la forme du joueur
string Jeu::getFormeOrdinateur(string formeJoueur) const
{
	string formeOrdinateur;
	if (formeJoueur == "X")
	{
		formeOrdinateur = "O";
	}
	else
	{
		formeOrdinateur = "X";
	}
	return formeOrdinateur;
}




