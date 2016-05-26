#ifndef MENUMASTER_H
#define MENUMASTER_H

#include "Drawable.h"
#include "Updateable.h"
#include "Simulator.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Point.h"

class MenuMaster : public Simulator
{
  private:
   ALLEGRO_DISPLAY* disp;
   ALLEGRO_FONT *fon;
   Point title = Point(400,100);
   Point opt1 = Point(400,250);
   Point opt2 = Point(400,400);
   bool oneKeyPress=false, twoKeyPress=false;
   std::string t = "Poing";
   std::string o1 = "1.Human vs. Human";
   std::string o2 = "2.Human vs. Computer";
   int mode;
   bool permissionToDie=false;
   // title, option1, option2
   

   int width, height;
   
  public:
   //constructor
  MenuMaster(const Display& d, Audio& a, int fps) : Simulator(d,a,fps)
   {
      disp = d.getAllegroDisplay();
      width = d.getW();
      height = d.getH();
      
      al_init_font_addon();
      al_init_ttf_addon();
      fon = al_load_ttf_font("/usr/share/fonts/dejavu/DejaVuSerif.ttf", 24, 0);
   


   }  
   void move(double);
   void draw();
   void updateModel(double);
   void drawModel();
   void playerinput(int, bool);
   void collision(double);
   int runMenu();
   
};
#endif
