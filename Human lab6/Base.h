#include "stdafx.h"

#ifndef __BASE_H_INCLUDED__
#define __BASE_H_INCLUDED__

class Base
{
public:
	virtual bool operator==(const Base &a) = 0;
};

#endif