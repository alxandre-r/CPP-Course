#include "Morpion.h"
using namespace std;

//constructeur
Morpion::Morpion() : Jeu()
{
	//création d'une grille 3x3 remplie d'espaces
	for (int ligne = 0; ligne < 3; ligne++)
	{
		for (int colonne = 0; colonne < 3; colonne++)
		{
			grille[ligne][colonne] = " ";
		}
	}
}

//jeu 1 joueur
void Morpion::jouerSolo(int joueur) {

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
		//sinon fin du jeu
		else {
			break;
		}
	} while (!testeFinJeu(joueur));
}

//pour jeu 1 joueur
void Morpion::nouveauTourSolo(string forme) {
	//la forme choisie en amont est entrée en paramètre
	placerForme(forme);
}

void Morpion::TourOrdinateur(string forme) {
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

	//l'ordinateur place sa forme dans une case aléatoire
	do{
		colonne = rand() % 7;
		ligne = rand() % 4;
		
		//si la case est vide
		if (grille[ligne][colonne] == " ") {
			//on place la forme
			grille[ligne][colonne] = forme;
			estVide = true;
			break;
		}
	} while (!estVide);
}

//jeu 2 joueurs
void Morpion::jouerDuo(int joueur) {
	do {
		joueur += 1; //alterne entre joueur X (pair) et joueur O (impair)
		nouveauTour(joueur);
		clear();
	} while (!testeFinJeu(joueur));
}

//pour jeu 2 joueurs
void Morpion::nouveauTour(int joueur)
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
void Morpion::afficherGrille() const
{
	std::cout << std::endl << "     -------------" << std::endl << "     ";
	for (int ligne = 0; ligne < 3; ligne++)
	{
		for (int colonne = 0; colonne < 3; colonne++)
		{
			std::cout << "| " << grille[ligne][colonne] << " ";
		}

		std::cout << "|" << std::endl << "     -------------" << std::endl;
		std::cout << "     ";
	}
}

//vérifie que la case soit bien rempli de " "
bool Morpion::caseVide(int ligne, int colonne) const
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
bool Morpion::setCase(int ligne, int colonne, string valeur)
{
	if (grille[ligne][colonne] == " ")
	{
		grille[ligne][colonne] = valeur;
		return true;
	}
	else {
		std::cout << "[setCase] Erreur lors de l'assignation de la valeur : la case n'est pas vide" << std::endl;
		return false;
	}
}

//place une forme dans une case vide entrée par le joueur
void Morpion::placerForme(string forme) {
	
	bool choixOK = false;
	string choix;
	string stringforme;
	
	//pour affichage
	if (forme == "X") {
		stringforme = "Croix";
	}
	else {
		stringforme = "Rond";
	}
	
	//affichage
	afficherGrille();
	std::cout << std::endl << "Choississez une case pour y placer votre " << stringforme << " (1 - 9)" << std::endl;
	std::cin >> choix;
	
	//setCase selon numéro de case entrée par le joueur
	do
	{
		if (choix == "1" && caseVide(0, 0)) {
			choixOK = true;
			setCase(0, 0, forme);
		}
		else if (choix == "2" && caseVide(0, 1)) {
			choixOK = true;
			setCase(0, 1, forme);
		}
		else if (choix == "3" && caseVide(0, 2)) {
			choixOK = true;
			setCase(0, 2, forme);
		}
		else if (choix == "4" && caseVide(1, 0)) {
			choixOK = true;
			setCase(1, 0, forme);
		}
		else if (choix == "5" && caseVide(1, 1)) {
			choixOK = true;
			setCase(1, 1, forme);
		}
		else if (choix == "6" && caseVide(1, 2)) {
			choixOK = true;
			setCase(1, 2, forme);
		}
		else if (choix == "7" && caseVide(2, 0)) {
			choixOK = true;
			setCase(2, 0, forme);
		}
		else if (choix == "8" && caseVide(2, 1)) {
			choixOK = true;
			setCase(2, 1, forme);
		}
		else if (choix == "9" && caseVide(2, 2)) {
			choixOK = true;
			setCase(2, 2, forme);
		}
		//test choix
		else
		{
			std::cout << "Choix invalide, veuillez choisir une case entre 1 et 9 vide" << std::endl;
			std::cin >> choix;
		}
	} while (!choixOK);
}

//retourne true si 3 cases alignées sont identiques
bool Morpion::testeFinJeu(int joueur)
{
	string forme;
	if (joueur % 2 == 0) {
		forme = "X";
	}
	else {
		forme = "O";
	}
	
	bool Fin = false;

	//test de victoire
	if (grille[0][0] == forme && grille[0][1] == forme && grille[0][2] == forme) {
		Fin = true;
	}
	else if (grille[1][0] == forme && grille[1][1] == forme && grille[1][2] == forme) {
		Fin = true;
	}
	else if (grille[2][0] == forme && grille[2][1] == forme && grille[2][2] == forme) {
		Fin = true;
	}
	else if (grille[0][0] == forme && grille[1][0] == forme && grille[2][0] == forme) {
		Fin = true;
	}
	else if (grille[0][1] == forme && grille[1][1] == forme && grille[2][1] == forme) {
		Fin = true;
	}
	else if (grille[0][2] == forme && grille[1][2] == forme && grille[2][2] == forme) {
		Fin = true;
	}
	else if (grille[0][0] == forme && grille[1][1] == forme && grille[2][2] == forme) {
		Fin = true;
	}
	else if (grille[0][2] == forme && grille[1][1] == forme && grille[2][0] == forme) {
		Fin = true;
	}
	//si grille remplie
	else if (grille[0][0] != " " && grille[0][1] != " " && grille[0][2] != " " && grille[1][0] != " " && grille[1][1] != " " && grille[1][2] != " " && grille[2][0] != " " && grille[2][1] != " " && grille[2][2] != " ") {
		std::cout << std::endl << "Match nul ! " << std::endl;
	}
	else {
		Fin = false;
	}

	if (Fin) {
		afficherGrille();	
		std::cout << std::endl << "Le joueur ayant les " << forme << " gagne !" << std::endl;
	}
	return Fin;
}
