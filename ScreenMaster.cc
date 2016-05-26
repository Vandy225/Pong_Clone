#include "ScreenMaster.h"
#include <cmath>

void ScreenMaster::addUpdateable(std::shared_ptr<Updateable> thing){
   ULIST.push_back(thing);
}

void ScreenMaster::addDrawable(std::shared_ptr<Drawable> thing2){
   DLIST.push_back(thing2);
}

void ScreenMaster::addPaddle(std::shared_ptr<Paddle> paddle){
   PADDLE_LIST.push_back(paddle);
}

void ScreenMaster::addCPUPaddle(std::shared_ptr<Paddle> CPUpaddle){
   PADDLE_LIST.push_back(CPUpaddle);
}

void ScreenMaster::addBall(std::shared_ptr<Ball> ball){
   BALL_LIST.push_back(ball);
}


void ScreenMaster::updateModel(double dt) {
   std::list <std::shared_ptr<Updateable>>::iterator it = ULIST.begin();

   if(ScoreOne->isMax()){
      std::cout<<"Player Right Wins!\n";
      gameOver = true;
      al_clear_to_color(al_map_rgb(0,0,0));
      std::string message = "Player Right Wins!";
      std::string mg;
      std::stringstream convert;
      convert << message;
      mg = convert.str();
      const char *c = mg.c_str();
      al_draw_text(fon, al_map_rgb(255,255,255), 400, 300,1, c);
      al_flip_display();
      al_rest(3);
      return;
   }
   if(ScoreTwo->isMax()){
      std::cout<<"Player Left Wins!\n";
      gameOver = true;
      al_clear_to_color(al_map_rgb(0,0,0));
      std::string message2 = "Player Left Wins!";
      std::string mg2;
      std::stringstream convert2;
      convert2 << message2;
      mg2 = convert2.str();
      const char *d = mg2.c_str();
      al_draw_text(fon, al_map_rgb(255,255,255), 400, 300,1, d);
      al_flip_display();
      al_rest(3);
      return;
   }
   
   while(it != ULIST.end()){
      (*it)->move(dt);
      ++it;
   }
   
   std::list <std::shared_ptr<Ball>>::iterator it2 = BALL_LIST.begin();
   std::list <std::shared_ptr<Paddle>>::iterator it3 = PADDLE_LIST.begin();

   while(it2 != BALL_LIST.end()){
      
      std::cout << "iterating over ball list" << std::endl;
	 
      if((*it2)->GetPos().x-20 <= 0){
         (*it2)->resetBall();
         ScoreOne->scoreUp();
      }
      if((*it2)->GetPos().x+20 >= 800){
         (*it2)->resetBall();
         ScoreTwo->scoreUp();
      }
      
      while(it3 != PADDLE_LIST.end()){
         (*it3)->getBallPosition((*it2)->GetPos());        
         ++it3;
      }

      ++it2;
   }

   //if one player is 5 points away from winning, add nets to his opponent's side
   if(ScoreOne->getScore()+5 == ScoreOne->getMaxScore() && ScoreOne->netTrigger == false)
   {
      ScoreOne->netTrigger = true;
      addPaddle(rightNetUp);
      addPaddle(rightNetDown);
      addDrawable(rightNetUp);
      addDrawable(rightNetDown);
      addUpdateable(rightNetUp);
      addUpdateable(rightNetDown);
   }

   if(ScoreTwo->getScore()+5 == ScoreTwo->getMaxScore() && ScoreTwo->netTrigger == false)
   {
      ScoreTwo->netTrigger = true;
      addPaddle(leftNetUp);
      addPaddle(leftNetDown);
      addDrawable(leftNetUp);
      addDrawable(leftNetDown);
      addUpdateable(leftNetUp);
      addUpdateable(leftNetDown);
   }  
}

void ScreenMaster::drawModel(){
   
   al_clear_to_color(al_map_rgb(0,0,0));
      std::list <std::shared_ptr<Drawable>>::iterator it = DLIST.begin();
      while(it != DLIST.end()){
	 (*it)->draw();
	 ++it;
      }
      al_flip_display();
}

void ScreenMaster::playerinput(int a, bool pressrelease)
{
   std::list <std::shared_ptr<Paddle>>::iterator it = PADDLE_LIST.begin();
   
   while(it != PADDLE_LIST.end()){
      (*it)->checkKey(a, pressrelease);
      ++it;
   }
}

void ScreenMaster::collision(double dt) {
   
   std::list <std::shared_ptr<Ball>>::iterator ballIT = BALL_LIST.begin();
   
   while(ballIT != BALL_LIST.end()){
      
      std::list <std::shared_ptr<Paddle>>::iterator paddleIT = PADDLE_LIST.begin();
      while(paddleIT != PADDLE_LIST.end()) {
     
     (*ballIT)->collisionCheck(dt, *(*paddleIT));
         ++paddleIT;
       }
       ++ballIT;     
   }
}

void ScreenMaster::initialize(){
   //play the background music
   al_play_sample_instance(bkgrnd_music_inst);
   
   std::shared_ptr<Ball> ballPointer = std::make_shared<Ball>(400,300,20,Vector(0,0));

   addUpdateable(ballPointer);
   addDrawable(ballPointer);
   
   addUpdateable(ScoreOne);
   addDrawable(ScoreOne);
   addUpdateable(ScoreTwo);
   addDrawable(ScoreTwo);
   
   addDrawable(pPointer);
   addUpdateable(pPointer);
   addPaddle(pPointer);

   addDrawable(pPointer2);
   addUpdateable(pPointer2);
   addPaddle(pPointer2);
   
   addBall(ballPointer);
   
   ScoreOne->setMaxScore(10);
   ScoreTwo->setMaxScore(10);
}

void ScreenMaster::initialize3(){
   //play the background music
   al_play_sample_instance(bkgrnd_music_inst);

   std::shared_ptr<Ball> ballPointer = std::make_shared<Ball>(400,300,20,Vector(0,0));
   
   addUpdateable(ballPointer);
   addDrawable(ballPointer);
   
   addUpdateable(ScoreOne);
   addDrawable(ScoreOne);
   addUpdateable(ScoreTwo);
   addDrawable(ScoreTwo);
   
   addDrawable(pPointer);
   addUpdateable(pPointer);
   addPaddle(pPointer);

   addDrawable(CPUPointer);
   addUpdateable(CPUPointer);
   addCPUPaddle(CPUPointer);

   addBall(ballPointer);
   
   ScoreOne->setMaxScore(10);
   ScoreTwo->setMaxScore(10);
}
