#include "jackpot.h"

Jackpot::Jackpot()			//tworzenie puli
{
	int k=0;
	{
		for(int i=0;i<=6;i++)
		{
			for(int j=i;j<=6;j++)
			{
				All_blocks[k]=Block(i,j);
				k++;
			}
		}
	}
}

Jackpot::~Jackpot()
{}

int z=0;									//aktywny element tablicy(puli)

void Jackpot::DrawBlock(int x, int y)		//losowanie z puli
{
	do{
		srand(time(NULL));
		z=rand()%28;
	}while(All_blocks[z].get_activity());
	
	All_blocks[z].set_location(x,y);
	All_blocks[z].DisplayBlock();
	All_blocks[z].active();
}

void Jackpot::Inversion()				//obracanie œwie¿o wylosowanego klocka
{
	All_blocks[z].InvertBlock();
}

void Jackpot::Up(int &count)			//przenoszenie œwie¿o wylosowanych klocków do ³añcucha 
{
	if(count<8)
		All_blocks[z].set_location(count*150,40);
	if((count>=8)&&(count<16))
		All_blocks[z].set_location((count-8)*150,140);
	if((count>=16)&&(count<24))
		All_blocks[z].set_location((count-16)*150,240);
	if(count>=24)
		All_blocks[z].set_location((count-24)*150,340);
	
	All_blocks[z].DisplayBlock();
	BITMAP * black = NULL;
	black = load_bmp( "black.bmp", default_palette);
	blit( black, screen, 0, 0, 250, 420, 150, 75 );
	blit( black, screen, 0, 0, 850, 420, 150, 75 );
}

Block Jackpot::get_all_blocks()
{
	return(All_blocks[z]);
}