#pragma once
#include "MainMethods.h"
#include <iostream>
#include <windows.h>
#include <string>
#include "Jeu.h"
using namespace std;

class Puissance4 : public Jeu
{
public:
	//constructeur
	Puissance4();

	//jeu 1 joueur
	void jouerSolo(int joueur);
	//pour jeu 1 joueur
	void nouveauTourSolo(string forme);
	void TourOrdinateur(string forme);

	//jeu 2 joueurs
	void jouerDuo(int joueur);
	//pour jeu 2 joueurs
	void nouveauTour(int joueur);
	
	//grille
	void afficherGrille() const;
	bool caseVide(int ligne, int colonne) const;
	bool setCase(int icolonne, int ligne, string valeur);
	void placerForme(string forme);
	
	//fin
	bool testeFinJeu(int joueur);

private:
	string grille[4][7];
};