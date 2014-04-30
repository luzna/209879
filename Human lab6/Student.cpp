#include "stdafx.h"
#include "Student.h"

Student::Student() : Human()
{
	this->index=0;
	this->semester=0;
	this->major="unknown";
	this->faculty="unknown";
}

Student::Student(int age, string gender, string name, string surname, int(*ptr)[10], int n, int index, int semester, string major, string faculty, int m) 
	: Human(age, gender, name, surname, ptr, n)
{
	this->index=index;
	this->semester=semester;
	this->major=major;
	this->faculty=faculty;
	this->table = new string[m];
	
}

Student::~Student()
{
	delete [] table;
	table=0;

	counter--;
}

int Student::get_index()
{
	return index;
}

void Student::set_index(int index)
{
	this->index=index;
}

int Student::get_semester()
{
	return semester;
}

void Student::set_semester(int semester)
{
	this->semester=semester;
}

string Student::get_major()
{
	return major;
}

void Student::set_major(string major)
{
	this->major=major;
}

string Student::get_faculty()
{
	return faculty;
}

void Student::set_faculty(string faculty)
{
	this->faculty=faculty;
}

int Student::studying_time()
{
	return (semester/2);
}

/*bool Student::operator==(const Base& a)
{
	const Base& a= dynamic_cast<const Student& a>;
	return ((a.age==age)&&(a.gender==gender)&&(a.name==name));
}

void Student::function1(){};
int Student::function2(){return 1;};*/