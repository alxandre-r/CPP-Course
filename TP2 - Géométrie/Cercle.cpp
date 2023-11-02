#pragma once
#include "Cercle.h"
using namespace std;

//constructeur
Cercle::Cercle(int diametre, Point centre)
{
	this->diametre = diametre;
	this->centre = centre;
}

//constructuer par défaut
Cercle::Cercle()
{
	this->diametre = 10;
	this->centre = Point(0, 0);
}

//getters
inline int Cercle::get_diametre() const { return diametre; };
inline int Cercle::get_rayon() const { return diametre / 2; };
inline Point Cercle::get_centre() const { return centre; };

//setters
void Cercle::set_diametre(int a) { diametre = a; };
void Cercle::set_centre(Point a) { centre = a; };

//retourne le perimetre du cercle
inline double Cercle::get_perimetre() const
{
	return  3.14 * diametre;
}

//retourne l'aire du cercle
inline double Cercle::get_aire() const
{
	return 3.14 * diametre/2 * diametre/2;
}

//affiche les caractéristiques du cercle
void Cercle::affiche() const
{
	std::cout
		<< "Diametre : " << diametre << ", rayon : " << diametre / 2 << "\n"
		<< "Le perimetre du cercle est de " << get_perimetre() << "\n"
		<< "L'aire du cercle est de " << get_aire() << "\n"
		<< "Le centre du cercle est en abscisse " << centre.get_Abscisse() << " et ordonnee " << centre.get_Ordonnee() << "\n";
}

//determine si point est sur le cercle
bool Cercle::estSurLeCercle(Point point) const {

	//si la distance entre le centre et le point est égal au rayon :
	if (point.distance(centre) == diametre / 2) { 
		return true;
	}
	else {
		return false;
	}
}

//determine si point est dans le cercle
bool Cercle::estDansLeCercle(Point point) const {

	//si la distance entre le centre et le point est inferieur au rayon :
	if (point.distance(centre) < diametre / 2) {
		return true;
	}
	else {
		return false;
	}
}



