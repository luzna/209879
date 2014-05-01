#include "stdafx.h"
#include "Student.h"
#include "Student2.h"
#include "Tutor.h"
#include <iostream>

int main()
{
	Human Frank;
	Student Jane(7, "female", "Jane", "Parker", 2, 748938, 2, "air", "W4", 5);
	Student Becky(7, "female", "Jane", "Philips", 3, 747292, 4, "mbm" , "W10", 6);
	Tutor Simon;
	Student2 Bob(25, "male", "Bob", "Harrison", 5, 102983, 3, "inf", "W4", 2, "inz.");

	cout<<Human::counting()<<endl;
	
	cout<<Frank;
	cout<<Jane;
	cout<<Becky;

	Frank.birthday();
	cout<<endl<<Jane.studying_time()<<endl;

	if(Jane==Becky)
		cout<<"operator== working properly\n\n";

	system("pause");
	return 0;
}

//Aby program dzia³a³ poprawnie funkcje czysto wirtualne musz¹ byæ zdefiniowane w klasach pochodnych (¿eby mo¿na by³o tworzyæ ich obiekty)
//Stworzenie obiektu klasy abstrakcyjnej (tutaj Mama1) jest niemo¿liwe.

//Klasa abstrakcyjna bêd¹ca interfejsem ma tylko i wy³¹cznie metody czysto wirtualne i nie ma ¿adnych pól.
//Jest to przydatne do udostêpniania takiego samego zestawu metod zupe³nie niezwi¹zanym ze sob¹ obiektom. 