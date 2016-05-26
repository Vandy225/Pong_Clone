#include "Ball.h"

void Ball::move(double dt) {
      origin = origin + speed*dt;
      timeE += dt;
      if(F){
      	if(timeE > 3){
      		speed = Vector::randomVector();
      		F = false;
      	}
      }
      if (origin.y-radius < 0){
	 origin.y = radius;
	 //play the wall hit sound
	 al_play_sample_instance(w_hit_inst);
	 VertBounce();
      }
      if(origin.y+radius > 600){
	 origin.y = 600-radius;
	 //play the wall hit sound
	 al_play_sample_instance(w_hit_inst);
	 VertBounce();
      }
      
   }

void Ball::HorzBounce(){
      speed = Vector(-(speed.x),speed.y);
      std::cout<<"("<<speed.x<<","<<speed.y<<")\n";
   }
   
void Ball::VertBounce(){
      speed = Vector(speed.x,-(speed.y));
      std::cout<<"("<<speed.x<<","<<speed.y<<")\n";
      
   }
   
   
Point Ball::GetPos(){
      return origin;
   }
   
Vector Ball::getBallSpeed() {
      return speed;
   }
   
int Ball::getRadius() {
      return radius;
   }
   
void Ball::resetBall(){
      origin = Point(400,300);
      speed = Vector::randomVector();
  }
   
void Ball::draw() 
{
      al_draw_filled_circle(origin.x, origin.y, radius, 
      	al_color_html("6be97d"));
      al_draw_filled_circle(origin.x+radius/4, origin.y+radius/4, radius/3*2,
      	al_color_html("59ce76"));
      al_draw_filled_circle(origin.x-radius/3, origin.y-radius/3, radius/4,
      	al_color_html("9bffaa"));
}
   
void Ball::collisionCheck(double dt, Paddle& paddle) {
      //collision has occcured
      
      if(paddle.TopLeft().x < origin.x &&
	     paddle.BottomRight().x > origin.x &&
	     paddle.TopLeft().y < origin.y+radius &&
	     paddle.TopLeft().y+radius > origin.y+radius) {
	        
            //top collision


           origin = Point(origin.x,paddle.TopLeft().y-radius-buffer);
	        speed = Vector(speed.x,-(speed.y+paddle.getPaddleSpeed().y));
	 
	        al_play_sample_instance(p_hit_inst);
      }else if(paddle.TopLeft().x < origin.x &&
	              paddle.BottomRight().x > origin.x &&
	              paddle.BottomRight().y-radius < origin.y-radius &&
	              paddle.BottomRight().y > origin.y-radius){
	        
           // bottom collision

           origin = Point(origin.x,paddle.BottomRight().y+radius+buffer);
	        speed = Vector(speed.x,-(speed.y-paddle.getPaddleSpeed().y));
	 
	        al_play_sample_instance(p_hit_inst);
      } else if(paddle.TopLeft().x <= origin.x+radius &&
	              paddle.BottomRight().x >= origin.x+radius &&
	              paddle.TopLeft().y < origin.y &&
	              paddle.BottomRight().y > origin.y){
      	 
          // left collision

          origin = Point(paddle.TopLeft().x-radius-buffer,origin.y);
      	 //speed = Vector(-(speed.x+(paddle.getPaddleSpeed().y/2)),speed.y+(paddle.getPaddleSpeed().y/2));
      	 speed = Vector(-speed.x,speed.y+paddle.getPaddleSpeed().y/2);
	 
	        al_play_sample_instance(p_hit_inst);
      } else if(paddle.TopLeft().x <= origin.x-radius &&
	        paddle.BottomRight().x >= origin.x-radius &&
	        paddle.TopLeft().y < origin.y &&
	        paddle.BottomRight().y > origin.y){
   	 
         // right collision

         origin = Point(paddle.BottomRight().x+radius+buffer, origin.y);
   	   //speed = Vector(-(speed.x+(paddle.getPaddleSpeed().y/2)),speed.y+(paddle.getPaddleSpeed().y/2));
   	   speed = Vector(-speed.x,speed.y+paddle.getPaddleSpeed().y/2);
	 
	      al_play_sample_instance(p_hit_inst);
      }
   }
