#include "ScreenMaster.h"
#include "MenuMaster.h"
#include <ctime>
#include <cstdlib>
#include <random>

int main ()
{

   bool continueGame=true;
   int mode;   
   //random seed for our random numbers
   srand (time(NULL));

   //this initializes a Display object of size 800 x 600
   Display displayobject(800,600);
   Audio audioobject;
   al_init_font_addon();
   al_init_ttf_addon();

   MenuMaster menu(displayobject,audioobject,100);


//while(mode != -1)
//{
 
 mode = menu.runMenu();
 
   //initialize the game ScreenMaster object with the display and set
   //the fps to 100
   ScreenMaster game(displayobject, audioobject, 100);
 
 if (mode == 1)
 {
   game.initialize();
   game.run();
   mode = 0;
 }
 else if (mode ==2)
 {
   //game.initialize2();
   
   game.initialize3();
   game.run();
   mode =0;
 }
 /*
 else if (mode ==3)
 {
   
 }*/

 std::cout << "Mode is: "<< mode << std::endl;  


//}

}






  
