#include "stdafx.h"
#include "Human.h"

int Human::counter=0;

int Human::counting()
{
	return counter;
}

Human::Human()
{
	this->age=0;
	this->gender="unknown";
	this->name="unknown";
	this->surname="unknown";

	counter++;
}

Human::Human(int age, string gender, string name, string surname, int n)
{
	this->age=age;
	this->gender=gender;
	this->name=name;
	this->surname=surname;
	this->favorite_books = new string[n];
	
	counter++;
}

Human::~Human()
{
	favorite_books=0;
	delete [] favorite_books;
	
	counter--;
}

ostream& operator<<(ostream& out, Human &A)
{
	out <<endl
		<<A.age
		<<A.gender
		<<A.name
		<<A.surname<<endl;

	return out;
}

istream& operator>>(istream& in, Human &A)
{
	in >>A.age>>A.gender>>A.name>>A.surname;

	return in;
}

void Human::set_age(int age)
{
	this->age=age;
}

int Human::get_age()
{
	return age;
}

void Human::set_gender(string gender)
{
	this->gender=gender;
}

string Human::get_gender()
{
	return gender;
}

void Human::set_name(string name)
{
	this->name=name;
}

string Human::get_name()
{
	return name;
}

void Human::set_surname(string surname)
{
	this->surname=surname;
}

string Human::get_surname()
{
	return surname;
}

void Human::birthday() 
{
	cout<<get_age()+1<<" birthday coming"<<endl;
}

int Human::studying_time()
{
	return 0;
}