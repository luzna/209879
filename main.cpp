#include "stdafx.h"
#include "Class.h"

int main()
{
	Circle circle, circle_3;
	
	location new_location={4.,2.};
	circle.set_location(new_location);
	circle.set_radius(15.);

	location new_location_1={3.,5.};
	Circle circle_1(new_location_1, 2.);

	location new_location_2={11.,7.};
	Circle circle_2(new_location_2, 4.);
	
	circle=circle+circle_1;
	circle_3=circle_1+circle_2;
	circle_3=circle_3*2;
	circle_2=circle*5;

	printf("Circle location is %.1fx%.1f.\n",
	circle.get_locationx(), circle.get_locationy());
	printf("Circle radius is %.1f.\n",
	circle.get_radius());
	printf("Circle circumference is %.2f.\n",
	circle.circumference());
	printf("Circle area is %.2f.\n",
	circle.area());
 
	Circle::counting();

system("pause");
return 0;
}

//Klasa Circle nie potrzebuje destruktora, poniewa¿ nie ma dzia³añ koniecznych do wykonania przed niszczeniem obiektów tej klasy.

//Zmienne i funkcje statyczne mog¹ mieæ zastosowanie, gdy obiekty danej klasy posiadaj¹ jak¹œ wspóln¹ cechê, która mo¿e ulegaæ zmianie, 
//nie trzeba wówczas dokonywaæ poprawek w ka¿dym obiekcie po kolei. Same zmienne statyczne mog¹ równie¿ pos³u¿yæ do przechowywania 
//bardzo d³ugich nazw klas, których obiektów jest wiele, aby nazwy te pojawia³y siê w pamiêci tylko raz. 