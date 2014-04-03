//
//  DonkeyKongGame.cpp
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

#include <SDL/SDL.h>
#include <iostream>
#include "SDL/SDL.h"
#include <string>
#include "DonkeyKongGame.h"
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"
#include "Barrel.h"
#include "math.h"
#include <stdlib.h>
#include <time.h>
//#include "SDL/SDL_mixer.h"
//#include "SDL_image/SDL_image.h"
//include "SDL_ttf/SDL_ttf.h"

using namespace std;


SDL_Event event;
//The music that will be played
//Mix_Music *music = NULL;

//Constructor for DonkeyKongGame, initializes SDL, creates screen, and loads background
DonkeyKongGame::DonkeyKongGame ()
{
    SDL_Init (SDL_INIT_EVERYTHING);
    // SDL_Color textColor = { 255, 255, 255 }; // it's white for now, color of text
    screen = SDL_SetVideoMode (550, 471, 32, SDL_SWSURFACE);
    background = SDL_LoadBMP ("/Users/jgavin/Documents/donkeykong/donkeykong/DonkeyKongBackground.bmp");
    
    // TTF_Font *font;
    // font = TTF_OpenFont( "kongtext.ttf", 36 ); //size 12 font
    // message = TTF_RenderText_Solid( font, "Current Score:", textColor );
    mario.initializeFloors ();
}


void DonkeyKongGame::Music ()
{
    
    // Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    //  music = Mix_LoadMUS( "intro.wav" );
    //  Mix_PlayMusic(music, -1);
}

//Display function which puts background and all objects on screen
void DonkeyKongGame::Display ()
{
    
    SDL_FillRect (screen, &screen->clip_rect,
                  SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));
    
    //Apply image to screen
    SDL_BlitSurface (background, NULL, screen, NULL);
    
    if (mario.getclimbing () == 0)
    {
        mario.display (screen, mario.getMarioSurface (), mario.getxpos (),
                       mario.getypos (),
                       mario.getspritesheetx () +
                       mario.getcurrentframe () * mario.getwidth (),
                       mario.getspritesheety (), mario.getwidth (),
                       mario.getheight ());
    }
    if (mario.getclimbing () == 1)
    {
        mario.climbingdisplay (screen, mario.getMarioSurface (),
                               mario.getxpos (), mario.getypos (),
                               mario.getspritesheetx () +
                               mario.getcurrentframe () * mario.getwidth () * 2,
                               mario.getspritesheety (), mario.getwidth (),
                               mario.getheight ());
    }
    
    peach.display (screen, peach.getMarioSurface (), peach.getxpos (),
                   peach.getypos (),
                   peach.getspritesheetx () +
                   peach.getcurrentframe () * peach.getwidth (),
                   peach.getspritesheety (), peach.getwidth (),
                   peach.getheight ());
    
    donkeykong.display (screen, donkeykong.getMarioSurface (),
                        donkeykong.getxpos (), donkeykong.getypos (),
                        donkeykong.getspritesheetx () +
                        donkeykong.getcurrentframe () * donkeykong.getwidth (),
                        donkeykong.getspritesheety (), donkeykong.getwidth (),
                        donkeykong.getheight ());
    
    barrel.display(screen, barrel.getMarioSurface(), barrel.getxpos(), barrel.getypos(), barrel.getspritesheetx() + barrel.getcurrentframe()*barrel.getwidth(), barrel.getspritesheety(), barrel.getwidth(), barrel.getheight());
    
    
    SDL_Flip (screen);
    
}

//Function to clean up game when over
void DonkeyKongGame::cleanUp ()
{
    
    //Free the loaded image
    //SDL_FreeSurface( screen );
    SDL_FreeSurface (background);
    SDL_FreeSurface (message);
    mario.cleanUp ();
    // Mix_FreeMusic( music );
    
    //Quit SDL Mixer
    //  Mix_CloseAudio();
    //Quit SDL
    SDL_Quit ();
}

//Function to create gameplay
void DonkeyKongGame::playDonkeyKong ()
{
    bool quit = false;
    int counter = 0;
    Display ();
    Music ();
    srand (time(NULL));
    while (quit == false)
    {
        //cout << "onFloor = " << mario.onFloor << endl;
        if (mario.getoldtime () + mario.getframerate () < SDL_GetTicks ())
        {
            mario.updateAnimation ();
        }
        if ((peach.getoldtime () + peach.getframerate () < SDL_GetTicks ())
            && (counter % 5) == 0)
        {
            peach.updateAnimation ();
            if (counter % 30 == 0 && peach.currentState == 1)
            {
                peach.currentState = 2;
                peach.setAnimation ();
            }
            else if (counter % 30 == 0 && peach.currentState == 2)
            {
                peach.currentState = 1;
                peach.setAnimation ();
            }
        }
        if ((donkeykong.currentState == 3 && donkeykong.currentFrame == 2) || (donkeykong.currentState == 2 && donkeykong.currentFrame == 0))
        {
            if (rand() % 10 + 1 >= 3 && donkeykong.currentState != 3 && counter % 100 == 0)
            {
                donkeykong.currentState = 3;
                donkeykong.setAnimation();
            }
            else if (donkeykong.currentState != 2 && counter % 100 == 0)
            {
                donkeykong.currentState = 2;
                donkeykong.setAnimation();
            }
        }
        if (counter % 100 == 0 && donkeykong.currentState == 2)
        {
            if (donkeykong.currentFrame == 0)
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
            else
            {
                donkeykong.updateAnimation ();
            }
            
        }
        if (counter % 100 == 0 && donkeykong.currentState == 3)
        {
            if (donkeykong.currentFrame == 2)
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
            else if (donkeykong.currentFrame == 0)
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
            else if (donkeykong.currentFrame == 3)
            {
                barrel.currentState = 1;
                barrel.currentFrame = 2;
                barrel.updateAnimation();
                barrel.updateAnimation();
                barrel.floorNumber = 6;
                
                if (rand() % 10 + 1 >= 4 || mario.getypos() <= 250)
                {
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                }
                else
                {
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                    donkeykong.updateAnimation ();
                }
            }
            else
            {
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
                donkeykong.updateAnimation ();
            }
        }
        while (SDL_PollEvent (&event))
        {
            mario.checkOnFloor ();
            if (mario.getoldtime () + mario.getframerate () < SDL_GetTicks ())
            {
                mario.updateAnimation ();
            }
            //Handle events for Mario
            mario.handle_input (event);
            //If the user has Xed out the window
            if (event.type == SDL_QUIT)
            {
                //Quit the program
                quit = true;
            }
            mario.updateAnimation ();
        }
        counter += 1;
        barrel.roll();
        mario.move ();
        mario.checkOnFloor ();
        Display ();
    }
    SDL_Quit ();
}
