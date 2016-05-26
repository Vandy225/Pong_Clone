/**
 * @file PlayerPaddle.h
 * @brief Definition of the PlayerPaddle class.
 * @details This class inherits from the Paddle class, with the additional
 * feature of taking user input and updating the paddle position accordingly.
 * @author Lance Chisholm, Joshua Vandenhoek, Shaun Cullen, Eric Den Haan
 * @bug no known bugs.
 */
#ifndef __PLAYERPADDLE_H
#define __PLAYERPADDLE_H

#include "Simulator.h"
#include "Drawable.h"
#include "Updateable.h"
#include <allegro5/allegro_primitives.h>
#include "Vector.h"
#include "Point.h"
#include "Paddle.h"
#include <iostream>
	
class PlayerPaddle: public Paddle {
   
   bool UP_ARROW_PRESS, DOWN_ARROW_PRESS; /**< Represents the state of the keys, pressed or released */

   int UP_KEY; /**< Represents the ALLEGRO_KEY_CODE assigned to move the paddle up. */
   int DOWN_KEY; /**< Represents the ALLEGRO_KEY_CODE assigned to move the paddle down. */

  public:
  
    /**
     * @fn PlayerPaddle(double width, double height, double xPos, double yPos, int upkey, int downkey)
     : Paddle(width,height,xPos,yPos).
     * @brief Constructor for the PlayerPaddle class.
     * @details Constructs the PlayerPaddle object, calls the Paddle constructor with the
     * initialization list. Most important difference is the PlayerPaddle recieves the 
     * Allegro_key_code for the up key and down key.
     * 
     * @param width Size of paddle, horizontal.
     * @param height Size of paddle, vertical.
     * @param xPos Position of paddle, horizonal.
     * @param yPos Position of paddle, vertical.
     * @param upkey ALLEGRO_KEY_CODE int that the paddle moves up when pressed.
     * @param downkey ALLEGRO_KEY_CODE int that the paddle moves down when pressed.
    */
    PlayerPaddle(double width, double height, double xPos, double yPos, int upkey, int downkey)
     : Paddle(width,height,xPos,yPos){
      
      UP_ARROW_PRESS = false;
      DOWN_ARROW_PRESS = false;

      UP_KEY = upkey;
      DOWN_KEY = downkey;
   }

   /**
    * @fn move(double dt)
    * @brief Updates the paddle properties.
    * @details When the screen timer fires, the update function is called,
    * and any changes to the paddle that are required are handled here.
    * 
    * @param dt Time in seconds since last update.
    */
   void move(double dt);
   
   /**
    * @fn setUpFlag(bool key)
    * @brief Function that determines whether a key is pressed, or is released.
    * @details This function sets a flag when a key is pressed, and sets a flag
    * when the key is released. That way we know if a key is being held down without
    * constantly polling the key state.
    * 
    * @param key Boolean, key state pressed or released
    */
   void setUpFlag(bool key);
   
   /**
    * @fn setDownFlag(bool key)
    * @brief Function that determines whether a key is pressed, or is released.
    * @details This function sets a flag when a key is pressed, and sets a flag
    * when the key is released. That way we know if a key is being held down without
    * constantly polling the key state.
    * 
    * @param key Boolean, key state pressed or released
    */
   void setDownFlag(bool key);
   
   /**
   * @fn getPaddleSpeed()
   * @brief Function to retrieve the Paddle speed.
   * @details Used by Ball to get the current Paddle speed to affect the
   * resulting Ball vector after a collision with a Paddle occurs.
   * @return Vector, representing Paddle speed, x and y components.
   */
   Vector getPaddleSpeed();

   /**
   * @fn void checkKey(int, bool)
   * @brief Function used to determine which key is pressed by the user.
   * @details Takes an int and bool argument, int is the allegro_key_code constant
   * which dictates which key was pressed, the bool dictates whether the key is being pressed
   * or is being released.
   * 
   * @param int ALLEGRO_KEY_CODE constant used to determine which key was pressed 
   * @param bool true indicates button pressed, false indicates button released
   */
   void checkKey(int keyPressed, bool pressed);

};   

#endif