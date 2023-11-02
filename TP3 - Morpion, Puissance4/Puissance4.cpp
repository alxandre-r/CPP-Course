#include "Puissance4.h"
using namespace std;

//constructeur
Puissance4::Puissance4() : Jeu()
{
	//création d'une grille 4x7 remplie d'espaces
	for (int ligne = 0; ligne < 4; ligne++)
	{
		for (int colonne = 0; colonne < 7; colonne++)
		{
			grille[ligne][colonne] = " ";
		}
	}	
}

//jeu 1 joueur
void Puissance4::jouerSolo(int joueur) {

	//definition des formes du joueur et de l'ordinateur
	string formeJoueur = getFormeJoueur();
	string formeOrdinateur = getFormeOrdinateur(formeJoueur);
	int ordinateur;
	if (formeOrdinateur == "X") {
		ordinateur = 0;
	}
	else {
		ordinateur = 1;
	}

	do {
		//joueur place sa forme
		nouveauTourSolo(formeJoueur);

		//si joueur n'a pas gagné, ordinateur place sa forme
		if (!testeFinJeu(joueur)) {

			//ordinateur place sa forme
			TourOrdinateur(formeOrdinateur);
		}
		//si joueur a gagné fin du jeu
		else {
			break;
		}
	} while (!testeFinJeu(joueur));//tant que ordinateur n'a pas gagner
}

//pour jeu 1 joueur
void Puissance4::nouveauTourSolo(string forme) {
	//la forme choisie en amont est entrée en paramètre
	placerForme(forme);
}

void Puissance4::TourOrdinateur(string forme) {
	//random seed
	srand((unsigned)time(NULL));
	int colonne;
	int ligne;
	bool estVide = false;

	//affichage
	afficherGrille();
	std::cout << "\n";
	std::cout << "Tour de l'ordinateur..." << std::endl;
	Sleep(1000);

	//l'ordinateur place sa forme dans une colonne aléatoire
	do {
		colonne = rand() % 7;

		//pour chaque ligne de la colonne choisie
		for (int i = 3; i > 0; i--) {
			//si la case est vide
			if (grille[i][colonne] == " ") {
				//on place la forme
				grille[i][colonne] = forme;
				estVide = true;
				break;
			}
		}
	} while (!estVide);
}

//jeu 2 joueurs
void Puissance4::jouerDuo(int joueur) {
	do {
		joueur += 1; //alterne entre joueur X (pair) et joueur O (impair)
		nouveauTour(joueur);
		clear();
	} while (!testeFinJeu(joueur));
}

//pour jeu 2 joueurs
void Puissance4::nouveauTour(int joueur) 
{
	//la forme est déterminée par le numéro du joueur (pair = X, impair = O)
	string stringforme;
	string forme;
	if (joueur % 2 == 0) {
		stringforme = "Croix";
		forme = "X";
	}
	else {
		stringforme = "Rond";
		forme = "O";
	}
	std::cout << "Tour du joueur ayant les " << stringforme << std::endl;
	placerForme(forme);
}

//affichage de la grille
void Puissance4::afficherGrille() const
{
	std::cout << std::endl << "     -----------------------------" << std::endl << "     ";
	for (int ligne = 0; ligne < 4; ligne++)
	{
		for (int colonne = 0; colonne < 7; colonne++)
		{
			std::cout << "| " << grille[ligne][colonne] << " ";
		}

		std::cout << "|" << std::endl << "     -----------------------------" << std::endl;
		std::cout << "     ";
	}
}

//vérifie que la case soit bien rempli de " "
bool Puissance4::caseVide(int ligne, int colonne) const
{
	if (grille[ligne][colonne] == " ")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//remplissage d'une case [ligne][colonne] par le jeton du joueur
bool Puissance4::setCase(int ligne, int colonne, string valeur)
{
	if (caseVide(ligne, colonne))
	{
		grille[ligne][colonne] = valeur;
		return true;
	}
	else {
		std::cout << "Erreur lors de l'assignation de la valeur (setCase)" << std::endl;
		return false;
	}
}

//place le jeton du joueur dans la colonne choisie
void Puissance4::placerForme(string forme)
{
	int colonne;
	bool valide = false;
	while (!valide)
	{
		//affichage
		afficherGrille();
		std::cout << "Choisissez une colonne (1-7) : ";
		std::cin >> colonne;
		//si colonne n'est pas un nombre
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Erreur : vous devez entrer un nombre" << std::endl;
		}
		
		colonne--; //car tableau commence à 0
		if (colonne >= 0 && colonne < 7)
		{
			for (int ligne = 3; ligne >= 0; ligne--)
			{
				if (grille[ligne][colonne] == " ")
				{												
					setCase(ligne, colonne, forme);				
					valide = true;								
					break;										
				}

			}
		}
		else
		{
			std::cout << "Cette colonne n'existe pas" << std::endl;
		}
	}
}

//retourne true si 4 cases alignées sont identiques
bool Puissance4::testeFinJeu(int joueur)
{
	//définition de la forme en fonction du joueur (pair X, impair O)
	string forme;
	if (joueur % 2 == 0) {
		forme = "X";
	}
	else {
		forme = "O";
	}

	//vérification des lignes
	for (int i = 0; i < 4; i++)//pour chaque ligne
	{
		for (int j = 0; j < 4; j++) //vérification de gauche à droite
		{
			if (grille[i][j] == forme && grille[i][j + 1] == forme && grille[i][j + 2] == forme && grille[i][j + 3] == forme)
			{
				std::cout << "Le joueur ayant les " << forme << " gagne !" << std::endl;
				return true;
			}
		}
	}

	//vérification des colonnes
	for (int i = 0; i < 7; i++)//pour chaque colonne
	{
		for (int j = 0; j < 1; j++) //vérification de haut en bas
		{
			if (grille[j][i] == forme && grille[j + 1][i] == forme && grille[j + 2][i] == forme && grille[j + 3][i] == forme)
			{
				std::cout << "Le joueur ayant les " << forme << " gagne !" << std::endl;
				return true;
			}
		}
	}

	//vérification des diagonales
	for (int i = 0; i < 4; i++)//pour chaque ligne
	{
		for (int j = 0; j < 4; j++)//de gauche à droite
		{
			if (grille[i][j] == forme && grille[i + 1][j + 1] == forme && grille[i + 2][j + 2] == forme && grille[i + 3][j + 3] == forme)
			{
				std::cout << "Le joueur ayant les " << forme << " gagne !" << std::endl;
				return true;
			}
		}
	}

	for (int i = 3; i < 7; i++)//pour les colonnes 3 à 7 (les 4 dernières)
	{
		for (int j = 0; j < 4; j++)//de gauche à droite
		{
			if (grille[i][j] == forme && grille[i - 1][j + 1] == forme && grille[i - 2][j + 2] == forme && grille[i - 3][j + 3] == forme)
			{
				std::cout << "Le joueur ayant les " << forme << " gagne !" << std::endl;
				return true;
			}
		}
	}

	if (joueur == 42) //si 42ieme tours : toutes les cases sont remplies
	{
		std::cout << "Match nul !" << std::endl;
		return true;
	}
	else
	{
		return false;
	}

	if (testeFinJeu(joueur))
	{
		std::cout << "Le joueur " << joueur << "  gagne !" << std::endl;
	}

	return false;
}