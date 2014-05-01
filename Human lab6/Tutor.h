#include "stdafx.h"
#include "Human.h"

class Tutor : public Human
{
private:
	string title;
	int number_of_publications;

public:
	Tutor();
	Tutor(int age, string gender, string name, string surname, int n, string title, int number_of_publications);
	~Tutor();
	string get_title();
	void set_title(string title);
	int get_number_of_publications();
	void set_number_of_publications(int number_of_publications);
};