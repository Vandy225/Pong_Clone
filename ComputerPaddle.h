/**
 * @file ComputerPaddle.h
 * @brief Definition of the ComputerPaddle class.
 * This class is similar to PlayerPaddle but is fed the current Ball
 * position and moves the paddle automatically to track the Ball. This
 * creates a CPU opponent for our Pong game.
 * @author Lance Chisholm, Joshua Vandenhoek, Eric Den Haan, Shaun Cullen
 * @bug Movement is jerky, does not track on right side of screen, if second 
 * ComputerPaddle is added, so there are 2 ComputerPaddles
 */

#ifndef __COMPUTERPADDLE_H
#define __COMPUTERPADDLE_H

#include "Simulator.h"
#include "Drawable.h"
#include "Updateable.h"
#include "Vector.h"
#include "Point.h"
#include "Paddle.h"
#include <iostream>
	

class ComputerPaddle: public Paddle {
   
  Point currentBallPos; /**< Represents the current ball position */
  double elapsedTime; /**< Represents the total elapsed time over many updates */

  public:
  /**
   * @fn ComputerPaddle(double width, double height, double xPos, double yPos) : 
   * Paddle(width,height,xPos,yPos)
   * @brief Constructor for the ComputerPaddle class with initialization list
   * for Paddle base class.
   * @details This constructor initializes the base class Paddle based on the input
   * arguments. elapsedTime is set to 0.0, and currentBallPos is set to (400.0, 300.0).
   * 
   * @param width Paddle width in pixels.
   * @param height Paddle height in pixels.
   * @param xPos Paddle horizontal position, centroid, from left side of screen.
   * @param yPos Paddle vertical position, centroid, from top of screen.
   */
  ComputerPaddle(double width, double height, double xPos, double yPos) : 
    Paddle(width,height,xPos,yPos)
    {
      Point startingPoint = Point(400.0,300.0);
      currentBallPos = startingPoint;
      elapsedTime = 0.0;
    }
    /**
     * @fn void draw()
     * @brief Describes how a paddle is drawn. Implemented in Paddle class.
     * @details This uses allegro primitive drawing functions to handle how
     * a paddle appears on screen. Implementation in Paddle class.
     */
    void draw();
    
    /**
     * @fn void move(double dt)
     * @brief Describes how the paddle should change after each update.
     * @details This takes an argument dt which is the time in seconds since
     * the last call to move. This function handles any changes in position 
     * or attributes that the paddle needs to make.
     * 
     * @param dt Time since last update.
     */
    void move(double dt);
    
    /**
     * @fn Vector getPaddleSpeed()
     * @brief Returns the paddle's current speed as a Vector.
     * @details This function returns the paddle's current speed so that
     * the Ball class knows how to alter the speed of the Ball based on 
     * a collision with a paddle.
     * @return Vector returned is the paddle speed as a Vector.
     */
    Vector getPaddleSpeed();
    
    /**
     * @fn getBallPosition(Point ballPos)
     * @brief This function is for setting Ball position. It takes a position
     * and sets the paddle proptery currentBallPos based on it.
     * @details Despite the function looking like a getter method, in actuality
     * it is a setter function that is used to retrieve the Ball position and track
     * it.
     * 
     * @param ballPos Ball position as a Point.
     */
    void getBallPosition(Point ballPos);
  
};   
#endif
