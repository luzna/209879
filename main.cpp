#include "stdafx.h"
#include "Class.h"
#include <iostream>

int main()
{
	Circle circle, circle_3; //counter=2
	
	location new_location={4.,2.};
	circle.set_location(new_location);
	circle.set_radius(15.);

	location new_location_1={3.,5.};
	Circle circle_1(new_location_1, 2.); //counter=3

	location new_location_2={11.,7.};
	Circle circle_2(new_location_2, 4.); //counter=4
	
	circle=circle+circle_1; //counter=2
	circle_3=circle_1+circle_2; //counter=0
	circle_3=circle_3*2; //counter=-1
	circle_2=circle*5; //counter=-2
						
	printf("Circle location is %.1fx%.1f.\n",
	circle.get_location(new_location).x, circle.get_location(new_location).y);
	printf("Circle radius is %.1f.\n",
	circle.get_radius());
	printf("Circle circumference is %.2f.\n",
	circle.circumference());
	printf("Circle area is %.2f.\n",
	circle.area());
 
	std::cout<<"existing objects: "<<Circle::counting()<<std::endl;

system("pause");
return 0;
}
