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

//Destruktor powinien by� wirtualny, je�li korzystamy z publicznego dziedziczenia z danej klasy. 
//Wywo�uj�c wtedy destruktor obiektu klasy pochodnej wywo�amy destruktor dla ca�ego obiektu
//Gdyby destruktor nie by� wirtualny, to wywo�any by�by od razu destruktor owej klasy, kt�ry mo�e nie wzi�� pod uwag� 
//istnienia sk�adowych dodanych w klasie pochodnej.