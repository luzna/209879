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
	this->ptr=NULL;

	counter++;
}

Human::Human(int age, string gender, string name, string surname, int(*ptr)[10]) : ptr(ptr)
{
	this->age=age;
	this->gender=gender;
	this->name=name;
	this->surname=surname;
	
	counter++;
}

Human::~Human()
{
	counter--;
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

void Human::set_ptr(int (*ptr)[10])
{
	this->ptr=ptr;
}

int* Human::get_ptr()
{
	return *ptr;
}