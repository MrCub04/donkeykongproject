//
//  DonkeyKongGame.h
//  donkeykong
//
//  Created by Jacob Gavin on 3/19/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//  Highest class for game

#ifndef DONKEYKONGGAME_H
#define DONKEYKONGGAME_H

#include "Floor.h"
#include <SDL/SDL.h>
#include "Object.h"
#include "Mario.h"
#include "Peach.h"
#include "DonkeyKong.h"
#include "Barrel.h"
#include "Hammer.h"
#include <vector>

class DonkeyKongGame{
    
public:
    
    DonkeyKongGame();
    
    SDL_Surface* OnLoad(char*); //Function to load game background
    
    void Display(); //Renders all of the game objects and background onto the screen
    
    void Music();
    
    void cleanUp(); //Cleans up all of the object in the game when it is finished
    
    void playDonkeyKong(); //Initiates gameplay and calls all other functions
    
    void applyBackground(int, int, SDL_Surface*, SDL_Surface*);
    
    void initializeFloors();
    
    int checkOnFloor(int, int, int, int);
    
    int checkForCollisions();
    
private:
    
    SDL_Surface* screen;//Screen surface
    SDL_Surface* background;//Surface for game background
    SDL_Surface *message;
    
    Mario mario;//Mario object
    Peach peach; //Peach object
    DonkeyKong donkeykong; //donkeykong object
    Hammer hammer;
    vector<Barrel> barrels; //Barrel object
    
};

#endif
