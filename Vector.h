/**
 *  @file Vector.h
 *  @brief Definition of the Vector class.
 *  @details This class is responsible for creating objects that act as vectors, which are used by
 *  moving objects to determine their speed and direction.
 *  @author Lance Chisholm, Joshua Vandenhoek, Shaun Cullen, Eric DenHaan
 *  @bug No known bugs
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <random>

class Vector
{
  public:
    float x; /**< Represents the x coordinate of the vector */
    float y; /**< Represents the y coordinate of the vector */



/**
 *  @fn Vector(float a=0.0, float b=0.0) : x(a) y(b) {}
 *  @brief Constructor for Vector objects with initialization list setting members to 0 by default.
 *  @param a Value that sets the x coordinate of the Vector object. Initialized to 0 if none provided.
 *  @param b Value that sets the y coordinate of the Vector object. Initialized to 0 if none provided.
 */
  Vector(float a=0.0, float b=0.0) : x(a), y(b) {};

  /**
    *  @fn Vector operator * (double scalar)
    *  @brief Overloaded * operator.
    *  This function  is intended to take in a double called scalar and multiply the x and y coordinates of     
    *  the Vector object it is operating on by this quantity. Then the function returns a new Vector object     
    *  initialized with the new values for the x and y coordinates.
    *  @param scalar Represents a quantity that the user wants the current Vector's x and y coordinates to
    *  be augmented by.
    *  @return A new Vector object with x and y coordinates that have been multipled by the parameter scalar.
    */

    Vector operator * (double scalar) {
      return Vector(x*scalar, y*scalar);
   }


    /**
    *  @fn Vector operator + (double scalar)
    *  @brief Overloaded + operator.
    *  This function is intended to take in a double called scalar and multiply the x and y coordinates of
    *  the Vector object it is operating on by this quantity.
    *  Then the function returns a new Vector object initialized with the new values for the x and y coordinates.
    *  @param scalar Represents a quantity that the user wants the current Vector's x and y coordinates to
    *  be augmented by.
    *  @return A new Vector object with x and y coordinates that have been added to the parameter scalar 
    */
   Vector operator + (double scalar){
      return Vector(x+scalar, y+scalar);
   }

/**
 *@fn bool operator == (Vector V)
 *@brief Overloaded == operator.
 *This overloaded == operator is intended to compare 2 vectors and return true if they are, false otherwise.
 *@param V a vector object that "this" is being compared to.
 *@return true/false
 */
 
   bool operator == (Vector V){
      if(x == V.x && y == V.y){
	 return true;
      }
   }
/**
 *@fn static Vector randomVector()
 *@brief function to generate a random vector.
 *This function is intended to generate a random vector, which will be used by the ball object when a
 *score happens and the ball is redrawn in the middle of the screen. The ball then moves off on this random
 *vector.
 *@param none.
 *@return a Vector object.
 */
   
   static Vector randomVector(){
      int ram = rand()%4+1;
      int xxx;
      int yyy;
      int min_speed = 200;
      int max_speed = 400;
      switch(ram){
	 case 1:{
	    xxx = -(rand()%max_speed+min_speed);
	    yyy = rand()%max_speed+min_speed;
	    break;
	 }
	 case 2:{
	    xxx= rand()%max_speed+min_speed;
	    yyy= rand()%max_speed+min_speed;
	    break;
	 }
	 case 3:{
	    xxx= rand()%max_speed+min_speed;
	    yyy= -(rand()%max_speed+min_speed);
	    break;
	 }
	 case 4:{
	    xxx= -(rand()%max_speed+min_speed);
	    yyy= -(rand()%max_speed+min_speed);
	    break;
	 }
      }
      
      return Vector(xxx,yyy);
   }
};



#endif // VECTOR_H_INCLUDED
