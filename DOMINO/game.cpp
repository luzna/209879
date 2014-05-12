#include "game.h"

Game::Game()
{
	BITMAP * background = NULL;
	background = load_bmp( "background.bmp", default_palette );
	blit( background, screen, 0, 0, 0, 0, background->w, background->h );	//t³o

	Jackpot pot;

	while( !key[ KEY_ESC ] )
    {
        if((mouse_b==1)&&(mouse_x<100)&&(mouse_y>550)&&(mouse_y<600))
		{	
			pot.DrawBlock();

		}

		//if((mouse_b==1)&&(mouse_x>100)&&(mouse_x<240)&&(mouse_y>500)&&(mouse_y<580))
			//.InvertBlock();

		clear_keybuf();
    }
}

Game::~Game(){}