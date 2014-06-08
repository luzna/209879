using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace DominoCsharp
{
    class Block
    {
        static Texture2D texture;
        
        protected int left_field, right_field;
        protected int x, y;
        protected Rectangle rectangle;

        public bool isClicked;
        public bool wasClicked;
        public bool secondClicked;
        Color colour = Color.White;

        public Block() { }

        

        public Block(int left_field, int right_field)
        {
            this.left_field=left_field;
            this.right_field=right_field;
        }

        ~Block(){}
        
        static public void LoadBlock(Texture2D newTexture, GraphicsDevice graphics)     //ładowanie bitmapy z oczkami
        {
            texture = newTexture;
        }
        
        public void DisplayBlock(SpriteBatch spriteBatch)                               //rysowanie klocka
        {
            Rectangle sourceRectangle = new Rectangle(75*left_field, 0, 75, 75);
            Rectangle source2Rectangle = new Rectangle(75*right_field, 0, 75, 75);
            spriteBatch.Draw(texture, new Vector2(this.x,this.y), sourceRectangle, colour);
            spriteBatch.Draw(texture, new Vector2(this.x+75, this.y), source2Rectangle, colour);
        }

        public void InvertBlock()                       //obracanie
        {
            int buff=0;
            buff=left_field;
            left_field=right_field;
            right_field=buff;
        }

        public int X {get; set;}
        public int Y {get; set;}


        public bool Compare(Block a)                    //porówbywanie - poprawność ruchu
        {
            if (this.right_field == a.left_field)
                return true;
            else return false;
        }

        public bool CompareInversed(Block a)
        {
            if(this.right_field == a.right_field)
                return true;
            else return false;
        }

        public int Sum()                        //sumowanie liczby oczek
        {
            int sum = 0;
            sum = this.left_field+this.right_field;
            return sum;
        }

        public void setPosition(int x, int y)       //ustawianie współrzędnych wyświetlania
        {
            this.x = x;
            this.y = y;
        }

        public void Update(MouseState CurrentMouseState, MouseState PreviousMouseState)                 //klocek jako przycisk - wykrywanie kliknięcia i podświetlanie
        {
            rectangle = new Rectangle(x, y, 150, 75);
            

            Rectangle mouseRectangle = new Rectangle(CurrentMouseState.X, CurrentMouseState.Y, 1, 1);

            if (CurrentMouseState.LeftButton == ButtonState.Pressed && PreviousMouseState.LeftButton == ButtonState.Released)
            {
                if (mouseRectangle.Intersects(rectangle))
                    wasClicked = true;
            }

            if (mouseRectangle.Intersects(rectangle))
            {
                colour = Color.Green;

                if (CurrentMouseState.LeftButton == ButtonState.Pressed) isClicked = true;
                if (CurrentMouseState.RightButton == ButtonState.Pressed) secondClicked = true;
            }
            else if (colour.G == 128)
            {
                colour = Color.White;
                if (CurrentMouseState.LeftButton == ButtonState.Released) isClicked = false;
                if (CurrentMouseState.RightButton == ButtonState.Released) secondClicked = false;
                wasClicked = false;
            }

        }
    }
}
