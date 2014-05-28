#include <allegro.h>

#ifndef __BLOCK_H_INCLUDED__
#define __BLOCK_H_INCLUDED__

class Block
{
protected:
	int left_field, right_field;
	int x,y;
	static BITMAP * blocks;
	bool activity;
	
public:
	Block();
	Block(int left_field, int right_field);
	~Block();
	void DisplayBlock();
	void InvertBlock();
	void set_location(int x, int y);
	int get_x();
	int get_y();
	void active();
	bool get_activity();
	bool operator==(Block &a);
	bool operator-=(Block &a);
	int operator+=(int &sum);
};

#endif