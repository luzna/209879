#include "jackpot.h"

Block Jackpot::all_blocks[]={Block(0,0),Block(0,1),Block(0,2),Block(0,3),Block(0,4),Block(0,5),Block(0,6),
							Block(1,1),Block(1,2),Block(1,3),Block(1,4),Block(1,5),Block(1,6),
							Block(2,2),Block(2,3),Block(2,4),Block(2,5),Block(2,6),
							Block(3,3),Block(3,4),Block(3,5),Block(3,6),
							Block(4,4),Block(4,5),Block(4,6),
							Block(5,5),Block(5,6),
							Block(6,6)};

Jackpot::Jackpot()
{}

Jackpot::~Jackpot()
{}

void Jackpot::DrawBlock()		//losowanie z puli
{
	srand(time(NULL));
	int x=rand()%27;
	all_blocks[x].DisplayBlock();
	//all_blocks[x]=;
}

