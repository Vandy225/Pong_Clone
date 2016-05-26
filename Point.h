#ifndef POINT_H
#define POINT_H

#include "Vector.h"

class Point
{
  public:
    float x,y;
    Point(float a = 0.0, float b=0.0):x(a), y(b) {};
   Point operator + (Vector v){
      return Point(x+v.x, y+v.y);
   }
};
#endif // POINT_H
