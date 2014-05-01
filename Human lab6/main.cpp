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

//Aby program dzia�a� poprawnie funkcje czysto wirtualne musz� by� zdefiniowane w klasach pochodnych (�eby mo�na by�o tworzy� ich obiekty)
//Stworzenie obiektu klasy abstrakcyjnej (tutaj Mama1) jest niemo�liwe.

//Klasa abstrakcyjna b�d�ca interfejsem ma tylko i wy��cznie metody czysto wirtualne i nie ma �adnych p�l.
//Jest to przydatne do udost�pniania takiego samego zestawu metod zupe�nie niezwi�zanym ze sob� obiektom. 