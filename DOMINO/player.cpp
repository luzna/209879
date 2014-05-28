#include "player.h"

Player::Player()
{
	block_count=7;
	Talon = new Block[7];					//ka¿dy gracz ma na pocz¹tku 7 klocków
}

Player::~Player()
{
	delete [] Talon;
	Talon=0;
}

void Player::DrawBlocks(int No, Jackpot &pot)			//losowanie klocków dla graczy (pierwszych 7)
{
	if(No==1)
	{
		int x=0;
		int y=505;
		for(int i=0;i<7;i++)
		{
			pot.DrawBlock(x,y);
			rest(1000);
			Talon[i]=pot.get_all_blocks();
			
			x+=160;
			if(i==3)
			{
				x=0;
				y+=90;
			}
		}
	}

	else if(No==2)
	{
		int x=645;
		int y=505;
		for(int i=0;i<7;i++)
		{
			pot.DrawBlock(x,y);
			rest(1000);
			Talon[i]=pot.get_all_blocks();

			x+=160;
			if(i==3)
			{
				x=645;
				y+=90;
			}
		}
	}

}

void Player::AddBlocks(int No, Jackpot &pot)				//dodawanie do talonu œwie¿o wylosowanego klocka
{
	Block *buff = new Block[block_count];				//powiêkszanie tablicy o 1
	for(int i=0; i<block_count; i++)
		buff[i]=Talon[i];				
	delete [] Talon;
	Talon = new Block[block_count+1];		
	for(int i=0; i<block_count; i++)
		Talon[i]=buff[i];					 
	delete [] buff;							
	
	Talon[block_count]=pot.get_all_blocks();
	
	if(No==1)											//ustalawianie odpowiednich wspó³rzêdnych w zale¿noœci od aktualnej iloœci klocków w talonie
	{
		switch(block_count)
		{
		case 1: Talon[block_count].set_location(160, 505); break;
		case 2: Talon[block_count].set_location(320, 505); break;
		case 3: Talon[block_count].set_location(480, 505); break;
		case 4: Talon[block_count].set_location(0, 595); break;
		case 5: Talon[block_count].set_location(160, 595); break;
		case 6: Talon[block_count].set_location(320, 595); break;
		case 7: Talon[block_count].set_location(480, 595); break;
		case 8: Talon[block_count].set_location(0, 685); break;
		case 9: Talon[block_count].set_location(160, 685); break;
		case 10: Talon[block_count].set_location(320, 685); break;
		case 11: Talon[block_count].set_location(480, 685); break;
		}	
	}		
	else if(No==2)
	{
		switch(block_count)
		{
		case 1: Talon[block_count].set_location(805, 505); break;
		case 2: Talon[block_count].set_location(965, 505); break;
		case 3: Talon[block_count].set_location(1125, 505); break;
		case 4: Talon[block_count].set_location(645, 595); break;
		case 5: Talon[block_count].set_location(805, 595); break;
		case 6: Talon[block_count].set_location(965, 595); break;
		case 7: Talon[block_count].set_location(1125, 595); break;
		case 8: Talon[block_count].set_location(645, 685); break;
		case 9: Talon[block_count].set_location(805, 685); break;
		case 10: Talon[block_count].set_location(965, 685); break;
		case 11: Talon[block_count].set_location(1125, 685); break;
		}	
	}

	Talon[block_count].DisplayBlock();								//wyœwietlanie klocka ju¿ w talonie
	BITMAP * black = NULL;
	black = load_bmp( "black.bmp", default_palette);
	blit( black, screen, 0, 0, 250, 420, 150, 75 );
	blit( black, screen, 0, 0, 850, 420, 150, 75 );
	rest(1000);
	block_count++;
}

void Player::Up(int &count, int number, int No)				//przenoszenie klocków z talonu do ³añcucha
{
	int a=Talon[number-1].get_x();							//zapamiêtywanie po³o¿enia przenoszonego klocka
	int b=Talon[number-1].get_y();

	if(count<8)												//przenoszenie do ³añcucha
		Talon[number-1].set_location(count*150,40);
	else if((count>=8)&&(count<16))
		Talon[number-1].set_location((count-8)*150,140);
	else if((count>=16)&&(count<24))
		Talon[number-1].set_location((count-16)*150,240);
	else if(count>=24)
		Talon[number-1].set_location((count-24)*150,340);
	
	Talon[number-1].DisplayBlock();
	
	
	block_count--;											//zmniejszanie licznika elementów talonu

	if(block_count>=number)
	{
		for(int i=block_count; i>number; i--)					//zsuwanie klocków (przesuwanie wspó³rzêdnych)
		{
			Talon[i].set_location(Talon[i-1].get_x(),Talon[i-1].get_y());
		}
		Talon[number].set_location(a,b);
	}

	Block *buff = new Block[block_count];					//zmniejszanie i zsuwanie tablicy przechowuj¹cej talon
	for(int i=0; i<(number-1); i++)
		buff[i]=Talon[i];
	if((number-1)<=block_count)
		for(int i=(number-1); i<block_count; i++)
			buff[i]=Talon[i+1];
	delete [] Talon;
	Talon = new Block[block_count];
	for(int i=0; i<block_count; i++)
		Talon[i]=buff[i];
	delete [] buff;

	for(int i=0; i<block_count; i++)						//wyœwietlanie zsuniêtych klocków
		Talon[i].DisplayBlock();

	BITMAP * black = NULL;
	black = load_bmp( "black.bmp", default_palette);
	if(No==1)
	{
		if(block_count<4)
		blit( black, screen, 0, 0, block_count*160, 505, 150, 75 );
	else if((block_count>=4)&&(block_count<8))
		blit( black, screen, 0, 0, (block_count-4)*160, 595, 150, 75 );
	else if(block_count>=8)
		blit(black, screen, 0, 0, (block_count-8)*160, 685, 150, 75 );
	}
	else if(No==2)
	{
		if(block_count<4)
		blit( black, screen, 0, 0, block_count*160+645, 505, 150, 75 );
	else if((block_count>=4)&&(block_count<8))
		blit( black, screen, 0, 0, (block_count-4)*160+645, 595, 150, 75 );
	else if(block_count>=8)
		blit(black, screen, 0, 0, (block_count-8)*160+645, 685, 150, 75 );
	}
}

void Player::Inversion(int number)							//obracanie klocków w talonie
{
	Talon[number-1].InvertBlock();
}

void Player::set_player(Player &second_player)				//ustawianie aktywnoœci graczy
{
	this->activity=1;
	second_player.activity=0;
}

bool Player::get_activity()
{
	return activity;
}

int Player::get_block_count()
{
	return block_count;
}

Block Player::get_talon(int n)
{
	return(Talon[n]);
}