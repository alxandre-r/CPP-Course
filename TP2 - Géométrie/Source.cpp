#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Cercle.h"
#include "Triangle.h"
using namespace std;

int main(void) {

	std::cout << "\n\n========================= I.POINT ET II.RECTANGLE ===========================\n\n";

	//création et affichage d'un point
	Point a(6.0f, 4.0f);
	a.affiche();

	std::cout << "\n------------ rectangle 1 ------------\n";
	//création rectangle 1 et affichage caractéristiques
	Point b(0.0f, 6.0f);
	Rectangle rectangle1(2, 6, b);
	rectangle1.affiche();

	//II.3 Bonus
	std::cout << "\n------------ rectangle 2 ------------\n";
	//création rectangle 2 et affichage caractéristiques
	Point c(0.0f, 2.0f);
	Rectangle rectangle2(3, 2, c);
	rectangle2.affiche();


	std::cout << "\n--------------- Bonus ---------------\n";
	//affiche le quel triangle a le plus grand perimetre
	if (rectangle1.aPlusGrandPerimetre(rectangle2) == true) {
		std::cout << "Le rectangle 1 a le plus grand perimetre \n";
	}
	else
	{
		std::cout << "Le rectangle 2 a le plus grand perimetre \n";
	}

	//affiche quel triangle a la plus grande aire
	if (rectangle1.aPlusGrandeAire(rectangle2) == true) {
		std::cout << "Le rectangle 1 a la plus grande aire \n";
	}
	else
	{
		std::cout << "Le rectangle 2 a la plus grande aire \n";
	}

	std::cout << "\n\n================================ III.CERCLE ==================================\n\n";

	std::cout << "-------------- Cercle1 --------------\n";

	//création et affichage du point centre
	Point centreCercle1(0.0f, 0.0f);
	std::cout << "\n";

	//création et affichage d'un cercle et de ses spécifications
	Cercle cercle1(10, centreCercle1);
	cercle1.affiche();
	std::cout << "\n";

	std::cout << "-------- Point sur le cercle --------\n";
	//création d'un point test
	Point surCercle(0.0f, 5.0f);

	//affiche si le point se trouve sur le cercle
	if (cercle1.estSurLeCercle(surCercle) == true)
	{
		std::cout << "Le point est sur le cercle \n";
	}
	else
	{
		std::cout << "Le point n'est pas sur le cercle \n";
	}
	std::cout << "\n";

	std::cout << "-------- Point dans le cercle -------\n";
	//création d'un point test
	Point dansCercle(1.0f, 1.0f);

	//affiche si le point se trouve dans le cercle
	if (cercle1.estDansLeCercle(dansCercle) == true)
	{
		std::cout << "Le point est dans le cercle \n";
	}
	else
	{
		std::cout << "Le point n'est pas dans le cercle \n";
	}

	std::cout << "\n\n=============================== IV.TRIANGLE =================================\n";
	
	std::cout << "\n-------- Triangle equilateral --------\n";
	//création des points du triangle
	Point point2A(1.0f, 2.0f);
	Point point2B(5.0f, 4.0f);
	Point point2C(3 - sqrt(3), 3 + 2 * sqrt(3));
	
	//création et affichage du triangle
	Triangle triangle2(point2A, point2B, point2C);
	triangle2.affiche();
	//affiche le type de triangle
	triangle2.affiche_type(triangle2);

	std::cout << "\n---------- Triangle Isocele ----------\n";
	//création des points du triangle
	Point point1A(0.0f, 0.0f);
	Point point1B(0.0f, 5.0f);
	Point point1C(5.0f, 0.0f);

	//création et affichage du triangle
	Triangle triangle1(point1A, point1B, point1C);
	triangle1.affiche();
	//affiche le type de triangle
	triangle1.affiche_type(triangle1);


	std::cout << "\n--------- Triangle quelconque --------\n";
	//création des points du triangle
	Point point3A(5.0f, 0.0f);
	Point point3B(0.0f, 6.0f);
	Point point3C(1.0f, 1.0f);

	//création et affichage du triangle
	Triangle triangle3(point3A, point3B, point3C);
	triangle3.affiche();
	//affiche le type de triangle
	triangle3.affiche_type(triangle3);
	
}