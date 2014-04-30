#include "stdafx.h"
#include "Mama1.h"
#include <string>
#include <iostream>
using namespace std;
#ifndef __HUMAN_H_INCLUDED__
#define __HUMAN_H_INCLUDED__

class Human : public Mama1
{
protected:
	int age;
	string gender;
	string name;
	string surname;
	int (*ptr)[10];
	static int counter;
	string *favorite_books;
public:
	Human();
	Human(int age, string gender, string name, string surname, int(*ptr)[10], int n);
	virtual ~Human();
	static int counting();
	friend ostream& operator<<(ostream& out, Human &A);
	friend istream& operator>>(istream& in, Human &A);
	void set_age(int age);
	int get_age();
	void set_gender(string gender);
	string get_gender();
	void set_name(string name);
	string get_name();
	void set_surname(string surname);
	string get_surname();
	void set_ptr(int (*ptr)[10]);
	int* get_ptr();
	void birthday();
	virtual int studying_time();
};

#endif