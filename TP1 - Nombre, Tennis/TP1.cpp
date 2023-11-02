// TP1.cpp : définit le point d'entrée de l'application.
#include "TP1.h"
#include <string> 
#include <chrono>
#include <thread>


using namespace std;

bool setIsWin = false;

//multiplie une valeur par une autre et retourne le résultat
int SommeDeuxInt(int nbr1, int nbr2) 
{
	return nbr1 + nbr2;
}
//inverse les valeurs de deux variables
void Inverser(int& nbr1, int& nbr2)
{
	int temp = nbr1;
	nbr1 = nbr2;
	nbr2 = temp;
}
//remplace une troisième valeur par la somme des deux premières avec des références
void ReplaceThirdBySumRef(int nbr1, int nbr2, int& nbr3) 
{
	nbr3 = nbr1 + nbr2;
}
//remplace une troisième valeur par la somme des deux premières avec des pointeurs
void ReplaceThirdBySumPointers(int nbr1, int nbr2, int* nbr3)
{
	*nbr3 = nbr1 + nbr2;
}
//affiche un tableau
void afficher(int array[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}
	std::cout << std::endl;
}
//rend aléatoire un tableau
void rendreAleatoire(int array[]) 
{
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
	}
}
//trie un tableau
void trier(int* array)
{
	int temp;
	for (int i = 0; i < 10; i++)					//pour chaque nombre
	{
		for (int j = 0; j + 1 < 10 - i; j++)		//tant que j+1 est plus petit que 10 - le nombre
		{

			if (array[j] > array[j + 1])			//si le nombre est plus grand que celui qui suit
			{
				Inverser(array[j], array[j + 1]);	//inverser
			}
		}
	}
}

//attribue des points au joueur gagnant selon certaines conditions, retourne true s'il y a un gagnant du set
bool getPoint(int joueur, int* J1, int* J2) 
{
	//pour plus de visibilité lors du jeu, possibilité d'attendre entre chaque échange
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	//si les points du joueur sont inférieur à 30 :
	if (*J1 < 30)
	{
		//+15 points au joueur
		*J1 = *J1 + 15;
		std::cout << "Joueur " << joueur << " gagne l'echange, total de points: " << *J1 << std::endl;
	}


	// sinon si points du joueur = 30 :
	else if (*J1 == 30) 
	{
		//+10 points au joueur
		*J1 = *J1 + 10;
		std::cout << "Joueur " << joueur << " gagne l'echange, total de points: " << *J1 << std::endl;
	}


	//si points joueur == 40 et autre joueur non, joueur 1 gagne le set 
	else if (*J1 == 40 && *J2 < 40)
	{
		//retourne true pour indiquer à la fonction Echange qu'il y a un vainqueur
		return true;
	}


	//si 40 partout
	else if (*J1 == 40 && *J2 == 40)
	{
		std::cout << "Joueur " << joueur << " gagne l'echange, 40 avantage" << std::endl;
		//donne l'avantage au gagnat de l'échange
		*J1 += 1;
	}


	//si point joueur == 40 et autre joueur a avantage
	else if (*J1 == 40 && *J2 > 40)
	{
		std::cout << "Joueur " << joueur << " gagne l'echange, 40 avantage" << std::endl;
		//donne l'avantage au joueur
		*J1 +=1 ;
		//retire l'avantage au deuxieme joueur
		*J2 = 40;
	}


	//si gagnat de l'échange à l'avantage :
	else if (*J1 == 41)
	{
		//joueur vainqueur
		return true;
	}
	//sinon erreur
	else
	{
		std::cout << "erreur " << std::endl;
	}
}
//simule un echange
void TennisEchange(int* J1, int* J2)  
{
	//défini un gagnant de l'échange aléatoire (1 ou 2)
	int win = (rand() % 2) +1;	

	//si gagnant est joueur 1
	if (win == 1) 
	{
		//si joueur 1 deviens gagnant du set
		if (getPoint(1, J1, J2) == true) {
			std::cout << "Joueur " << 1 << " gagne l'echange : il gagne le set" << std::endl;
			//arrêt boucle while
			setIsWin = true; 
			return;
		}
		//sinon joueur 1 getPoint
		else { getPoint(1, J1, J2); }			
	}
	//si gagnant est joueur 2
	else 
	{
		//si joueur 2 deviens gagnant du set
		if (getPoint(2, J2, J1) == true) {
			std::cout << "Joueur " << 2 << " gagne l'echange : il gagne le set" << std::endl;
			//arrêt boucle while
			setIsWin = true; 
			return;
		} 
		//sinon joueur 2 getPoint
		else { getPoint(2, J2, J1); }
	}
}




int main()
{
	//graine pour aléatoire
	std::srand(std::time(nullptr));

	int nbr1 = 1;
	int nbr2 = 2;
	int nbr3 = 10;
	int* nbr3p = &nbr3;

	//I.1.1
	std::cout <<"La somme de "<<nbr1<<" et de "<<nbr2<<" est " << SommeDeuxInt(nbr1, nbr2) << "\n";

	//I.1.2
	std::cout <<"Avant inversement : " << nbr1 << " " << nbr2 << "\n";
	Inverser(nbr1, nbr2);
	std::cout << "Apres inversement : " << nbr1 <<" "<< nbr2 << "\n";
	Inverser(nbr1, nbr2);

	//I.1.3 références
	std::cout << "Avant remplacement : " << nbr1 << " " << nbr2 << " " << nbr3 << "\n";
	ReplaceThirdBySumRef(nbr1, nbr2, nbr3);

	//I.1.3 pointeurs (enlever les commentaires pour tester et mettre en commentaire la précédente)
	//ReplaceThirdBySumPointers(nbr1, nbr2, nbr3p);
	std::cout << "Apres remplacement : " << nbr1 << " " << nbr2 << " " << nbr3 << std::endl;
	std::cout << std::endl;

	//I.1.4
	int tableau[10];

	std::cout << "Tableau : \n";
	rendreAleatoire(tableau);
	afficher(tableau);

	trier(tableau);
	std::cout << "\nTableau trie : \n";
	afficher(tableau);

	std::cout << std::endl;


	//II. Tennis

	int j1 = 0;	//declaration variable int
	int* J1;	//declaration pointeur
	J1 = &j1;	//liaison pointeur à l'adresse de j1

	int j2 = 0;
	int* J2;
	J2 = &j2;

	while (setIsWin == false) {
		TennisEchange(J1, J2);
	}

	//III.1 Bonus
	string entree; 
	std::cout << "Entre ton prenom ET ton nom: "; 
	getline(cin, entree);								//ligne input = entree

	//mot du début jusqu'à espace
	string prenom = entree.substr(0, entree.find(" "));
	//première lettre en majuscule
	prenom[0] = toupper(prenom[0]);						

	//mot de fin prenom jusqu'à fin entree
	string nom = entree.substr(prenom.length(), entree.length()-1);
	//en majuscule
	std::transform(nom.begin(), nom.end(), nom.begin(), ::toupper);	

	std::cout << "Bonjour " << prenom << nom << endl;

	//III.2
	int essai;
	int nbr_essai = 1;

	std::cout << "Essayer de deviner le nombre entre 0 et 1000 " << endl;
	int nombre_aleatoire = rand() % 1000;
	cin >> essai;

	while (essai != nombre_aleatoire) {
		if (essai < nombre_aleatoire) {
			nbr_essai +=1;
			std::cout << "C'est plus " << endl;
			cin >> essai;
		}

		if (essai > nombre_aleatoire) {
			nbr_essai +=1;
			std::cout << "C'est moins " << endl;
			cin >> essai;
		}
	}
	std::cout << "Felicitation, le nombre etait bien " << nombre_aleatoire << ", tu as reussi en " << nbr_essai << " essais." << endl;

	
}