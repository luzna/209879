#include "stdafx.h"
#include "Human.h"

class Student : public Human
{
protected:
	int index;
	int semester;
	string major;
	string faculty;
	string *table;
public:
	Student();
	Student(int age, string gender, string name, string surname, int(*ptr)[10], int n, int index, int semester, string major, string faculty, int m);
	~Student();
	int get_index();
	void set_index(int index);
	int get_semester();
	void set_semester(int semester);
	string get_major();
	void set_major(string major);
	string get_faculty();
	void set_faculty(string faculty);
};

