#pragma once
#include "Rectangle.h"
using namespace std;

//constructeur
Rectangle::Rectangle(const int longueur,const int largeur, const Point supGauche) 
{
	this->longueur = longueur;
	this->largeur = largeur;
	this->supGauche = supGauche;
}

//constructeur par défaut
Rectangle::Rectangle()
{
	this->longueur = 10;
	this->largeur = 10;
	this->supGauche = Point(0, 0);
}

//getters 
inline int Rectangle::get_longueur() const { return longueur; }
inline int Rectangle::get_largeur() const { return largeur; }
inline Point Rectangle::get_PointSupGauche() const { return supGauche; }

//setters
void Rectangle::set_Longueur(float a) { longueur = a; };
void Rectangle::set_Largeur(float a) { largeur = a; };
void Rectangle::set_PointSupGauche(Point a) { supGauche = a; };

//retourne le perimetre du rectangle
inline double Rectangle::get_perimetre() const
{
	return 2 * (longueur + largeur);
}

//retourne l'aire du rectangle
inline double Rectangle::get_aire() const
{
	return longueur * largeur;
}

//affiche coordonnées point supérieur gauche du rectangle
inline void Rectangle::affiche_PointSupGauche() const
{ 
	std::cout << "Le point superieur gauche est en abscisse " << supGauche.get_Abscisse() << " et ordonee " << supGauche.get_Ordonnee() << "\n"; 
}

//affiche les caractéristiques du rectangle
void Rectangle::affiche() const
{
	std::cout 
		<< "Longueur : " << longueur << ", largeur : " << largeur << "\n"
		<< "Le perimetre du rectangle est de " << get_perimetre() << "\n" 
		<< "L'aire du rectangle est de " << get_aire() << "\n"
		<< "Le point superieur gauche est en abscisse " << supGauche.get_Abscisse() << " et ordonee " << supGauche.get_Ordonnee() << "\n";
}

//retourne true si perimètre du rectangle en paramètre est plus grand
bool Rectangle::aPlusGrandPerimetre(Rectangle rectangle) const 
{
	if (get_perimetre() > rectangle.get_perimetre()) {
		return true;
	}
	else
	{	
		return false;
	}
}
//retourne true si l'aire du rectangle en paramètre est plus grand
bool Rectangle::aPlusGrandeAire(Rectangle rectangle) const 
{
	if (get_aire() > rectangle.get_aire()) {
		return true;
	}
	else
	{
		return false;
	}
}
