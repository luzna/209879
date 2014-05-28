#include "block.h"

BITMAP *Block::blocks = NULL;

Block::Block(){}

Block::Block(int left_field, int right_field)
{
	this->left_field=left_field;
	this->right_field=right_field;
	this->activity=0;
}

Block::~Block(){}

void Block::DisplayBlock()							//wyœwietlanie klocka
{
	blocks = load_bmp( "blocks.bmp", default_palette );
			
	blit( blocks, screen, left_field*75, 0, this->x, this->y, 75, 75 );
	blit( blocks, screen, right_field*75, 0, this->x+75, this->y, 75, 75 );
}

void Block::InvertBlock()							//obracanie klocka
{
	int bufor=0;
	bufor=left_field;
	left_field=right_field;
	right_field=bufor;
	DisplayBlock();
}

void Block::set_location(int x, int y)
{
	this->x=x;
	this->y=y;
}

int Block::get_x()
{
	return x;
}

int Block::get_y()
{
	return y;
}

void Block::active()
{
	this->activity=1;
}

bool Block::get_activity()
{
	return activity;
}

bool Block::operator==(Block &a)					//porównanie do sprawdzania poprawnoœci ruchu
{
	if(this->right_field==a.left_field)
		return 1;
	else return 0;
}

bool Block::operator-=(Block &a)					//porównanie do sprawdzania czy ruch by³by poprawny po obróceniu klocka
{
	if(this->right_field==a.right_field)
		return 1;
	else return 0;
}

int Block::operator+=(int &sum)						//sumowanie oczek na klocku
{
	sum=(sum+this->left_field+this->right_field);
	return sum;
}
