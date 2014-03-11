#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 

struct location
{
	float x,y;
};


class Circle
{

private:
	location location;
	float radius;

public:
	void set_location(float x, float y)
	{
		location.x=x;
		location.y=y;
	}
		
	float get_locationx()
	{
		return location.x;
	}

	float get_locationy()
	{
		return location.y;
	}

	void set_radius(float rad)
	{
		radius=rad;
	}

	 float get_radius()
	{
		return radius;
	}

	 float circumference()
	{
		return 2 * M_PI * radius;
	}

	float area()
	{
		return M_PI * pow(radius,2);
	}
};

int main()
{
	Circle circle;
	circle.set_location(4., 2.);
	circle.set_radius(15.);

	printf("Circle location is %.1fx%.1f.\n",
	circle.get_locationx(), circle.get_locationy());
	printf("Circle radius is %.1f.\n",
	circle.get_radius());
	printf("Circle circumference is %.2f.\n",
	circle.circumference());
	printf("Circle area is %.2f.\n",
	circle.area());
    

system("pause");
}

//TEST WIDOCZNO�CI 
//Przy odwo�ywaniu si� do zadeklarowanej wg instrukcji zmiennej z klasy Circle kompilator wyrzuca b��d tre�ci:
//'float Circle::radius Error:member "Circle::radius" (declared at line 24) is inaccessible'
//Wnioskuj� st�d, �e z poziomu funkcji main nie mamy dost�pu do wy�ej wymienionej zmiennej.

//PUBLICZNE METODY
//Pobieramy i ustawiamy dane w klasie przy u�yciu publicznych metod, 
//aby m�c zachowa� sam� struktur� danych niedost�pn� dla nieuprawnionych funkcji i nie dopu�ci� do jej 'zepsucia'.