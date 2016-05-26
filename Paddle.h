/**
 * @file Paddle.h
 * @brief Definition of the Paddle class.
 * @details This class is responsible for creating Paddle objects. 
 * This is the base class for the ComputerPaddle and PlayerPaddle objects,
 * which interact with the Ball class.
 * @author Lance Chisholm, Joshua Vandenhoek, Shaun Cullen, Eric Den Haan
 * @bug No known bugs
 */

#ifndef PADDLE_H
#define PADDLE_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include "Drawable.h"
#include "Updateable.h"
#include "Point.h"
#include "Vector.h"

class Paddle: public Drawable, public Updateable {
  public:
  
    Point origin; /**< Represents current position of Paddle in Point form, centroid */
    Point size; /**< Represents current size of Paddle in Point form x=width, y=height*/
    Point topLeftCorner; /**< Represents top left corner of Paddle in Point form */
    Point bottomRightCorner; /**< Represents bottom right corner of Paddle in Point form */
    Vector paddleSpeed; /**< Represents paddle speed in Vector form */

    /**
     * @fn Paddle(double xsize, double ysize, double xpos, double ypos)
     * : size(xsize,ysize), origin(xpos,ypos), paddleSpeed(0,0)
     * @brief Constructor for Paddle class.
     * @details Constructs paddle object with basic input of width, height, xpos,
     * ypos, and calls the appropriate point and vector constructors for size
     * origin, and paddleSpeed. calcCornerPoints() is called to generate the topleft and bottomright
     * based on the input of the origin and size.
     * 
     * @param xsize The width of the paddle in pixels.
     * @param ysize The height of the paddle in pixels.
     * @param xpos The position of the paddle, centroid, from the left edge of screen.
     * @param ypos The position of the paddle, centroid, from the top edge of screen.
     * 
     */
  Paddle(double xsize, double ysize, double xpos, double ypos)
     : size(xsize,ysize), origin(xpos,ypos), paddleSpeed(0,0){

    calcCornerPoints();

  } 
  

   /**
     * @fn void draw()
     * @brief This is the virtual function for displaying the paddle.
     * @details This function dictates how the paddle is drawn by allegro
     * primitives. It has a basic implementation which describes a default
     * appearance and can be overridden by child classes to implement their
     * look.
     */
  virtual void draw();

  /**
   * @fn void setUpFlag(bool key)
   * @brief Used in PlayerPaddle for player input.
   * @details When a human presses a key, the setUpFlag function is used to
   * manage when the key is pressed and when it is let go.
   * 
   * @param key boolean, sets the up flag inside PlayerPaddle for input
   */
  virtual void setUpFlag(bool key);
  
   /**
   * @fn void setDownFlag(bool key)
   * @brief Used in PlayerPaddle for player input.
   * @details When a human presses a key, the setDownFlag function is used to
   * manage when the key is pressed and when it is let go.
   * 
   * @param key boolean, sets the down flag inside PlayerPaddle for input
   */
  virtual void setDownFlag(bool key);
  
  /**
   * @fn void move(double dt) = 0
   * @brief Move function used to update the paddle postion and speed.
   * @details Pure virtual function that must be implemented by an inheriting
   * class (PlayerPaddle or ComputerPaddle). Dictates what changes must be made to 
   * paddle for each screen update.
   * 
   * @param dt double, time from call to move()
   */
  virtual void move(double dt);

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
  virtual void checkKey(int, bool);

  /**
   * @fn void getBallPosition(Point)
   * @brief Gets the Ball position from Ball and sets it as currentBallPos.
   * @details Virtual function, gets the Ball position from Ball as a Point and sets it currentBallPos.
   * 
   * @param  Point, current Ball position
   */
  virtual void getBallPosition(Point);
  
  /**
   * @fn getPaddleSpeed()
   * @brief Function to retrieve the Paddle speed.
   * @details Used by Ball to get the current Paddle speed to affect the
   * resulting Ball vector after a collision with a Paddle occurs.
   * @return Vector, representing Paddle speed, x and y components.
   */
  Vector getPaddleSpeed();

  /**
   * @fn getPos()
   * @brief Getter, get current Paddle position.
   * @details Returns the current Paddle position as a Point.
   * @return Point, paddle position, centroid, x and y.
   */
  Point getPos();

  /**
   * @fn getSize()
   * @brief Getter, get current Paddle size.
   * @details Returns the current size of the Paddle object as a Point.
   * @return Point, the paddle size, width and height as x and y
   */
  Point getSize();

  /**
   * @fn calcCornerPoints()
   * @brief Calculates the top left corner Point and bottom right corner Point.
   * @details Based on the current size and origin of the Paddle, will calculate
   * the corner points of the paddle, useful for collision and when drawing the 
   * rectangle of the paddle.
   */
  void calcCornerPoints();

  /**
   * @fn TopLeft()
   * @brief Returns the top left corner of the Paddle as a Point.
   * @details Getter, returns the top left corner of the Paddle shape as a Point.
   * @return Point, top left corner of Paddle, x and y.
   */
  Point TopLeft();

/**
   * @fn BottomRight()
   * @brief Returns the bottom right corner of the Paddle as a Point.
   * @details Getter, returns the bottom right corner of the Paddle shape as a Point.
   * @return Point, bottom right corner of Paddle, x and y.
   */
  Point BottomRight();


};

#endif
