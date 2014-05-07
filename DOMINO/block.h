#include <allegro.h>

class Block
{
private:
	int left_field, right_field;
	static int position_x;
	static int position_y;
public:
	Block(int left_field, int right_field);
	~Block();
	void NextBlock();
	void DisplayBlock();
	void InvertBlock();
};