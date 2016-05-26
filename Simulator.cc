#include "Simulator.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdexcept>


Simulator::Simulator(const Display & d, const Audio & a, int fps) :
	framesPerSec(fps), timer(NULL), eventQueue(NULL) {

	if ((timer = al_create_timer(1.0 / fps)) == NULL)
		throw std::runtime_error("Cannot create allegro timer");

	if ((eventQueue = al_create_event_queue()) == NULL)
		throw std::runtime_error("Cannot create event queue");

	al_register_event_source(eventQueue, al_get_display_event_source(d.getAllegroDisplay()));

	//this segment is going to use the event queue to implement keyboard control

	//*******************************************************************

	al_install_keyboard();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	
	//*******************************************************************
	 
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
  
	al_start_timer(timer);
}


Simulator::~Simulator() {
	if (timer != NULL)
		al_destroy_timer(timer);
	if (eventQueue != NULL)
		al_destroy_event_queue(eventQueue);
}


void Simulator::run() {

	// switch to trigger model drawing
	bool redraw=false;
	// current time and previous time in seconds; needed so we can try
	// to keep track of the passing of real time.
	double crtTime, prevTime = 0;

	while(1) {
	   ALLEGRO_EVENT ev;

	   al_wait_for_event(eventQueue, &ev);

		/* This */   

		if(ev.type == ALLEGRO_EVENT_TIMER) {
			crtTime = al_current_time();
			updateModel(crtTime - prevTime);

			collision(crtTime - prevTime);


			prevTime = crtTime;
			// instead of simply calling drawModel() here, we set this flag so that
			// we redraw only if the event queue is empty; reason: draw is expensive and
			// we don't want to delay everything too much
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			al_flush_event_queue(eventQueue);
			break;
		} else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
		   
		   playerinput(ev.keyboard.keycode, true);
		   
		} else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
		   playerinput(ev.keyboard.keycode, false);
		}    
		
 
		if(redraw && al_is_event_queue_empty(eventQueue)) {
			drawModel();
			redraw = false;
		}

		if (gameOver)
		{
			break;
		}
		
		   
	}
}

ALLEGRO_EVENT_QUEUE* Simulator::getQueue()
{
	return eventQueue;
}
