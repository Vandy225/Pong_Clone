/**
 *@file Ball.h
 *@brief Definition of the ball class.
 *@details This class is responsible for creating ball objects. The ball is the main object
 *that players will interact with during gameplay, besides the paddles. This class
 *contains functions that dictate the ball's behaviour with respect to movement and collision,
 *as well as getter/setter methods.
 *@author Lance Chisholm, Shaun Cullen, Joshua Vandenhoek, Eric DenHaan
 *@bug collision periodically demonstrates odd behaviour, especially with paddle corner collisions 
 */

#ifndef BALL_H
#define BALL_H

#include "Drawable.h"
#include "Updateable.h"
#include "Audio.h"
#include "Vector.h"
#include "Point.h"
#include "Paddle.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Ball: public Drawable, public Updateable, public Audio{
   Point origin; /**< Point object representing the center of the ball. */
   int radius;   /**< int that describes the radius of the ball. */
   Vector speed; /**< Vector object that describes the speed of the ball at a given point in time.*/
   float timeE = 0; /**< float that tracks the time elapsed since an update was made. */
   float timecheck = 0.5; /**< float that is set at 0.5 to be compared with timeE.*/
   Vector maxSpeed = Vector(700,700); /**< Vector object that represents the maximum speed a ball can have.*/
   Vector minSpeed = Vector(300,0); /**< Vector object that represents the minimum speed a ball can have.*/
   int buffer = 0; /**< int that is used in collision checking that can change how collisions are evaluated.*/
   bool F = true; /**< boolean variable that stops the ball from scoring when the game is started. Designed to freeze the ball for 3 seconds before starting the game.*/
		  
   
  public:

   /**
    *@fn Ball(float xx, float yy, float r,Vector V) : origin(xx,yy), radius(r)
    *@brief Constructor for the ball objects.
    *@details This constructor takes in 4 parameters and constructs a ball based on the input parameters.
    *@param xx float value that represents the x coordinate of the center of the ball.
    *@param yy float value that represents the y coordinate of the center of the ball.
    *@param r float value that represents the radius of the ball.
    *@param V Vector object that represents the initial speed that the ball has upon creation.
    *@return Ball object initialized with parameters.
    */
  Ball(float xx, float yy, float r,Vector V) : origin(xx,yy), radius(r){
      speed = V;
   }

   /**
    *@fn void move(double dt)
    *@brief Function dictating the movement of the ball.
    *@details This function is responsible for moving the ball around the screen.
    *@param dt double that represents the difference in time between two events. Used to determine if the ball should move or not.
    *@return void.
    */
   void move(double dt);

   /**
    *@fn void HorzBounce()
    *@brief function that dictates the behaviour of the ball on a horizontal bounce.
    *@details This function affects the vector of the ball object and reverses it in the x direction.
    *Basically just reflects the ball back on its original y vector but inverted x.
    *@param none.
    *@return void.
    */
   void HorzBounce();   

   /**
    *@fn void HorzBounce()
    *@brief function that dictates the behaviour of the ball on a vertical bounce.
    *@details This function affects the vector of the ball object and reverses it in the y direction.
    *Basically just reflects the ball back on its original x vector but inverted y.
    *@param none.
    *@return void
    */
   void VertBounce();
   
   /**
    *@fn Point GetPos()
    *@brief getter method for the position of the center of the ball
    *@details This function is a getter method for the position of the ball.
    *@param none.
    *@return Point object that represents the center of the ball object at a given point in time.
    */
   Point GetPos();
   
   /**
    *@fn Vector getBallSpeed()
    *@brief getter method for the speed of the ball at a given point in time.
    *@details This function is a getter method for the speed of the ball at a given point in time.
    *@param none.
    *@return Vector object representing the speed of the ball at a given point in time.
    */
   Vector getBallSpeed();

   /**
    *@fn int getRadius()
    *@brief getter method for the radius of the ball.
    *@details This function is a getter method that returns the radius of a ball object.
    *@param none.
    *@return int that denotes the radius of the ball.
    */
   int getRadius();

   /**
    *@fn void resetBall()
    *@brief function to reset the position of the ball after scoring.
    *@details This function resets the ball's origin to the center of the screen and sets its speed to be a random vector.
    *@param none.
    *@return void.
    */
    
   void resetBall();

   /**
    *@fn void draw()
    *@brief function that makes the ball appear on screen.
    *@details This function uses the allegro function to draw a filled circle to the screen. This allows the ball to be seen.
    *@param none.
    *@return void.
    */
   void draw();

   /**
    *@fn void collisionCheck()
    *@brief function that checks if a collision is occurring between the ball and a paddle.
    *@details This function evaluates a double dt and a paddle reference to determine if it is currently colliding
    *with a paddle. If a collision is occurring, then the ball's vector is altered according to what kind of collision occurred
    *(left, right, top, bottom).
    *@param none.
    *@return void.
    */
   void collisionCheck(double dt, Paddle& paddle);

   
};
   
#endif   
