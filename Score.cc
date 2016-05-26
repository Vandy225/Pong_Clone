//Score Class Implementation
#include "Score.h"

//Constructor
Score::Score(int xx, int yy) : x(xx), y(yy)
{
   sc = 0;
   maxsc = 5;

   //al_init_font_addon();
   //al_init_ttf_addon();
   fon = al_load_ttf_font("pong_fonts/wendy.ttf", 200, 0);
}

//Score::~Score(){}

//scoreUp function
//Output: the current score incremented by 1
void Score::scoreUp()
{
   //if the score sound is already playing, stop it first
   if(al_get_sample_instance_playing(score_inst))
   {
      al_stop_sample_instance(score_inst);
   }

   //play the score sound
   al_play_sample_instance(score_inst);
   
   scoreUp2();
   al_clear_to_color(al_map_rgb(0,0,0));
}

void Score::scoreUp2()
{
   sc++;
}

//resetScore function
//Output: set score back to 0
void Score::resetScore()
{
   sc = 0;
}

//setMaxScore function
//Output: set a new max score
int Score::setMaxScore(int max)
{
   maxsc = max;
   return maxsc;
}

//getMaxScore function
int Score::getMaxScore()
{
   return maxsc;
}

//setScore function
//Input: a new score
//Output: the current score set to a new value
int Score::setScore(int newScore)
{
   sc = newScore;
   return sc;
}

//getScore function
int Score::getScore()
{
   return sc;
}

//isMax function
//Output: If the max score is reached, set to true, otherwise false
bool Score::isMax()
{
   if(sc == maxsc)
   {
      return true;
   }
   else
   {
      return false;
   }
}

//draw function
//Output: draws the digit corresponding to the score
void Score::draw()
{
   std::string score;
   std::stringstream convert;
   convert << sc;
   score = convert.str();
   const char *c = score.c_str();
   al_draw_text(fon, al_map_rgb(255,255,255), x, y,0, c);
}

void Score::move(double dt){
   //Does nothing. 
}
