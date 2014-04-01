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
	cout<<Student::counting()<<endl; //obydwa zapytania zwracaj¹ tê sam¹ wartoœæ

	//Frank=Jane;
	//takie przypisanie jest mo¿liwe(obiektu klasy pochodnej do ob.kl. bazowej), skutkuje skopiowaniem zawartoœci wy³¹cznie zmiennych bazowych
	//Becky=Frank; -> generuje b³¹d, w obiekcie klasy bazowej jest wiêcej pól, które nie mog¹ pozostaæ czêœciowo niewype³nione

	system("pause");
	return 0;
}

//U¿ycie s³owa kluczowego protected lub private zamiast public(przy class Student : public Human) 
//ogranicza dostêpnoœæ metod klasy Human dla klasy Student.
//Na przyk³ad u¿ycie getterów generuje b³êdy jak ten: 'Human::get_gender' not accessible 
//because 'Student' uses 'private' to inherit from 'Human'

