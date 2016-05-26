#include "Paddle.h"

void Paddle::draw(){
   
   calcCornerPoints();
   al_draw_filled_rounded_rectangle(topLeftCorner.x, topLeftCorner.y,
				    bottomRightCorner.x, bottomRightCorner.y,
   3, 3, al_color_html("729fcf"));
   al_draw_rounded_rectangle(topLeftCorner.x, topLeftCorner.y,
			     bottomRightCorner.x, bottomRightCorner.y,
   3, 3, al_color_html("b5edff"), 1.0);

   al_draw_filled_rounded_rectangle(topLeftCorner.x, topLeftCorner.y,
				    bottomRightCorner.x - 5, bottomRightCorner.y - 5,
   3, 3, al_color_html("8abbef"));
}

void Paddle::move(double dt) {}

Point Paddle::getPos(){
   
	return origin;
}

Point Paddle::getSize() {

	return size;
}

void Paddle::calcCornerPoints() {

	topLeftCorner.x = (origin.x - (size.x/2.0));
	topLeftCorner.y = (origin.y - (size.y/2.0));

	bottomRightCorner.x = (origin.x + (size.x/2.0));
	bottomRightCorner.y = (origin.y + (size.y/2.0));

}

Point Paddle::TopLeft(){
   return topLeftCorner;
}

Point Paddle::BottomRight(){
   return bottomRightCorner;
}

Vector Paddle::getPaddleSpeed(){
   return paddleSpeed;
}

void Paddle::checkKey(int keyPressed, bool pressed) {}

void Paddle::getBallPosition(Point p) {}

void Paddle::setUpFlag(bool key){};
void Paddle::setDownFlag(bool key){};
