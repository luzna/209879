#include <allegro.h>
#include "jackpot.h"

#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

class Player : public Block
{
private:
	int block_count;
	bool activity;						//gracz aktywny=1, czekaj¹cy na swoj¹ kolej=0
	Block *Talon;
public:
	Player();
	~Player();
	void DrawBlocks(int No, Jackpot &pot);
	void AddBlocks(int No, Jackpot &pot);
	void Up(int &count, int number, int No);
	void Inversion(int number);
	void set_player(Player &second_player);	
	bool get_activity();
	int get_block_count();
	Block get_talon(int n);
};

#endif