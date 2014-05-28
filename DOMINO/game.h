#include <allegro.h>
#include "block.h"
#include "jackpot.h"
#include "player.h"

class Game
{
private:
	Block Chain[28];
	bool game;	//zmienna powi�zana z mainem - wznawianie gry
	bool won;	//koniec po spe�nieniu warunku wygranej - niesprawdzanie dalszych
public:
	Game();
	~Game();
	void InitializeGame();
	void WrongMove();
	bool gaming();
	void set_game(bool &game);
};