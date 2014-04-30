#include "stdafx.h"
#include "Student.h"
#include "Tutor.h"
#include <iostream>

int main()
{
	int tab[10]; int (*wsk)[10]; wsk=&tab;

	Human Frank;
	Student Jane(7, "female", "Jane", "Parker", wsk, 2, 748938, 2, "air", "W4", 5);
	Student Becky(5, "female", "Becky", "Philips", wsk, 3, 747292, 4, "mbm" , "w10", 6);
	Tutor Simon;
	
	cout<<Human::counting()<<endl;
	
	cout<<Frank;
	cout<<Jane;

	Frank.birthday();
	cout<<Jane.studying_time();

	system("pause");
	return 0;
}

//Aby program dzia³a³ poprawnie funkcje czysto wirtualne musz¹ byæ zdefiniowane w klasach pochodnych (¿eby mo¿na by³o tworzyæ ich obiekty)
//Stworzenie obiektu klasy abstrakcyjnej (tutaj Mama1) jest niemo¿liwe.

//Klasa abstrakcyjna bêd¹ca interfejsem ma tylko i wy³¹cznie metody czysto wirtualne i nie ma ¿adnych pól.
//Jest to przydatne do udostêpniania takiego samego zestawu metod zupe³nie niezwi¹zanym ze sob¹ obiektom. 