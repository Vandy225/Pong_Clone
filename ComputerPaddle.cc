#include "ComputerPaddle.h"

void ComputerPaddle::draw() {
   calcCornerPoints();
   al_draw_filled_rounded_rectangle(topLeftCorner.x, topLeftCorner.y,
				    bottomRightCorner.x, bottomRightCorner.y,
   3, 3, al_color_html("ff66cc"));
   al_draw_rounded_rectangle(topLeftCorner.x, topLeftCorner.y,
			     bottomRightCorner.x, bottomRightCorner.y,
   3, 3, al_color_html("ff99cc"), 1.0);

   al_draw_filled_rounded_rectangle(topLeftCorner.x, topLeftCorner.y,
				    bottomRightCorner.x - 5, bottomRightCorner.y - 5,
   3, 3, al_color_html("ffcccc"));
}

void ComputerPaddle::move(double dt) {

  elapsedTime += dt;

  //if (elapsedTime > 0.05) {
    // collision check of paddle with top and bottom of screen
   if((Paddle::origin.y - (Paddle::size.y/2)) <= 0 )  {
   
      Paddle::paddleSpeed.y = -(Paddle::paddleSpeed.y) * 0.7;

   } else if(Paddle::origin.y + (Paddle::size.y/2) >= 600) {

     Paddle::paddleSpeed.y = -(Paddle::paddleSpeed.y) * 0.7;

   }
 
   // paddle slow down factor
   if(Paddle::paddleSpeed.y != 0) {
       Paddle::paddleSpeed.y *= 0.9;
   }

   std::cout << currentBallPos.y << std::endl;

   // this deals with the possibility of the ball getting stuck
   // between a net and the paddle
   if(Paddle::topLeftCorner.x > currentBallPos.x && currentBallPos.y < 150)
   {
      Paddle::origin.y += 5;
   }
   
   else if(Paddle::topLeftCorner.x > currentBallPos.x && currentBallPos.y > 150)
   {
      Paddle::origin.y -= 5;
   }

   if(Paddle::origin.y < currentBallPos.y)
   {
      std::cout << "Paddle above ball, moving paddle down" << std::endl;
      Paddle::origin.y += 5;
   } 
   else if(Paddle::origin.y > currentBallPos.y)
   {
      std::cout << "Paddle below ball, moving paddle up" << std::endl;
      Paddle::origin.y -= 5;
   }

    // apply the change in the paddle vector to actually move paddle
    //Paddle::origin.y += Paddle::paddleSpeed.y * dt;
    elapsedTime = 0.0;
  //make}

}

void ComputerPaddle::getBallPosition(Point ballPos) {
  std::cout << "Ball pos retrieved: x: " << ballPos.x <<
  " y: " << ballPos.y << std::endl; 

  currentBallPos.x = ballPos.x;
  currentBallPos.y = ballPos.y;
}

// void ComputerPaddle::setUpFlag(bool key){}
// void ComputerPaddle::setDownFlag(bool key){}
