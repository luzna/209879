#include "stdafx.h"
#include "Tutor.h"

Tutor::Tutor() : Human()
{
	this->title="unknown";
	this->number_of_publications=0;
}

Tutor::Tutor(int age, string gender, string name, string surname, int(*ptr)[10], string title, int number_of_publications) : Human(age, gender, name, surname, ptr)
{
	this->title=title;
	this->number_of_publications=number_of_publications;
}

Tutor::~Tutor(){}

string Tutor::get_title()
{
	return title;
}

int Tutor::get_number_of_publications()
{
	return number_of_publications;
}