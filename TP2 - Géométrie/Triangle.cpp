#include <iostream>
//fichier d'en-tête correspondant
#include "Triangle.h"
using namespace std;

//constructeur
Triangle::Triangle(const Point a, const Point b, const Point c)
{
	this->pointA = a;
	this->pointB = b;
	this->pointC = c;
}

//constructeur par défaut
Triangle::Triangle()
{
	this->pointA = Point(0, 10);
	this->pointB = Point(0, 0);
	this->pointC = Point(10, 0);
}

//getters
inline Point Triangle::get_pointA() const  { return pointA; };
inline Point Triangle::get_pointB() const  { return pointB; };
inline Point Triangle::get_pointC() const  { return pointC; };

//setters
inline void Triangle::set_pointA(Point a) { pointA = a; };
inline void Triangle::set_pointB(Point a) { pointB = a; };
inline void Triangle::set_pointC(Point a) { pointC = a; };

//affiche les caractéristiques du triangle
void Triangle::affiche() const
{
	std::cout << "AB = " << get_longueurAB() << "\n"
		<< "BC = " << get_longueurBC() << "\n"
		<< "CA = " << get_longueurCA() << "\n"
		<< "Sa base est donc de " << get_base() << "\n"
		<< "Son aire est de " << get_aire() << "\n"
		<< "Sa hauteur est de " << get_hauteur() << "\n";
}

//retourne la longueur AB
inline float Triangle::get_longueurAB() const {return pointA.distance(pointB);}
//retourne la longueur BC
inline float Triangle::get_longueurBC() const {return pointB.distance(pointC);}
//retourne la longueur CA
inline float Triangle::get_longueurCA() const {return pointC.distance(pointA);}

//retourne le périmètre du triangle
inline float Triangle::get_perimetre() const
{
	return get_longueurAB() + get_longueurBC() + get_longueurCA();
}

//retourne l'aire du triangle
inline float Triangle::get_aire() const
{
	//formule de Héron
	float p = get_perimetre() / 2;
	return sqrt(p * (p - get_longueurAB()) * (p - get_longueurBC()) * (p - get_longueurCA()));
}

//retourne la hauteur du triangle
inline float Triangle::get_hauteur() const
{
	return get_aire() / (get_base() / 2);

}

//retourne la plus grande distance entre deux point
float Triangle::get_base() const
{
	float distanceAB = pointA.distance(pointB);
	float distanceAC = pointA.distance(pointC);
	float distanceBC = pointB.distance(pointC);

	if (distanceAB > distanceAC && distanceAB > distanceBC)
	{
		return distanceAB;
	}
	else if (distanceAC > distanceAB && distanceAC > distanceBC)
	{
		return distanceAC;
	}
	else
	{
		return distanceBC;
	}
}

//retourne true si le triangle est equilatéral
bool Triangle::estEquilateral() const
{
	if (get_longueurAB() == get_longueurBC() && get_longueurAB() == get_longueurCA())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//retourne true si le triangle est isocèle
bool Triangle::estIsocele() const
{
	if (get_longueurAB() == get_longueurBC() || get_longueurAB() == get_longueurCA() || get_longueurBC() == get_longueurCA())
	{
		return true;
	}
	else
	{
		return false;;
	}
}

//affiche de quel type est le triangle entrée en paramètres
void Triangle::affiche_type(Triangle a) const {
	{
		if (a.estEquilateral())
		{
			std::cout << "Le triangle est equilateral\n";
		}
		else if (a.estIsocele())
		{
			std::cout << "Le triangle est isocele\n";
		}
		else
		{
			std::cout << "Le triangle est quelconque\n";
		}
	}
}