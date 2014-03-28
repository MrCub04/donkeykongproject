//
//  DonkeyKong.cpp
//  donkeykong
//
//  Created by Jacob Gavin on 3/27/14.
//  Copyright (c) 2014 Jacob Gavin. All rights reserved.
//

//
//  DonkeyKong.cpp
//  SDL_Tutorial
//
//  Created by Ryan Moran on 3/26/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.
//

#include "Object.h"
#include "DonkeyKong.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
DonkeyKong::DonkeyKong() : Object(33, 43, 94, 150, 0, 0, 0, 1, 1, 2, 0, 0, 100){
    setAnimation();
}

void DonkeyKong::updateAnimation(){
    oldTime = SDL_GetTicks();
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
    //(*this).setAnimation();
}


//Function sets animation parameters according to state of mario
void DonkeyKong::setAnimation(){
    switch(currentState){
        case 1: //standing still
            spritesheetx = 105;
            spritesheety = 150;
            currentFrame = 1;
            maxFrames = 1;
            height = 33;
            width = 47;
            break;
        case 2: //left hand raise
            spritesheetx = 154;
            spritesheety = 149;
            currentFrame = 1;
            maxFrames = 2;
            height = 33;
            width = 43;
            break;
    }
}