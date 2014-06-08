using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace DominoCsharp
{
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;                             //narzêdzia rysowania
        SpriteBatch spriteBatch;

        MouseState currentMouseState, previousMouseState;           //stan przycisków myszki

        enum GameState                                              //dwa g³ówne mo¿liwe stany gry
        {
            Start,
            Playing,
        }
        GameState CurrentGameState = GameState.Start;              

        Button Play, NewBlock, ArrowL, ArrowR;                      //tworzenie przycisków na ekranie
        
        Jackpot pot = new Jackpot();                                //tworzenie obiektów, liczników i flag
        Game game = new Game();
        Player player1 = new Player();
        Player player2 = new Player();

        Song backgroundMusic;

        int pot_count;
        int chain_count;

        bool wrongMove;
        bool win;
        bool zero, nomove1, nomove2;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";

            graphics.PreferredBackBufferWidth = 1280;
            graphics.PreferredBackBufferHeight = 800;
        }

        protected override void Initialize()
        {
            base.Initialize();
        }

        protected override void LoadContent()
        {            
            spriteBatch = new SpriteBatch(GraphicsDevice);

            backgroundMusic = Content.Load<Song>("music");

            MediaPlayer.Play(backgroundMusic);                  //zapêtlona muzyka w tle 
            MediaPlayer.IsRepeating = true;
            
            IsMouseVisible = true;
            
            Play = new Button(Content.Load<Texture2D>("button"), graphics.GraphicsDevice);                  //inicjalizacja przycisków 
            Play.setPosition(new Vector2(700,400));
            NewBlock = new Button(Content.Load<Texture2D>("newblock"), graphics.GraphicsDevice);
            NewBlock.setSize(new Vector2(100, 50));
            NewBlock.setPosition(new Vector2(900, 350));
            ArrowL = new Button(Content.Load<Texture2D>("arrow"), graphics.GraphicsDevice);
            ArrowL.setPosition(new Vector2(470, 420));
            ArrowL.setSize(new Vector2(50, 50));
            ArrowR = new Button(Content.Load<Texture2D>("arrow"), graphics.GraphicsDevice);
            ArrowR.setPosition(new Vector2(1070, 420));
            ArrowR.setSize(new Vector2(50, 50));
            Block.LoadBlock(Content.Load<Texture2D>("blocks"), graphics.GraphicsDevice);
        }

        protected override void UnloadContent() {}

        protected override void Update(GameTime gameTime)
        {
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();
            
            currentMouseState = Mouse.GetState();                       //stan klawiszy i przycisków myszki w danej klatce
            KeyboardState keyboard = Keyboard.GetState();

            switch (CurrentGameState)
            {
                case GameState.Start:
                    if (Play.isClicked == true)                           //tworzenie nowej gry
                    {
                        game = new Game();
                        pot = new Jackpot();
                        player1 = new Player();
                        player2 = new Player();
                        
                        pot.Shuffle();                                  //tasowanie klocków w puli
                        player1.DrawBlocks(1, pot);                     //przyporz¹dkowywanie pierwszych 14 klocków graczom 
                        player2.DrawBlocks(2, pot);
                        player1.set_player(player2);                    //gracz nr 1. jest pierwszy
                        
                        pot_count = 14;                                 //wykorzystane ju¿ klocki z puli na starcie - 14
                        chain_count = 0;                                //na pocz¹tku ³añcuch jest pusty

                        wrongMove = false;
                        win = false;
                        nomove1 = false;
                        nomove2 = false;
                        zero = false;

                        CurrentGameState = GameState.Playing;
                    }
                    Play.Update(currentMouseState, previousMouseState);
                    break;

                case GameState.Playing:

                    if (player1.get_block_count() != 0 && player2.get_block_count() != 0)       //gra trwa dopóki któryœ z talonów nie jest pusty
                    {
                        NewBlock.Update(currentMouseState, previousMouseState);
                    
                        if (NewBlock.wasClicked == true && NewBlock.canClick == true)           //losowanie nowego klocka
                        {
                            if (player1.get_activity())
                            {
                                player1.AddBlock(1, pot, pot_count);                //dodawanie od razu do talonu
                                ArrowL.canClick = true;
                            }
                            else if (player2.get_activity())
                            {
                                player2.AddBlock(2, pot, pot_count);
                                ArrowR.canClick = true;
                            }

                            pot_count++;

                            NewBlock.canClick = false;
                        }

                        if (ArrowL.wasClicked == true && ArrowL.canClick == true)
                        {
                            player1.MoveDown(1);                //zachowywanie klocka w talonie i przesuwanie go w dó³
                            NewBlock.canClick = true;
                            ArrowL.canClick = false;
                        }

                        if (ArrowR.wasClicked == true && ArrowR.canClick == true)
                        {
                            player2.MoveDown(2);
                            NewBlock.canClick = true;
                            ArrowR.canClick = false;
                        }

                        if (player1.get_activity())
                        {
                            ArrowL.Update(currentMouseState, previousMouseState);           //strza³ki dodawania aktywne gdy odpowiedni gracz aktywny
                            
                            for (int i = 0; i < player1.get_block_count(); i++)
                            {
                                player1.get_talon(i).Update(currentMouseState, previousMouseState);             //klocki odpowiedniego gracza aktywne 
                            }

                            for (int i = 0; i < player1.get_block_count(); i++)               //obracanie klocków
                            {
                                if (player1.get_talon(i).secondClicked == true)
                                {
                                    player1.get_talon(i).InvertBlock();
                                    player1.get_talon(i).secondClicked = false;
                                    Thread.Sleep(100);
                                }
                            }

                            for (int i = 0; i < player1.get_block_count(); i++)             //dodawanie klocków do ³añcucha
                            {
                                if (player1.get_talon(i).isClicked == true)
                                {

                                    if ((chain_count != 0 && game.get_chain(chain_count - 1).Compare(player1.get_talon(i)) == true) || chain_count == 0)
                                    {
                                        game.AddToChain(chain_count, player1.get_talon(i));
                                        player1.Delete(chain_count, i, 1);
                                        player2.set_player(player1);

                                        chain_count++;
                                        NewBlock.canClick = true;
                                    }
                                    else wrongMove = true;          // komunikat o z³ym ruchu
                                }
                            }
                        }

                        if (player2.get_activity())
                        {
                            ArrowR.Update(currentMouseState, previousMouseState);
                            
                            for (int i = 0; i < player2.get_block_count(); i++)
                            {
                                player2.get_talon(i).Update(currentMouseState, previousMouseState);
                            }
                            
                            for (int i = 0; i < player2.get_block_count(); i++)
                            {
                                if (player2.get_talon(i).secondClicked == true)
                                {
                                    player2.get_talon(i).InvertBlock();
                                    player2.get_talon(i).secondClicked = false;
                                    Thread.Sleep(100);
                                }
                            }

                            for (int i = 0; i < player2.get_block_count(); i++)
                            {
                                if (player2.get_talon(i).isClicked == true)
                                {

                                    if ((chain_count != 0 && game.get_chain(chain_count - 1).Compare(player2.get_talon(i)) == true) || chain_count == 0)
                                    {
                                        game.AddToChain(chain_count, player2.get_talon(i));
                                        player2.Delete(chain_count, i, 2);
                                        player1.set_player(player2);

                                        chain_count++;
                                        NewBlock.canClick = true;
                                    }
                                    else wrongMove = true;
                                }
                            }
                        }

                        if (pot_count == 28)            //warianty rozstrzygniêæ po wyczerpaniu puli
                        {
                            zero = true;
                            NewBlock.canClick = false;

                            int moves1 = 0;
                            int moves2 = 0;

                            for (int i = 0; i < player1.get_block_count(); i++)
                            {
                                if (game.get_chain(chain_count - 1).Compare(player1.get_talon(i)) == true)
                                    moves1++;
                                if (game.get_chain(chain_count - 1).CompareInversed(player1.get_talon(i)) == true)
                                    moves1++;
                            }

                            for (int i = 0; i < player2.get_block_count(); i++)
                            {
                                if (game.get_chain(chain_count - 1).Compare(player2.get_talon(i)) == true)
                                    moves2++;
                                if (game.get_chain(chain_count - 1).CompareInversed(player2.get_talon(i)) == true)
                                    moves2++;
                            }

                            if (player1.get_activity() && moves1 == 0)
                            {
                                player2.set_player(player1);
                                Thread.Sleep(300);
                            }

                            if (player2.get_activity() && moves2 == 0)
                            {
                                player1.set_player(player2);
                                Thread.Sleep(300);
                            }

                            if (moves1 == 0 && moves2 == 0)
                            {
                                int sum1 = 0;
                                int sum2 = 0;
                                for (int i = 0; i < player1.get_block_count(); i++)
                                    sum1 = sum1 + player1.get_talon(i).Sum();
                                for (int i = 0; i < player2.get_block_count(); i++)
                                    sum2 = sum2 + player2.get_talon(i).Sum();

                                if (sum1 < sum2)
                                    nomove1 = true;
                                else if (sum1 > sum2) nomove2 = true;
                            }
                        }

                    }
                    else win = true;
                    
                    if(keyboard.IsKeyDown(Keys.Back))           //powrót do ekranu startowego przez "Backspace"
                        CurrentGameState = GameState.Start;

                    break;
      
            }

            if (keyboard.IsKeyDown(Keys.Escape)) Exit();        //wyjœcie przez "Escape"
            
            previousMouseState = currentMouseState;         //przechowywanie stanu przycisku myszki z poprzedniej klatki

            base.Update(gameTime);
        }

        

        protected override void Draw(GameTime gameTime)
        {
            

            spriteBatch.Begin();
            
            switch (CurrentGameState)
            {
                case GameState.Start:
                    spriteBatch.Draw(Content.Load<Texture2D>("start"), new Rectangle(0, 0, 1280, 800), Color.White);    //rysowanie t³a
                    Play.Draw(spriteBatch);
                    break;

                case GameState.Playing:
                    spriteBatch.Draw(Content.Load<Texture2D>("background"), new Rectangle(0, 0, 1280, 800), Color.White);
                    NewBlock.Draw(spriteBatch);
                    ArrowL.Draw(spriteBatch);
                    ArrowR.Draw(spriteBatch);
                    

                    player1.DrawTalon(spriteBatch);         //rysowanie klocków graczy
                    player2.DrawTalon(spriteBatch);

                    game.DrawChain(spriteBatch, chain_count);   //rysowanie ³añcucha

                    if (wrongMove == true)                      //wyœwietlanie komunikatów
                    {
                        game.WrongMove(Content.Load<Texture2D>("wrongmove"), spriteBatch);
                        wrongMove = false;
                    }

                    if (win == true)
                        spriteBatch.Draw(Content.Load<Texture2D>("youwon"), new Vector2(470, 350), Color.White);

                    if(zero == true)
                        spriteBatch.Draw(Content.Load<Texture2D>("zero"), new Vector2(1000, 350), Color.White);

                    if (nomove1 == true)
                        spriteBatch.Draw(Content.Load<Texture2D>("nomove1"), new Vector2(470, 350), Color.White);

                    if(nomove2 == true)
                        spriteBatch.Draw(Content.Load<Texture2D>("nomove2"), new Vector2(470, 350), Color.White);

                    break;
            }
                                    
            spriteBatch.End();

            base.Draw(gameTime);
        }

    }
}
