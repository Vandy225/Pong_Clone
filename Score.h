/**
 *@file Score.h
 *@brief Declaration of the Score class.
 *@details This class is responsible for tracking the score of the players and displaying it on the screen. In addition, the nets are
 *generated based on the activity of the score class.
 *@author Eric DenHaan, Lance Chisholm, Shaun Cullen, Joshua Vandenhoek
 *@bug no known bugs.
 */
 


//Score Class Interface
#ifndef SCORE_H
#define SCORE_H

#include "Drawable.h"
#include "Updateable.h"
#include "Audio.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string>
#include <sstream>
//#include <stdio.h>


class Score : public Drawable, public Updateable, public Audio
{
  private:
   int sc; /**< private member that denotes the score for a player. */
   int maxsc; /**< private member that denotes the maximum score a player can reach.*/
   int x,y; /** private members that track the x and y position of the score objects on the screen. */ 

   
   ALLEGRO_FONT *fon; /**< private member that stores the font that the score will be displayed in. */
   
  public:
   /**
    *@fn Score (int, int)
    *@brief constructor for the score.
    *@details This function takes 2 parameters and sets the x and y values of the score object to the incoming parameters.
    *@param xx int that denotes the x position of the center point of the score object to be displayed.
    *@param yy int that denotes the y position of the center point of the score object to be displayed
    *@return Score object.
    */
   Score(int,int);

   
   //~Score();
   /**
    *@fn void scoreUp()
    *@brief increments the score by 1 and plays a sound.
    *@details this function acts on a score object to change its sc data member by calling the helper function scoreUp2(). This function also handles
    *playing the sound that accompanies scoring.
    *@param none.
    *@return void.
    */
   
   void scoreUp();
   /**
    *@fn void scoreUp2()
    *@brief increments the 2nd player's score by 1.
    *@details acts on a score object to increment the sc data member by 1, effectively increasing the score.
    *@param none.
    *@return void.
    */
   
   void scoreUp2();
   /**
    *@fn void resetScore()
    *@brief function that resets the score.
    *@details This function resets the sc parameter of a score object to 0, clearing the score.
    *@param none.
    *@return void.
    */
   
   void resetScore();
   /**
    *@fn int setMaxScore(int)
    *@brief function that sets the max score to a specified value.
    *@details this function sets the maxsc data member of a score object to the value in the input parameter. 
    *@param max int value that denotes what the maxsc parameter should be set to.
    *@return returns maxsc after being reset
    */
   
   int setMaxScore(int);
   /**
    *@fn int getMaxScore()
    *@brief getter function for the max score of a score object.
    *@details This function returns the maxsc member of a score object.
    *@param none.
    *@return maxsc
    */
   
   int getMaxScore();

/**
    *@fn int setScore(int);
    *@brief setter function for the sc parameter of a score object.
    *@details this function sets the sc parameter of a score object and then returns it.
    *@param newScore the new score that you want the old score to be set to.
    *@return returns sc back after it has been changed.
    */

   
   int setScore(int);


/**
    *@fn int getScore()
    *@brief getter function for the current score of a score object.
    *@details returns the value of the sc parameter of a score object.
    *@param none. 
    *@return returns the current value of the sc member of the score object.
    */

   
   int getScore();
   /**
    *@fn bool isMax()
    *@brief determines if the sc parameter of the score object is the max score
    *@details this function returns true if the sc parameter of the score object equals the maxsc parameter, false otherwise.
    *@param none.
    *@return true/false.
    */

   
   bool isMax();




///empty implementation, scores don't move!   
   void move(double);


/**
    *@fn void draw()
    *@brief displays the score of a score object with a particular font.
    *@details This function uses a string stream to convert the string representation of the sc member to a const char *. This
    *is necessary for allegro to display text on the screen properly. The function then calls the allegro draw text function to
    *display the text on screen.
    *@param none.
    *@return void.
    */

   
   void draw();
  
   bool netTrigger = false; /**< public member that is used by ScreenMaster to determine if the nets need to be triggered based on the current score. */
};
#endif
