#include "PlayerPaddle.h"

void PlayerPaddle::move(double dt) {

   bool moveUp, moveDown;
   moveUp = true;
   moveDown = true;

   if((Paddle::origin.y - (Paddle::size.y/2)) <= 0 )  {
      moveUp = false;
      moveDown = true;
      Paddle::paddleSpeed.y = -(Paddle::paddleSpeed.y) * 0.7;

   } else if(Paddle::origin.y + (Paddle::size.y/2) >= 600) {
      moveUp = true;
      moveDown = false;
     Paddle::paddleSpeed.y = -(Paddle::paddleSpeed.y) * 0.7;
   }   

   if(Paddle::paddleSpeed.y != 0) {
        Paddle::paddleSpeed.y *= 0.9;
   }

  
      if(UP_ARROW_PRESS && !DOWN_ARROW_PRESS && moveUp) {
            Paddle::paddleSpeed.y -= 100;

      } 

      if(DOWN_ARROW_PRESS && !UP_ARROW_PRESS && moveDown){
            Paddle::paddleSpeed.y += 100;
         
      }

    Paddle::origin.y += Paddle::paddleSpeed.y * dt;
}

void PlayerPaddle::setUpFlag(bool key) {
   UP_ARROW_PRESS = key;
}

void PlayerPaddle::setDownFlag(bool key) {
   DOWN_ARROW_PRESS = key;
}

void PlayerPaddle::checkKey(int keyPressed, bool pressed) {

  if (pressed)
   {
      
      //this is when the key is actually being pressed
     if (keyPressed == UP_KEY) {
         //Paddle->x += 1;
          std::cout << "Getting Up Key" << std::endl;
          this->setUpFlag(true);
          //UP_ARROW_PRESS = true;
     } else if (keyPressed == DOWN_KEY) {
         //Paddle->x -=1;
          std::cout << "Getting Down Key" << std::endl;
          this->setDownFlag(true);
          //DOWN_ARROW_PRESS=true
     }
  }
   //this is when the key is being released
   else
   {
      if (keyPressed == UP_KEY) {
            //Paddle->x += 1;
            std::cout << "Releasing Up Key" << std::endl;
            this->setUpFlag(false);
            //UP_ARROW_PRESS = false;
      } else if (keyPressed == DOWN_KEY) {
         //Paddle->x -=1;
          std::cout << "Releasing Down Key" << std::endl;
            this->setDownFlag(false);
            //DOWN_ARROW_PRESS = false;
      }
   }

}
