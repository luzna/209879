#include "stdafx.h"
#include "Student.h"

class Student2 : public Student
{
private:
	string degree;
	double*average;
public:
	Student2();
	Student2(int age, string gender, string name, string surname, int(*ptr)[10], int n, int index, int semester, string major, string faculty, int m, string degree);
	~Student2();
	string get_degree();
	void set_degree(string degree);
};