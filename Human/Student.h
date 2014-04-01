#include "stdafx.h"
#include "Human.h"

class Student : public Human
{
private:
	int index;
	int semester;
	string major;
	string faculty;
public:
	Student();
	Student(int age, string gender, string name, string surname, int(*ptr)[10], int index, int semester, string major, string faculty);
	~Student();
	int get_index();
	int get_semester();
	string get_major();
	string get_faculty();
};

