using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;

namespace DominoCsharp
{
    class Player : Block
    {
        private	int block_count;
	    bool activity;						//gracz aktywny=1, czekający na swoją kolej=0
	    private Block [] Talon;

        public Player()
        {
            block_count=0;
	        Talon = new Block[7];
        }

        ~Player() { }

        public void DrawTalon(SpriteBatch spriteBatch)          //rysowanie talonu
        {
            for(int i=0; i<block_count; i++)
            Talon[i].DisplayBlock(spriteBatch);
        }

	    public void DrawBlocks(int No, Jackpot pot)             // przenoszenie pierwszych 14 klocków do talonów i ustawianie współrzędnych
        {
            if(No==1)
	        {
		        int x=0;
		        int y=505;
		        for(int i=0;i<7;i++)
		        {
			        Talon[i]=pot.get_all_blocks(i);
                    Talon[i].setPosition(x, y);
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
                    int j=7;
		            for(int i=0;i<7;i++)
		            {
			            Talon[i]=pot.get_all_blocks(j);
                        Talon[i].setPosition(x, y);
  			            
                        j++;

			            x+=160;
			            if(i==3)
			            {
				            x=645;
				            y+=90;
			            }
		
                    }
                }
            
            block_count = 7;
        }

	    public void AddBlock(int No, Jackpot pot, int count)              //dodawanie świeżo wylosowanego klocka do talonu (najpierw obok strzałki)
        {
            Block [] buff = new Block[block_count];
	        for(int i=0; i<block_count; i++)
		        buff[i]=this.Talon[i];				
	        Talon = new Block[block_count+1];		
	        for(int i=0; i<block_count; i++)
		    Talon[i]=buff[i];					 
	                   	
	        Talon[block_count]=pot.get_all_blocks(count);

            if(No == 1)
                Talon[block_count].setPosition(250, 420);
            else if(No == 2)
                Talon[block_count].setPosition(850, 420);

            block_count++;

        }
	
	    public void MoveDown(int No)                                //przenoszenie klocka na dół (po kliknięciu strzałki)
        {
            if(No==1)											//ustalawianie odpowiednich współrzędnych w zależności od aktualnej ilości klocków w talonie
	        {
		        switch(block_count-1)
		        {
                    case 1: Talon[block_count-1].setPosition(160, 505); break;
                    case 2: Talon[block_count-1].setPosition(320, 505); break;
                    case 3: Talon[block_count-1].setPosition(480, 505); break;
                    case 4: Talon[block_count-1].setPosition(0, 595); break;
                    case 5: Talon[block_count-1].setPosition(160, 595); break;
                    case 6: Talon[block_count-1].setPosition(320, 595); break;
                    case 7: Talon[block_count-1].setPosition(480, 595); break;
                    case 8: Talon[block_count-1].setPosition(0, 685); break;
                    case 9: Talon[block_count-1].setPosition(160, 685); break;
                    case 10: Talon[block_count-1].setPosition(320, 685); break;
                    case 11: Talon[block_count-1].setPosition(480, 685); break;
		            }	
	        }		
	        else if(No==2)
	        {
		        switch(block_count-1)
		        {
		            case 1: Talon[block_count-1].setPosition(805, 505); break;
		            case 2: Talon[block_count-1].setPosition(965, 505); break;
		            case 3: Talon[block_count-1].setPosition(1125, 505); break;
		            case 4: Talon[block_count-1].setPosition(645, 595); break;
		            case 5: Talon[block_count-1].setPosition(805, 595); break;
		            case 6: Talon[block_count-1].setPosition(965, 595); break;
		            case 7: Talon[block_count-1].setPosition(1125, 595); break;
		            case 8: Talon[block_count-1].setPosition(645, 685); break;
		            case 9: Talon[block_count-1].setPosition(805, 685); break;
		            case 10: Talon[block_count-1].setPosition(965, 685); break;
		            case 11: Talon[block_count-1].setPosition(1125, 685); break;
		        }	
	        }

         }

	    public void Delete(int chain_count, int number, int No)                           //przenoszenie klocków z talonu do łańcucha
        {
            block_count--;										//zmniejszanie licznika elementów talonu
            
            Block []buff = new Block[block_count];				//zmniejszanie i zsuwanie tablicy przechowującej talon
	        for(int i=0; i<number; i++)             
		        buff[i]=this.Talon[i];
	        if((number-1)<=block_count)
		        for(int i=number; i<block_count; i++)
			            buff[i]=this.Talon[i+1];
	        Talon = new Block[block_count];
	        for(int i=0; i<block_count; i++)
		        Talon[i]=buff[i];

            if (No == 1)                                    //aktualizacja współrzędnych klocków w talonie
            {
                int x = 0;
                int y = 505;
                for (int i = 0; i < block_count; i++)
                {
                    Talon[i].setPosition(x, y);
                    
                    x += 160;
                    if (i == 3)
                    {
                        x = 0;
                        y += 90;
                    }

                    if (i == 7)
                    {
                        x = 0;
                        y += 90;
                    }
                }
            }

            else if (No == 2)
            {
                int x = 645;
                int y = 505;
                for (int i = 0; i < block_count; i++)
                {
                    Talon[i].setPosition(x, y);
                    
                    x += 160;
                    if (i == 3)
                    {
                        x = 645;
                        y += 90;
                    }

                    if (i == 7)
                    {
                        x = 645;
                        y += 90;
                    }
                }
            }


        }

	    public void set_player(Player second_player)			//ustawianie aktywności graczy
        {
	        this.activity=true;
	        second_player.activity=false;
        }
        
	    public bool get_activity()
        {
            return activity;
        }

	    public int get_block_count()
        {
            return block_count;
        }

	    public Block get_talon(int n)
        {
            return(Talon[n]);
        }
    }
}
        