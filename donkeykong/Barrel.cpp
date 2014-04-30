//  Created by Ryan Moran on 4/1/14.
//  Copyright (c) 2014 Ryan Moran. All rights reserved.


#include "Object.h"		//using inheritance so that object functions are accessible
#include "Barrel.h"		//include header file for barrel class
#include <math.h>
#include <iostream>


using namespace std;

//Constructor, sets parameters and loads surface
Barrel::Barrel ():Object (12, 18, 140, 170, 0, 0, 0, 1, 0, 2, 0, 0, 100)
{
  setAnimation ();
  floorNumber = 6;		//barrel always starts on top floor where donkey kong is
  climbing = 0;
  initializeFloors ();
  hitOil = 0;			//barrel has not hit the oil can on the bottom floor yet
  alive = 1;			//barrel is alive and has not been destroyed by oil can or by hammer
  speedBoost = 0;
}

//function to control movement of barrel object on screen
void
Barrel::move ()
{
  if (type == 1)		//barrel type 1 is rolling down a floor
    {
      //Set a dt variable and variable for gravity
      double dt = .2;
      ay = 1;
      if (vx > 0)
	vx = vx + speedBoost;	//update speed based on level (determines speedboost)
      if (vx < 0)
	vx = vx - speedBoost;
      if (climbing == 0)
	{
	  vx += (ax * dt);
	  vy += (ay * dt);
	  xpos += (vx * dt);
	  ypos += (vy * dt);
	}

      if (xpos <= 0)
	{
	  xpos = 2;
	  vx = 0;
	}

      if (xpos >= 531)
	{
	  xpos = 529;
	  vx = 0;
	}

      if (ypos <= 49)
	{
	  ypos = 50;
	  vy = 0;
	}
    }
  else				//covers other two barrel types: dropped straight down by dk and those that randomly fall down ladders after rolling
    {
      double dt = .1;
      ay = .3;
      vy += (ay * dt);
      ypos += (vy * dt);
    }
}

//function that calls move to physically move a barrel and animates its rolling by calling updateAnimation();
void
Barrel::roll ()
{
  if (type == 1)		//a barrel rolling horizontally on the floors
    {
      //series of if statements to cover a rolling barrel on specific floors
      if (floorNumber == 6)
	{
	  ax = 0;
	  vx = 1;		//student machine vx = 1.5
	  move ();		//moves the barrel on the screen
	  //series of if statements to flip to the next correct spritesheet frame
	  updateAnimation ();
	  if (currentState == 1 && currentFrame == 1)
	    {
	      updateAnimation ();
	    }
	  if (currentFrame == 2 && currentState == 1)
	    {
	      currentState = 2;
	      setAnimation ();
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 2)
	    {
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 1)
	    {
	      currentState = 1;
	      setAnimation ();
	      updateAnimation ();
	    }
	}
      else if (floorNumber == 5)
	{
	  vx = -1;
	  move ();
	  updateAnimation ();
	  if (currentState == 1 && currentFrame == 1)
	    {
	      updateAnimation ();
	    }
	  if (currentFrame == 2 && currentState == 1)
	    {
	      currentState = 2;
	      setAnimation ();
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 2)
	    {
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 1)
	    {
	      currentState = 1;
	      setAnimation ();
	      updateAnimation ();
	    }
	}
      else if (floorNumber == 4)
	{
	  vx = 1;
	  move ();
	  updateAnimation ();
	  if (currentState == 1 && currentFrame == 1)
	    {
	      updateAnimation ();
	    }
	  if (currentFrame == 2 && currentState == 1)
	    {
	      currentState = 2;
	      setAnimation ();
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 2)
	    {
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 1)
	    {
	      currentState = 1;
	      setAnimation ();
	      updateAnimation ();
	    }
	}
      else if (floorNumber == 3)
	{
	  vx = -1;
	  move ();
	  updateAnimation ();
	  if (currentState == 1 && currentFrame == 1)
	    {
	      updateAnimation ();
	    }
	  if (currentFrame == 2 && currentState == 1)
	    {
	      currentState = 2;
	      setAnimation ();
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 2)
	    {
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 1)
	    {
	      currentState = 1;
	      setAnimation ();
	      updateAnimation ();
	    }
	}
      else if (floorNumber == 2)
	{
	  vx = 1;
	  move ();
	  updateAnimation ();
	  if (currentState == 1 && currentFrame == 1)
	    {
	      updateAnimation ();
	    }
	  if (currentFrame == 2 && currentState == 1)
	    {
	      currentState = 2;
	      setAnimation ();
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 2)
	    {
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 1)
	    {
	      currentState = 1;
	      setAnimation ();
	      updateAnimation ();
	    }
	}
      else if (floorNumber == 1)
	{
	  vx = -1;
	  move ();
	  if (xpos > 267)
	    {
	      ypos += .025;
	    }
	  updateAnimation ();
	  if (currentState == 1 && currentFrame == 1)
	    {
	      updateAnimation ();
	    }
	  if (currentFrame == 2 && currentState == 1)
	    {
	      currentState = 2;
	      setAnimation ();
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 2)
	    {
	      updateAnimation ();
	      updateAnimation ();
	    }
	  if (currentState == 2 && currentFrame == 1)
	    {
	      currentState = 1;
	      setAnimation ();
	      updateAnimation ();
	    }

	  if (xpos <= 23)
	    {
	      currentState = 1;
	      setAnimation ();
	    }
	}
    }
  else
    {
      move ();
      if (currentState == 3)
	{
	  currentState = 4;
	}
      else
	{
	  currentState = 3;
	}
      setAnimation ();
    }
}

//Function updates animation frames from spite sheet
void
Barrel::updateAnimation ()
{
  oldTime = SDL_GetTicks ();
  currentFrame++;
  if (currentFrame >= maxFrames)
    {
      currentFrame = 0;
    }
}


//Function sets animation parameters according to state of barrel
void
Barrel::setAnimation ()
{
  switch (currentState)
    {				//our spritesheet had barrel animations split between two rows so each situation has two cases, one for each row
    case 1:			//rolling case 1
      spritesheetx = 46;
      spritesheety = 256;
      currentFrame = 0;
      maxFrames = 3;
      height = 12;
      width = 16;
      break;
    case 2:			//rolling case 2
      spritesheetx = 62;
      spritesheety = 268;
      currentFrame = 0;
      maxFrames = 2;
      height = 12;
      width = 16;
      break;
    case 3:			//falling barrel top row
      spritesheetx = 93;
      spritesheety = 250;
      currentFrame = 0;
      maxFrames = 1;
      height = 12;
      width = 18;
    case 4:			//falling barrel bottom row
      spritesheetx = 93;
      spritesheety = 258;
      currentFrame = 0;
      maxFrames = 1;
      height = 12;
      width = 18;
    }
}
