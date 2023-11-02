#include <iostream>
#include "Point.h"
using namespace std;

//Constructeur
Point::Point(float abscisses,float ordonnee) {
	x = abscisses;
	y = ordonnee;
}

//Constructeur par defaut
Point::Point() {
	x = 5;
	y = 10;
}

//getters
int Point::get_Abscisse() const { return x; };
int Point::get_Ordonnee() const { return y; };

//affiche les coordonnées du point
void Point::affiche() const
{
	std::cout << "Le point est en abscisse " << x << " et ordonee " << y << "\n";
}

//calcul la distance entre deux point
float Point::distance(Point point) const 
{
	float distance = sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
	return distance;
}