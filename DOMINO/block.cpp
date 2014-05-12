#include "block.h"

Block::Block(){}

Block::Block(int left_field, int right_field)
{
	this->left_field=left_field;
	this->right_field=right_field;
}

Block::~Block(){}

void Block::DisplayBlock()							//wyœwietlanie
{
	//BITMAP * bufor = NULL;
	//bufor = create_bitmap( 1280,800 );
	BITMAP * blocks = NULL;
	blocks = load_bmp( "blocks.bmp", default_palette );
	
	blit( blocks, screen, left_field*80, 0, 100, 500, 80, 80 );
	blit( blocks, screen, right_field*80, 0, 180, 500, 80, 80 );
	//blit( bufor, screen, 0, 0, 0, 0, 1280, 800 );
}

void Block::InvertBlock()							//obracanie
{
	int bufor=0;
	bufor=left_field;
	left_field=right_field;
	right_field=bufor;
	DisplayBlock();
}