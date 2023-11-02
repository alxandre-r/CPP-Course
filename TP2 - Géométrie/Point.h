#pragma once
#include <iostream>   
using namespace std;

struct Point
{
private:
	float x;
	float y;
	
public:
	//constructeur
	Point(float abscisses, float ordonnee);
	//constructeur par d�faut
	Point();
	
	//getters
	int get_Abscisse() const;
	int get_Ordonnee() const;

	//m�thodes
	void affiche() const;
	float distance(Point) const;
};

