#include "stdafx.h"
#include "Class.h"
#include <iostream>

Circle::Circle()
{
	this->location.x=0;
	this->location.y=0;
	this->radius=0;

	counter++;
}

Circle::Circle(::location new_location, float new_radius)
{
	this->location.x=new_location.x;
	this->location.y=new_location.y;
	this->radius=new_radius;
}

Circle::~Circle(){}

int Circle::counter=0;
int Circle::counting()
{
	std::cout<<"existing objects: "<<counter<<"\n";
	return counter;
}

Circle Circle::operator+(Circle a)
{
	Circle sum;
	sum.location.x = (this->location.x+a.location.x)/2;
	sum.location.y = (this->location.y+a.location.y)/2;
	sum.radius = this->radius+a.radius;
	return sum;
}

Circle Circle::operator*(float scalar)
{
	Circle result;
	result.radius = this->radius * scalar;
	return result;
}

void Circle::set_location(::location location)
{
	this->location=location;
}
		
float Circle::get_locationx()
{
	return location.x;
}

float Circle::get_locationy()
{
	return location.y;
}

void Circle::set_radius(float radius)
{
	this->radius=radius;
}

float Circle::get_radius()
{
	return radius;
}

float Circle::circumference()
{
	return 2 * M_PI * radius;
}

float Circle::area()
{
	return M_PI * pow(radius,2);
}
