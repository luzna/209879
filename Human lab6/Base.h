#include "stdafx.h"

class Base
{
public:
	virtual void function1() = 0;
	virtual int function2() = 0;
	virtual bool operator==(const Base &a) = 0;
};