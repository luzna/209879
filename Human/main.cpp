#include "stdafx.h"
#include "Student.h"
#include "Tutor.h"
#include <iostream>

int main()
{
	int tab[10]; int (*wsk)[10]; wsk=&tab;

	Human Frank;
	Student Jane(7, "female", "Jane", "Parker", wsk, 748938, 2, "air", "W4");
	Student Becky;
	Tutor Simon;
	
	cout<<"OBIEKT JANE: "<<Jane.get_age()<<" "<<Jane.get_gender()<<" "<<Jane.get_name()<<" "<<Jane.get_surname()<<" "<<Jane.get_index()
		<<Jane.get_semester()<<" "<<Jane.get_major()<<" "<<Jane.get_faculty()<<" "<<Jane.get_ptr()<<endl;
	cout<<"OBIEKT BECKY: "<<Becky.get_age()<<endl;
	cout<<"OBIEKT SIMON: "<<Simon.get_surname()<<endl;

	cout<<Human::counting()<<endl;
	cout<<Student::counting()<<endl; //obydwa zapytania zwracaj� t� sam� warto��

	//Frank=Jane;
	//takie przypisanie jest mo�liwe(obiektu klasy pochodnej do ob.kl. bazowej), skutkuje skopiowaniem zawarto�ci wy��cznie zmiennych bazowych
	//Becky=Frank; -> generuje b��d, w obiekcie klasy bazowej jest wi�cej p�l, kt�re nie mog� pozosta� cz�ciowo niewype�nione

	system("pause");
	return 0;
}

//U�ycie s�owa kluczowego protected lub private zamiast public(przy class Student : public Human) 
//ogranicza dost�pno�� metod klasy Human dla klasy Student.
//Na przyk�ad u�ycie getter�w generuje b��dy jak ten: 'Human::get_gender' not accessible 
//because 'Student' uses 'private' to inherit from 'Human'

