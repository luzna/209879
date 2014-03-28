#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

struct location
{
	float x,y;
};

class Circle
{
	location location;
	float radius;
	static int counter;

public:
	Circle();
	Circle(::location location, float radius);
	~Circle();
	static int counting();
	Circle operator+(Circle a);
	Circle operator*(float scalar);
	void set_location(::location location);
	::location get_location(::location location);
	void set_radius(float radius);
	float get_radius();
	float circumference();
	float area();
};
