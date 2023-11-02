#include "MainMethods.h"
#include "Morpion.h"
#include "Puissance4.h"
#include "Jeu.h"
using namespace std;


/******** MAIN *********/

int main()
{
	//declration des variables
	int nbJoueurs = 0;
	string formeJoueur = "null";
	int joueur = 0;
	string formeOrdinateur = "null";
	int ordinateur = 0;
	
	//choix jeu solo ou à deux
	std::cout << "Combien de joueurs ? (1 ou 2)" << endl;
	std::cin >> nbJoueurs;
	isNbJoueurInt1or2(nbJoueurs);
	
	//choix morpion ou puissance 4
	int choixJeu = 0;
	std::cout << "Choisissez votre jeu : 1 pour Morpion, 2 pour Puissance 4" << endl;
	std::cin >> choixJeu;
	isNbJoueurInt1or2(nbJoueurs);

	if (choixJeu == 1)
	{
		Morpion morpion;
		
		//si jeu 1 joueur
		if (nbJoueurs == 1) {
			morpion.jouerSolo(joueur);
		}
	
		//si jeu 2 joueurs
		else if (nbJoueurs == 2) {
			morpion.jouerDuo(joueur);
		}
		//grille de fin
		morpion.afficherGrille();
		
	} //fin morpion

	else if (choixJeu == 2)
	{
		Puissance4 puissance4;

		//si jeu 1 joueur
		if (nbJoueurs == 1) {
			puissance4.jouerSolo(joueur);
		}
		
		//si jeu 2 joueurs
		else if (nbJoueurs == 2) {
			puissance4.jouerDuo(joueur);
		}
		
		//grille de fin
		puissance4.afficherGrille();
	}

	//sortie du programme après la fin de la partie
	std::cout << "Appuyer sur Entrer pour terminer" << endl;
	std::cin.ignore();
	std::cin.get();
	
}//fin main
