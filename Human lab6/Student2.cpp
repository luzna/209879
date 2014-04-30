#include "stdafx.h"
#include "Student2.h"

Student2::Student2() : Student()
{
	this->degree="unknown";
}

Student2::Student2(int age, string gender, string name, string surname, int(*ptr)[10], int n, int index, int semester, string major, string faculty, int m, string degree) 
	: Student(age, gender, name, surname, ptr, n, index, semester, major, faculty, m)
{
	this->degree=degree;
	average = new double[semester];
	
}

Student2::~Student2()
{
	delete [] average;
	average=0;
}

string Student2::get_degree()
{
	return degree;
}

void Student2::set_degree(string degree)
{
	this->degree=degree;
}

int Student2::studying_time()
{
	return (3+semester/2);
}