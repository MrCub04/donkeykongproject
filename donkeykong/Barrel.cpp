//  Created by Ryan Moran on 4/1/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.

////NOTE THAT FOR NOW USES PINK SPRITESHEET: this ended up being much simpler than trying to use two sheets

#include "Object.h"
#include "Barrel.h"
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Barrel::Barrel() : Object(12, 18, 140, 170, 0, 0, 0, 1, 0, 2, 0, 0, 100){
    setAnimation();
    floorNumber = 7;
}

void Barrel::roll(){
	if(floorNumber == 6){
		xpos += .5;
		if(xpos >= 350){
			ypos+=.025;
		}
		updateAnimation();
		if (currentState == 1 && currentFrame == 1){
			updateAnimation();
		}
		if (currentFrame == 2 && currentState == 1){
			currentState = 2;
			setAnimation();
			updateAnimation();
			updateAnimation();
		}
		if (currentState == 2 && currentFrame == 2){
			updateAnimation();
			updateAnimation();
		}
		if(currentState == 2 && currentFrame == 1){
			currentState = 1;
			setAnimation();
			updateAnimation();
		}
        
		if (xpos >= 507){
			floorNumber -=1;
		}
	}
}



void Barrel::updateAnimation(){
    oldTime = SDL_GetTicks();
    currentFrame++;
    if(currentFrame >= maxFrames) {
        currentFrame = 0;
    }
    //(*this).setAnimation();
}


//Function sets animation parameters according to state of mario
void Barrel::setAnimation(){
    switch(currentState){
        case 1: //rolling case 1
            spritesheetx = 46;
            spritesheety = 255;
            currentFrame = 0;
            maxFrames = 3;
            height = 12;
            width = 16;
            break;
        case 2: //rolling case 2
            spritesheetx = 62;
            spritesheety = 267;
            currentFrame = 0;
            maxFrames = 2;
            height = 12;
            width = 16;
            break;
        case 3: //falling barrel top row
            spritesheetx = 93;
            spritesheety = 255;
            currentFrame = 0;
            maxFrames = 1;
            height = 12;
            width = 18;
        case 4: //falling barrel bottom row
            spritesheetx = 93;
            spritesheety = 267;
            currentFrame = 0;
            maxFrames = 1;
            height = 12;
            width = 18;
    }
}
