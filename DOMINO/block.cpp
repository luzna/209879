#include "block.h"

int Block::position_x=0;
int Block::position_y=0;

Block::Block(int left_field, int right_field)
{
	this->left_field=left_field;
	this->right_field=right_field;
}

Block::~Block(){}

void Block::NextBlock()
{
	position_x+=160;
}

void Block::DisplayBlock()
{
	BITMAP *soap = NULL;
	soap = load_bmp( "soap.bmp", default_palette );
	BITMAP *dot = NULL;
	dot = load_bmp( "dot.bmp", default_palette );

	blit( soap, screen, 0, 0, position_x, position_y, soap->w, soap->h );

	if(left_field==1)																//kropki po lewej
		blit( dot, screen, 0, 0, position_x+30, position_y+30, dot->w, dot->h );
	else if(left_field==2){
		blit( dot, screen, 0, 0, position_x+15, position_y+30, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+45, position_y+30, dot->w, dot->h );
	}
	else if(left_field==3){
		blit( dot, screen, 0, 0, position_x+10, position_y+30, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30, position_y+30, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50, position_y+30, dot->w, dot->h );
	}
	else if(left_field==4){
		blit( dot, screen, 0, 0, position_x+15, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+45, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+15, position_y+45, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+45, position_y+45, dot->w, dot->h );
	}
	else if(left_field==5){
		blit( dot, screen, 0, 0, position_x+10, position_y+10, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50, position_y+10, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+10, position_y+50, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50, position_y+50, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30, position_y+30, dot->w, dot->h );
	}
	else if(left_field==6){
		blit( dot, screen, 0, 0, position_x+10, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+10, position_y+45, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30, position_y+45, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50, position_y+45, dot->w, dot->h );
	}
	
	if(right_field==1)																//kropki po prawej
		blit( dot, screen, 0, 0, position_x+30+70, position_y+30, dot->w, dot->h );
	else if(right_field==2){
		blit( dot, screen, 0, 0, position_x+15+70, position_y+30, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+45+70, position_y+30, dot->w, dot->h );
	}
	else if(right_field==3){
		blit( dot, screen, 0, 0, position_x+10+70, position_y+30, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30+70, position_y+30, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50+70, position_y+30, dot->w, dot->h );
	}
	else if(right_field==4){
		blit( dot, screen, 0, 0, position_x+15+70, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+45+70, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+15+70, position_y+45, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+45+70, position_y+45, dot->w, dot->h );
	}
	else if(right_field==5){
		blit( dot, screen, 0, 0, position_x+10+70, position_y+10, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50+70, position_y+10, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+10+70, position_y+50, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50+70, position_y+50, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30+70, position_y+30, dot->w, dot->h );
	}
	else if(right_field==6){
		blit( dot, screen, 0, 0, position_x+10+70, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30+70, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50+70, position_y+15, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+10+70, position_y+45, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+30+70, position_y+45, dot->w, dot->h );
		blit( dot, screen, 0, 0, position_x+50+70, position_y+45, dot->w, dot->h );
	}

	destroy_bitmap( soap );
	destroy_bitmap( dot );
}

void Block::InvertBlock()							//obracanie klocka
{
	int bufor=0;
	bufor=left_field;
	left_field=right_field;
	right_field=bufor;
	DisplayBlock();
}