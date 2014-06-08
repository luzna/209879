using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace DominoCsharp
{
    class Game
    {
        private Block [] Chain = new Block[28];
	    
        public Game(){}

	    ~Game(){}

        public void DrawChain(SpriteBatch spriteBatch, int chain_count)         //rysowanie łańcucha
        {
            for (int i = 0; i < chain_count; i++)
                Chain[i].DisplayBlock(spriteBatch);
        }

        public void AddToChain(int chain_count, Block block)                //przenoszenie z talonu do łańcucha i ustawianie współrzędnych
        {
            Chain[chain_count] = block;

                        
            if (chain_count < 8)												
                this.Chain[chain_count].setPosition(chain_count * 150, 40);
            else if ((chain_count >= 8) && (chain_count < 16))
                this.Chain[chain_count].setPosition((chain_count - 8) * 150, 140);
            else if ((chain_count >= 16) && (chain_count < 24))
                this.Chain[chain_count].setPosition((chain_count - 16) * 150, 240);
            else if (chain_count >= 24)
                this.Chain[chain_count].setPosition((chain_count - 24) * 150, 340);
        }

        public void WrongMove(Texture2D texture, SpriteBatch spriteBatch)             //wyświetlanie komunikatu o nieprawidłowym ruchu
        {
            spriteBatch.Draw(texture, new Rectangle(470, 350, 342, 50), Color.White);
        }

        public Block get_chain(int n)
        {
            return (Chain[n]);
        }

    
    
    }
}
