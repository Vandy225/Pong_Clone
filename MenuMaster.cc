#include "MenuMaster.h"

void MenuMaster::draw()
{
}

void MenuMaster::move(double dt){}

void MenuMaster::updateModel(double dt)
{
}

void MenuMaster::drawModel()
{
   al_clear_to_color(al_map_rgb(0,0,0));
   std::string titleS;
   //option for human v human
   std::string option1;
   //option for human v comp
   std::string option2;
   
   std::stringstream convert;
   std::stringstream convert2;
   std::stringstream convert3;
   convert << t;
   titleS = convert.str();
   const char *c = titleS.c_str();
   al_draw_text(fon, al_map_rgb(0, 255, 0), title.x, title.y, ALLEGRO_ALIGN_CENTRE, c);

   convert2 << o1;
   option1 = convert2.str();
   const char *d = option1.c_str();
   al_draw_text(fon, al_map_rgb(255, 255, 255), opt1.x, opt1.y, ALLEGRO_ALIGN_CENTRE, d);

   convert3 << o2;
   option2 = convert3.str();
   const char *e = option2.c_str();
   al_draw_text(fon, al_map_rgb(30, 55, 255), opt2.x, opt2.y, ALLEGRO_ALIGN_CENTRE, e);
   al_flip_display();
   
}

void MenuMaster::playerinput(int a, bool pressrelease)
{
   if(pressrelease){
        
      //this is when the key is actually being pressed
      switch(a)
      {
	 case ALLEGRO_KEY_1:
	 {
	    //ModeSelect1(true);
	    std::cout<<"one\n";
	    mode = 1;
	    break;
	 }
	 case ALLEGRO_KEY_2:
	 {
	    //ModeSelect2(true);
	    std::cout<<"two\n";
	    mode = 2;
	    break;
	 }
	 case ALLEGRO_KEY_3:
	 {
	 	mode =3;
	 	break;
	 }

	 case ALLEGRO_KEY_4:
	 {
	 	mode = 4;
	 	break;
	 }
	 default:
	 {
	 	mode =1;
	 	break;
	 }
      }
      
   }
}

void MenuMaster::collision(double dt){}



int MenuMaster::runMenu() {

	// switch to trigger model drawing
	//bool redraw=true;
	// current time and previous time in seconds; needed so we can try
	// to keep track of the passing of real time.
	//double crtTime, prevTime = 0;

	while(1) {

	ALLEGRO_EVENT_QUEUE* eventQ = this->getQueue();
	   ALLEGRO_EVENT ev;

	   al_wait_for_event(eventQ, &ev);
 

		drawModel();
			
			
		

	   //if the user closes the screen then we close out
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		   return -1;
		}
		//this is where I want to check for the type of key that is being pressed
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
		   
		   playerinput(ev.keyboard.keycode, true);
		   return mode;	    
		}
	}
}

