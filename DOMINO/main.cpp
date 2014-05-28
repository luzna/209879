#include <allegro.h>
#include "block.h"
#include "jackpot.h"
#include "game.h"
#include "player.h"

int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth( 16 );			//g³êbia kolorów
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 1280, 800, 0, 0 );			//tryb graficzny -> wymiary okna
    
	
	
	install_mouse();					//wyœwietlanie myszki
	enable_hardware_cursor();
    select_mouse_cursor(MOUSE_CURSOR_ALLEGRO);
    show_mouse( screen );
    unscare_mouse();

	
	BITMAP * start = NULL;											//ekran startowy
	start = load_bmp( "start.bmp", default_palette );	
	blit(start, screen, 0, 0, 0, 0, 1280, 800 );
	
	
	while(!key[ KEY_ESC ])
	{
		if((mouse_b==1)&&(mouse_x>700)&&(mouse_x<1000)&&(mouse_y>400)&&(mouse_y<542))		//przycisk NewGame
		{
			Game NewGame;
			do{
				bool foo=0;
				NewGame.set_game(foo);
				NewGame.InitializeGame();
				NewGame.~Game();
				Game NewGame;
			}while(NewGame.gaming()==1);
		}
	}

	
	
	readkey();
	allegro_exit();
	return 0;
}

END_OF_MAIN();