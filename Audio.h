// CPSC 2720
// Group Project
// Audio.h
// Class which initializes and deallocates all audio components (interface)
// Written By: Eric Den Haan

#ifndef AUDIO_H
#define AUDIO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cstdlib>
#include <string>

class Audio
{
  private:
   // the sound samples
   ALLEGRO_SAMPLE *bkgrnd_music; // background music
   ALLEGRO_SAMPLE *w_hit; // wall hit sound effect
   ALLEGRO_SAMPLE *p_hit; // paddle hit sound effect
   ALLEGRO_SAMPLE *score; // score sound effect

  protected:
   // the sample instances, which will be played in ball and score
   ALLEGRO_SAMPLE_INSTANCE *bkgrnd_music_inst;
   ALLEGRO_SAMPLE_INSTANCE *w_hit_inst;
   ALLEGRO_SAMPLE_INSTANCE *p_hit_inst;
   ALLEGRO_SAMPLE_INSTANCE *score_inst;
  
  public:
// Constructor, initializes audio components
   Audio();
// Destructor, releases audio resources
   ~Audio();
// checks to see if samples have loaded, for testing purposes
   bool samplesLoaded();
};

#endif
   
