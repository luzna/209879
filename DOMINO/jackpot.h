#include "block.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#ifndef __JACKPOT_H_INCLUDED__
#define __JACKPOT_H_INCLUDED__

class Jackpot : public Block
{
private:
	Block All_blocks[28];
	
public:
	Jackpot();
	~Jackpot();
	void DrawBlock(int x, int y);
	void Inversion();
	void Up(int &count);
	Block get_all_blocks();
};

#endif