#include "stdafx.h"
#include "Student.h"

Student::Student() : Human()
{
	this->index=0;
	this->semester=0;
	this->major="unknown";
	this->faculty="unknown";
}

Student::Student(int age, string gender, string name, string surname, int(*ptr)[10], int index, int semester, string major, string faculty) 
	: Human(age, gender, name, surname, ptr)
{
	this->index=index;
	this->semester=semester;
	this->major=major;
	this->faculty=faculty;
}

Student::~Student(){}

int Student::get_index()
{
	return index;
}

int Student::get_semester()
{
	return semester;
}

string Student::get_major()
{
	return major;
}

string Student::get_faculty()
{
	return faculty;
}

