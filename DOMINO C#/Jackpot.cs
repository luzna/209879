using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace DominoCsharp
{
    class Jackpot : Block
    {
        private Block[] All_blocks;


        public Jackpot()                            //inicjalizacja puli
        {
            All_blocks = new Block[28];

            int k = 0;
            for (int i = 0; i <= 6; i++)
            {
                for (int j = i; j <= 6; j++)
                {
                    All_blocks[k] = new Block(i, j);
                    k++;
                }
            }

        }


         ~Jackpot() 
         {}

        public void Shuffle()                                   //tasowanie - zmiania ustawienia klocków w puli
        {
            Random rng = new Random();
            int n = 28;  
            while (n > 1) 
            {  
                n--;  
                int k = rng.Next(n + 1);  
                Block value = All_blocks[k];  
                All_blocks[k] = All_blocks[n];  
                All_blocks[n] = value;  
            }     
        }

        public Block get_all_blocks(int n)
        {
           return (All_blocks[n]);
        }
    }
}