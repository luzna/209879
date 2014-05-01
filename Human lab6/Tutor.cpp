#include "stdafx.h"
#include "Tutor.h"

Tutor::Tutor() : Human()
{
	this->title="unknown";
	this->number_of_publications=0;
}

Tutor::Tutor(int age, string gender, string name, string surname, int n, string title, int number_of_publications) : Human(age, gender, name, surname, n)
{
	this->title=title;
	this->number_of_publications=number_of_publications;
}

Tutor::~Tutor()
{
	counter--;
}

string Tutor::get_title()
{
	return title;
}

void Tutor::set_title(string title)
{
	this->title=title;
}

int Tutor::get_number_of_publications()
{
	return number_of_publications;
}

void Tutor::set_number_of_publications(int number_of_publications)
{
	this->number_of_publications=number_of_publications;
}
