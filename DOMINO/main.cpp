#include <allegro.h>
#include "block.h"

int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth( 16 );			//g³êbia kolorów
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 1024, 768, 0, 0 );			//tryb graficzny -> wymiary okna
    clear_to_color( screen, makecol( 0,0,0) );			//kolor t³a
	
	install_mouse();					//wyœwietlanie myszki
	enable_hardware_cursor();
    select_mouse_cursor(MOUSE_CURSOR_ALLEGRO);
    show_mouse( screen );
    unscare_mouse();
	
	
	Block a(6,1), b(4,2), c(5,0);			//tymczasowy test dzia³ania funkcji
	a.DisplayBlock();
	a.NextBlock(); 
	b.DisplayBlock();
	b.NextBlock();
	c.DisplayBlock();
	
	if(mouse_b==1)
		a.InvertBlock();

	readkey();
	allegro_exit();
	return 0;
}

END_OF_MAIN();