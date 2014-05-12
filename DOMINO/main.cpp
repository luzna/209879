#include <allegro.h>
#include "block.h"
#include "jackpot.h"
#include "game.h"

int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth( 16 );			//g��bia kolor�w
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 1280, 800, 0, 0 );			//tryb graficzny -> wymiary okna
    
	

	install_mouse();					//wy�wietlanie myszki
	enable_hardware_cursor();
    select_mouse_cursor(MOUSE_CURSOR_ALLEGRO);
    show_mouse( screen );
    unscare_mouse();



	Game NewGame;			//test dzia�ania


	
	
	readkey();
	allegro_exit();
	return 0;
}

END_OF_MAIN();