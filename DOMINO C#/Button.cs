using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace DominoCsharp
{
    class Button                            //obsługa kliknięć i podświetleń przycisków
    {
        Texture2D texture;
        Vector2 position;
        Rectangle rectangle;

        Color colour = Color.White;
        public Vector2 size;

        public Button(Texture2D newTexture, GraphicsDevice graphics)
        {
            texture = newTexture;

            size = new Vector2(300, 140);
        }

        public bool isClicked;
        public bool wasClicked;

        public bool canClick = true;
        public void Update(MouseState CurrentMouseState, MouseState PreviousMouseState)
        {
            rectangle = new Rectangle((int)position.X, (int)position.Y,
                (int)size.X, (int)size.Y);

            Rectangle mouseRectangle = new Rectangle(CurrentMouseState.X, CurrentMouseState.Y, 1, 1);


            if (CurrentMouseState.LeftButton == ButtonState.Pressed && PreviousMouseState.LeftButton == ButtonState.Released)
            {
                if (mouseRectangle.Intersects(rectangle))
                    wasClicked = true;
            }

                
            if (mouseRectangle.Intersects(rectangle))
            {
                colour=Color.DarkRed;
                
                if (CurrentMouseState.LeftButton == ButtonState.Pressed) isClicked = true;         
            }
            else if (colour.R == 139)
            {
                colour = Color.White;
                if (CurrentMouseState.LeftButton == ButtonState.Released) isClicked = false;
                wasClicked = false;
            }
        }

        public void setPosition(Vector2 newPosition)
        {
            position = newPosition;
        }

        public void Draw(SpriteBatch spriteBatch)
        {
            spriteBatch.Draw(texture, rectangle, colour);
        }

        public void setSize(Vector2 newSize)
        {
            size = newSize;
        }
    }
}
