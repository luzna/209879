#include "block.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#ifndef __JACKPOT_H_INCLUDED__
#define __JACKPOT_H_INCLUDED__

class Jackpot
{
private:
	static Block all_blocks[28];
	
public:
	Jackpot();
	~Jackpot();
	void DrawBlock();
	

};

#endif