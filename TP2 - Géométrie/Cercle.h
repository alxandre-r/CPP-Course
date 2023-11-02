#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Cercle
{	
private:
	int diametre;
	Point centre;
	
public:
	//constructeur
	Cercle(int diametre, Point centre);
	//constructeur par défaut
	Cercle();
	
	//getters
	inline int get_diametre() const;
	inline int get_rayon() const;
	inline Point get_centre() const;

	//setters
	void set_diametre(int a);
	void set_centre(Point a);

	//méthodes
	inline double get_perimetre() const;
	inline double get_aire() const;

	bool estSurLeCercle(Point) const;
	bool estDansLeCercle(Point) const;
	
	void affiche() const;
};

