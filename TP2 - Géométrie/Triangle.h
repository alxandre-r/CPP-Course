#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Triangle
{
private:
	Point pointA;
	Point pointB;
	Point pointC;
	
public:
	//constructeur
	Triangle(const Point point1, const Point point2, const Point point3);
	
	//constructeur par défaut
	Triangle();
	
	//getters
	inline Point get_pointA() const;
	inline Point get_pointB() const;
	inline Point get_pointC() const;

	//setters
	inline void set_pointA(Point a);
	inline void set_pointB(Point b);
	inline void set_pointC(Point c);

	//méthodes
	void affiche() const;
	
	inline float get_longueurAB() const;
	inline float get_longueurBC() const;
	inline float get_longueurCA() const;
	inline float get_perimetre() const;
	inline float get_aire() const;
	inline float get_hauteur() const;

	float get_base() const;

	bool estEquilateral() const;
	bool estIsocele() const;
	void affiche_type(Triangle) const;
};
	
