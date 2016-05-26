#ifndef SCREENMASTER_H
#define SCREENMASTER_H

#include "Simulator.h"
#include <allegro5/allegro_primitives.h>
#include <memory>
#include <list>
#include <iostream>
#include "Audio.h"
#include "PlayerPaddle.h"
#include "ComputerPaddle.h"
#include "Paddle.h"
#include "Updateable.h"
#include "Drawable.h"
#include "Ball.h"
#include "Score.h"
#include "Net.h"

//Using one simulator class that works with multiple objects of different type.
class ScreenMaster: public Simulator, public Audio {
   int width, height;
   ALLEGRO_FONT* fon = al_load_ttf_font("pong_fonts/wendy.ttf", 50, 0);
   //keep a list of updateable and drawables
   std::list <std::shared_ptr<Updateable>> ULIST;
   std::list <std::shared_ptr<Drawable>> DLIST;
   std::list <std::shared_ptr<Paddle>> PADDLE_LIST;
   std::list <std::shared_ptr<Ball>> BALL_LIST;
   std::shared_ptr<Score> ScoreOne = std::make_shared<Score>(500,25);
   std::shared_ptr<Score> ScoreTwo = std::make_shared<Score>(250,25);

   std::shared_ptr<PlayerPaddle> pPointer2 =
      std::make_shared<PlayerPaddle>(20.0, 100.0, 150.0, 400.0, ALLEGRO_KEY_W, ALLEGRO_KEY_S);

   std::shared_ptr<PlayerPaddle> pPointer =
      std::make_shared<PlayerPaddle>(20.0, 100.0, 650.0, 400.0, ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN);

   
   std::shared_ptr<ComputerPaddle> CPUPointer = std::make_shared<ComputerPaddle>(20.0, 100.0, 150.0, 300.0);
   std::shared_ptr<Net> leftNetUp = std::make_shared<Net>(20.0, 200.0, 795.0, 50.0);
   std::shared_ptr<Net> leftNetDown = std::make_shared<Net>(20.0, 200.0,795.0, 550.0);
   std::shared_ptr<Net> rightNetUp = std::make_shared<Net>(20.0, 200.0, 5.0, 50.0);
   std::shared_ptr<Net> rightNetDown = std::make_shared<Net>(20.0, 200.0, 5.0, 550.0);
   
  
public:
   //this paddlepointer is so that ScreenMaster can communicate with the paddle
  ScreenMaster(const Display & d, const Audio & a, int fps) : Simulator(d, a, fps)
   {
      width = d.getW();
      height = d.getH();
   }
   
   void addUpdateable(std::shared_ptr<Updateable>);

   void addDrawable(std::shared_ptr<Drawable>);

   void addPaddle(std::shared_ptr<Paddle>);

   void addCPUPaddle(std::shared_ptr<Paddle>);

   void addBall(std::shared_ptr<Ball>);

   void updateModel(double dt);

   void drawModel();  

   //this function may be used to detect player input
   void playerinput(int a, bool pressrelease);

   // set up right human player versus left computer player
   void initialize3();

   void initialize();

   void collision(double dt);

};

#endif
	 
