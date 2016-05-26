/**
 *@file Net.h
 *@brief Declaration of the net class.
 *@details This class is a subclass of Paddle. The net objects act as additional barriers in the game when a score limit is reached, but
 *do not move.
 *@author Lance Chisholm, Eric DenHaan, Shaun Cullen, Joshua Vandenhoek
 *@bug no known bugs.
 */
#ifndef __NET_H
#define __NET_H

#include "Simulator.h"
#include "Drawable.h"
#include "Updateable.h"
#include "Vector.h"
#include "Point.h"
#include "Paddle.h"
#include <iostream>
	
class Net: public Paddle {
   

   double elapsedTime; /**<private member that tracks the amount of elapsed time.*/ 

  public:
   /**
    *@fn Net(double xpos, double ypos, double xsize, double ysize) : Paddle(xpos,ypos,xsize,ysize)
    *@brief Net constructor.
    *@details This takes 4 parameters and initializes the net with the parameters. Behaves very similar
    *to paddle. Sets the private data member elapsedTime to 0 as well.
    *@param xpos variable that denotes the x portion of the center point of the paddle.
    *@param ypos variable that denotes the y portion of the center point of the paddle.
    *@param xsize variable that denotes the x width of the paddle.
    *@param ysize variable that denotes the y height of the paddle.
    *@return Net object.
    */
  Net(double xpos, double ypos, double xsize, double ysize) : 
    Paddle(xpos,ypos,xsize,ysize)
    {     
      elapsedTime = 0.0;
    }

    /**
     *@fn void draw()
     *@brief function that draws the net.
     *@details This function draws a filled rectangle to the screen, which is the net.
     *@param none.
     *@return void.
     */
    void draw(){
   
       calcCornerPoints();
       al_draw_filled_rectangle(topLeftCorner.x, topLeftCorner.y,
					bottomRightCorner.x, bottomRightCorner.y,
					al_color_html("d9d9d9"));
    }

   

};   
#endif
