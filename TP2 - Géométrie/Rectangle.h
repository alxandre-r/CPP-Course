#pragma once
#include <iostream> 
#include "Point.h"
using namespace std;

class Rectangle
{
private:
	int longueur;
	int largeur;
	Point supGauche;

public:
	//constructeur
	Rectangle(const int longueur, const int largeur, const Point supGauche);
	//constructeur par défaut
	Rectangle();
	
	//getters 
	inline int get_longueur() const;
	inline int get_largeur() const;
	inline Point get_PointSupGauche() const;
	
	//setters
	void set_Longueur(float a);
	void set_Largeur(float a);
	void set_PointSupGauche(Point a);

	//méthodes
	inline double get_perimetre() const;
	inline double get_aire() const;
	
	inline void affiche_PointSupGauche() const;

	bool aPlusGrandPerimetre(Rectangle) const;
	bool aPlusGrandeAire(Rectangle) const;

	void affiche() const;
};