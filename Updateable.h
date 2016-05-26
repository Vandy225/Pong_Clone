/**
 *@file Updateable.h
 *  @brief Definition of the Updateable Class.
 *  This class is responsible for providing the pure virtual method
 *  move(double dt) which is responsible for moving an object.
 *  @author Lance Chisholm, Joshua Vandenhoek, Shaun Cullen, Eric DenHaan
 *  @bug no known bugs
 */

#ifndef UPDATEABLE_H
#define UPDATEABLE_H

class Updateable {
  public:

   /**
    *@fn virtual void move(double dt)
    *  @brief Pure virtual object moving function
    *  @param dt 
    *  The purpose of this function is to take in a double called dt that
    *  represents a change in distance over time, and then move the object that
    *  this function is acting on as specified in the implementation. The user
    *  is responsible for providing inplementation as the way that a particular
    *  object is meant to move is specific to the object.
    *  @return void
    */
   virtual void move(double dt) = 0;
};

#endif
