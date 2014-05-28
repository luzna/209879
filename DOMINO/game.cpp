#include "game.h"

Game::Game()
{
	BITMAP * background = NULL;
	background = load_bmp( "background.bmp", default_palette );
	blit( background, screen, 0, 0, 0, 0, 1280, 800 );	//t³o
}

Game::~Game()
{}

void Game::InitializeGame()
{
	int count=0;								//licznik elementów ³añcucha
	Jackpot pot;								//pula
	
	Player player1,player2;
	player1.DrawBlocks(1,pot);					//losowanie 7 klocków dla gracza nr 1
	player2.DrawBlocks(2,pot);					//losowanie 7 klocków dla gracza nr 2
	player1.set_player(player2);				//gracz nr 1 zaczyna
	
	bool NewBlockButton=1;						//aktywnoœæ przycisku NewBlock
	
	while( !key[ KEY_ESC ] )
    {
        
		if((mouse_b==1)&&(mouse_x>900)&&(mouse_x<1000)&&(mouse_y>350)&&(mouse_y<400)&&(NewBlockButton==1)&&(count+player1.get_block_count()+player2.get_block_count())!=28)			
		{
			if(player1.get_activity())																							//NewBlock
			{																													//losowanie elementu dla aktywnego gracza
				pot.DrawBlock(250,420);
			}
			else if(player2.get_activity())
			{
				pot.DrawBlock(850,420);
			}


			NewBlockButton=0;
		}


		if((mouse_b==2)&&(mouse_x>250)&&(mouse_x<400)&&(mouse_y>420)&&(mouse_y<495) && (NewBlockButton==0) )		//inversja œwie¿o wylosowanych klocków
		{
			if(player1.get_activity())
			{
				pot.Inversion();
				rest(500);
			}
		}
		if((mouse_b==2)&&(mouse_x>850)&&(mouse_x<1010)&&(mouse_y>420)&&(mouse_y<495) && (NewBlockButton==0) )
		{
			if(player2.get_activity())
			{
				pot.Inversion();
				rest(500);
			}
		}
		

		if( ((mouse_b==1)&&(mouse_x>470)&&(mouse_x<520)&&(mouse_y>420)&&(mouse_y<470)&&(NewBlockButton==0))||((mouse_b==1)&&(mouse_x>1070)&&(mouse_x<1120)&&(mouse_y>420)&&(mouse_y<470)&&(NewBlockButton==0)) )																//dodawanie klocka do talonu gracza
		{
			if(player1.get_activity())																//przyciski strza³ek - dodawanie do talonów graczy
			{	
				player1.AddBlocks(1, pot);
				NewBlockButton=1;
			}
			else if(player2.get_activity())
			{	
				player2.AddBlocks(2, pot);
				NewBlockButton=1;
			}

		}
		

		if((mouse_b==2)&&(mouse_x>0)&&(mouse_x<150)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))					//obracanie klocków w talonach po klikniêciu na nie prawym myszki
		{																														//dla gracza nr 1
			player1.Inversion(1);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>160)&&(mouse_x<310)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))
		{
			player1.Inversion(2);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>320)&&(mouse_x<470)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))
		{
			player1.Inversion(3);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>480)&&(mouse_x<630)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))
		{
			player1.Inversion(4);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>0)&&(mouse_x<150)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			player1.Inversion(5);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>160)&&(mouse_x<310)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			player1.Inversion(6);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>320)&&(mouse_x<470)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			player1.Inversion(7);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>480)&&(mouse_x<630)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			player1.Inversion(8);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>0)&&(mouse_x<150)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			player1.Inversion(9);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>160)&&(mouse_x<310)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			player1.Inversion(10);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>320)&&(mouse_x<470)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			player1.Inversion(11);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>480)&&(mouse_x<630)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			player1.Inversion(12);
			rest(500);
		}

		if((mouse_b==2)&&(mouse_x>645)&&(mouse_x<795)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))					//obracanie klocków w talonach po klikniêciu na nie prawym myszki
		{																														//dla gracza nr 2
			player2.Inversion(1);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>805)&&(mouse_x<955)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))
		{
			player2.Inversion(2);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>965)&&(mouse_x<1115)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))
		{
			player2.Inversion(3);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>1125)&&(mouse_x<1275)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))
		{
			player2.Inversion(4);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>645)&&(mouse_x<795)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			player2.Inversion(5);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>805)&&(mouse_x<955)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			player2.Inversion(6);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>965)&&(mouse_x<1115)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			player2.Inversion(7);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>1125)&&(mouse_x<1275)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			player2.Inversion(8);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>645)&&(mouse_x<795)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			player2.Inversion(9);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>805)&&(mouse_x<955)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			player2.Inversion(10);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>965)&&(mouse_x<1115)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			player2.Inversion(11);
			rest(500);
		}
		if((mouse_b==2)&&(mouse_x>1125)&&(mouse_x<1275)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			player2.Inversion(12);
			rest(500);
		}


		if((mouse_b==1)&&(mouse_x>0)&&(mouse_x<150)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))					//dodawanie klocków do ³añcucha po klikniêciu na nie
		{																														//dla gracza nr 1, kolej nastêpnego gracza
			if(Chain[count-1]==player1.get_talon(0)||count==0)
			{	
				Chain[count]=player1.get_talon(0);																			
				player1.Up(count, 1, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>160)&&(mouse_x<310)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(1)||count==0)
			{
				Chain[count]=player1.get_talon(1);
				player1.Up(count, 2, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>320)&&(mouse_x<470)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(2)||count==0)
			{
				Chain[count]=player1.get_talon(2);
				player1.Up(count, 3, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>480)&&(mouse_x<630)&&(mouse_y>505)&&(mouse_y<585)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(3)||count==0)
			{
				Chain[count]=player1.get_talon(3);
				player1.Up(count, 4, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>0)&&(mouse_x<150)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(4)||count==0)
			{
				Chain[count]=player1.get_talon(4);
				player1.Up(count, 5, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>160)&&(mouse_x<310)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(5)||count==0)
			{
				Chain[count]=player1.get_talon(5);
				player1.Up(count, 6, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>320)&&(mouse_x<470)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(6)||count==0)
			{
				Chain[count]=player1.get_talon(6);
				player1.Up(count, 7, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
			
		}
		if((mouse_b==1)&&(mouse_x>480)&&(mouse_x<630)&&(mouse_y>595)&&(mouse_y<675)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(7)||count==0)
			{
				Chain[count]=player1.get_talon(7);
				player1.Up(count, 8, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>0)&&(mouse_x<150)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(8)||count==0)
			{
				Chain[count]=player1.get_talon(8);
				player1.Up(count, 9, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>160)&&(mouse_x<310)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(9)||count==0)
			{
				Chain[count]=player1.get_talon(9);
				player1.Up(count, 10, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>320)&&(mouse_x<470)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(10)||count==0)
			{
				Chain[count]=player1.get_talon(10);
				player1.Up(count, 11, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>480)&&(mouse_x<630)&&(mouse_y>685)&&(mouse_y<765)&&(player1.get_activity()))
		{
			if(Chain[count-1]==player1.get_talon(11)||count==0)
			{
				Chain[count]=player1.get_talon(11);
				player1.Up(count, 12, 1);
				player2.set_player(player1);
			
				count++;
			}
			else WrongMove();
		}

		if((mouse_b==1)&&(mouse_x>645)&&(mouse_x<795)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))					//dodawanie klocków do ³añcucha po klikniêciu na nie
		{																														//dla gracza nr 2, kolej nastêpnego gracza
			if(Chain[count-1]==player2.get_talon(0)||count==0)
			{																								
				Chain[count]=player2.get_talon(0);
				player2.Up(count, 1, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>805)&&(mouse_x<955)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(1)||count==0)
			{
				Chain[count]=player2.get_talon(1);
				player2.Up(count, 2, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>965)&&(mouse_x<1115)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(2)||count==0)
			{
				Chain[count]=player2.get_talon(2);
				player2.Up(count, 3, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>1125)&&(mouse_x<1275)&&(mouse_y>505)&&(mouse_y<585)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(3)||count==0)
			{
				Chain[count]=player2.get_talon(3);
				player2.Up(count, 4, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>645)&&(mouse_x<795)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(4)||count==0)
			{
				Chain[count]=player2.get_talon(4);
				player2.Up(count, 5, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>805)&&(mouse_x<955)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(5)||count==0)
			{
				Chain[count]=player2.get_talon(5);
				player2.Up(count, 6, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>965)&&(mouse_x<1115)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(6)||count==0)
			{
				Chain[count]=player2.get_talon(6);
				player2.Up(count, 7, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>1125)&&(mouse_x<1275)&&(mouse_y>595)&&(mouse_y<675)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(7)||count==0)
			{
				Chain[count]=player2.get_talon(7);
				player2.Up(count, 8, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>645)&&(mouse_x<795)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(8)||count==0)
			{
				Chain[count]=player2.get_talon(8);
				player2.Up(count, 9, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>805)&&(mouse_x<955)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(9)||count==0)
			{
				Chain[count]=player2.get_talon(9);
				player2.Up(count, 10, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>965)&&(mouse_x<1115)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(10)||count==0)
			{
				Chain[count]=player2.get_talon(10);
				player2.Up(count, 11, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}
		if((mouse_b==1)&&(mouse_x>1125)&&(mouse_x<1275)&&(mouse_y>685)&&(mouse_y<765)&&(player2.get_activity()))
		{
			if(Chain[count-1]==player2.get_talon(11)||count==0)
			{
				Chain[count]=player2.get_talon(11);
				player2.Up(count, 12, 2);
				player1.set_player(player2);
			
				count++;
			}
			else WrongMove();
		}




		if(((mouse_b==1)&&(mouse_x>250)&&(mouse_x<400)&&(mouse_y>420)&&(mouse_y<500))||((mouse_b==1)&&(mouse_x>850)&&(mouse_x<1000)&&(mouse_y>420)&&(mouse_y<500)))
		{
			if(Chain[count-1]==pot.get_all_blocks())
			{
				pot.Up(count);
				Chain[count]=pot.get_all_blocks();												//dodawanie klocka do ³añcucha
				count++;
			
				if(player1.get_activity())											//prze³¹czanie na nastêpnego gracza
				{
					player2.set_player(player1);
				}
				else if(player2.get_activity())
				{
					player1.set_player(player2);
				}
				NewBlockButton=1;
			}
			else 
				WrongMove();
						
			rest(500);
	 	}
		
		

		if(player1.get_block_count()==0||player2.get_block_count()==0)			//wygrana po pozbyciu siê wszystkich klocków z talonu
		{
			BITMAP * youwon = NULL;
			youwon = load_bmp("youwon.bmp", default_palette);
			blit(youwon, screen, 0, 0, 470, 350, youwon->w, youwon->h);
			won=1;
		}

		if( (count+player1.get_block_count()+player2.get_block_count())==28 && (won!=1) )	//wygrana po wyczerpaniu puli
		{
			int moves1=0;
			int moves2=0;

			for(int i=0; i<player1.get_block_count(); i++)				//zliczanie mo¿liwych ruchów gracza nr 1
			{
				if( Chain[count-1]==player1.get_talon(i) )
					moves1++;
				if( Chain[count-1]-=player1.get_talon(i) )
					moves1++;
			}
			for(int i=0; i<player2.get_block_count(); i++)				//zliczanie mo¿liwych ruchów gracza nr 2
			{
				if( Chain[count-1]==player2.get_talon(i) )
					moves2++;
				if( Chain[count-1]-=player2.get_talon(i) )
					moves2++;
			}

			if(player1.get_activity()&&(moves1==0))						//utrata kolejki gracza nr 1 gdy nie ma mo¿liwych ruchów
			{
				player2.set_player(player1);
				rest(500);
			}
			
			
			if(player2.get_activity()&&(moves2==0))						//analogicznie utrata kolejki gracza nr 2
			{
				player1.set_player(player2);
				rest(500);
			}

			if( (moves1==0)&&(moves2==0) )								//nikt nie ma dostêpnych ruchów - wygrywa gracz z mniejsz¹ sum¹ oczek swoich klocków
			{
				int sum1=0;
				int sum2=0;
				for(int i=0; i<player1.get_block_count(); i++)
					player1.get_talon(i)+=sum1;
				for(int i=0; i<player2.get_block_count(); i++)
					player2.get_talon(i)+=sum2;

				if(sum1<sum2)
				{
					BITMAP * nomove1 = NULL;
					nomove1 = load_bmp("nomove1.bmp", default_palette);
					blit(nomove1, screen, 0, 0, 470, 350, nomove1->w, nomove1->h);
					break;
				}
				else if(sum1>sum2)
				{
					BITMAP * nomove2 = NULL;
					nomove2 = load_bmp("nomove2.bmp", default_palette);
					blit(nomove2, screen, 0, 0, 470, 350, nomove2->w, nomove2->h);
					break;
				}
			}
		}

		if((mouse_b==1)&&(mouse_x>1050)&&(mouse_y<40))				//przycisk NewGame w prawym rogu
		{
			game=1;
			break;	
		}

		

		clear_keybuf();
		
	}
}

void Game::WrongMove()							//wyœwietlanie komunikatu o nieprawid³owym ruchu
{
	BITMAP * wrongmove = NULL;
	wrongmove = load_bmp("wrongmove.bmp", default_palette);
	blit(wrongmove, screen, 0, 0, 470, 350, wrongmove->w, wrongmove->h);
	rest(1000);
	BITMAP * wrongblack = NULL;
	wrongblack = load_bmp("wrongblack.bmp", default_palette);
	blit(wrongblack, screen, 0, 0, 470, 350, wrongblack->w, wrongblack->h);
}

bool Game::gaming()
{
	return game;
}

void Game::set_game(bool &game)
{
	this->game=game;
}