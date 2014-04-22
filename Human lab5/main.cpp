#include "stdafx.h"
#include "Student.h"
#include "Tutor.h"
#include <iostream>

int main()
{
	int tab[10]; int (*wsk)[10]; wsk=&tab;

	Human Frank;
	Student Jane(7, "female", "Jane", "Parker", wsk, 2, 748938, 2, "air", "W4", 5);
	Student Becky;
	Tutor Simon;
	
	cout<<Human::counting()<<endl;
	
	cout<<Frank;
	cout<<Jane;

	system("pause");
	return 0;
}

//Destruktor powinien byæ wirtualny, jeœli korzystamy z publicznego dziedziczenia z danej klasy. 
//Wywo³uj¹c wtedy destruktor obiektu klasy pochodnej wywo³amy destruktor dla ca³ego obiektu
//Gdyby destruktor nie by³ wirtualny, to wywo³any by³by od razu destruktor owej klasy, który mo¿e nie wzi¹æ pod uwagê 
//istnienia sk³adowych dodanych w klasie pochodnej.