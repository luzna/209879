#include <allegro.h>

#ifndef __BLOCK_H_INCLUDED__
#define __BLOCK_H_INCLUDED__


class Block
{
private:
	int left_field, right_field;

public:
	Block();
	Block(int left_field, int right_field);
	~Block();
	void DisplayBlock();
	void InvertBlock();
};

#endif