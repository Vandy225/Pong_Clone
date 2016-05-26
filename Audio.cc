// CPSC 2720
// Group Project
// Audio.cc
// Class which initializes and deallocates all audio components (implementation)
// Written By: Eric Den Haan

#include "Audio.h"
#include <iostream>

//Constructor
Audio::Audio()
{
   //initialize library resources
   al_install_audio();
   al_init_acodec_addon();
   al_reserve_samples(4);

   //load the samples
   bkgrnd_music = al_load_sample("pong_sounds/music.wav");
   w_hit = al_load_sample("pong_sounds/wall_hit.wav");
   p_hit = al_load_sample("pong_sounds/paddle_hit.wav");
   score = al_load_sample("pong_sounds/score.wav");

   //create the sample instances to allow simultaneous playback
   bkgrnd_music_inst = al_create_sample_instance(bkgrnd_music);

   //set the background music to loop, also set the gain a bit lower
   al_set_sample_instance_playmode(bkgrnd_music_inst, ALLEGRO_PLAYMODE_LOOP);
   al_set_sample_instance_gain(bkgrnd_music_inst, 0.5);
   
   w_hit_inst = al_create_sample_instance(w_hit);
   p_hit_inst = al_create_sample_instance(p_hit);
   score_inst = al_create_sample_instance(score);

   //attach the instances to the default mixer
   al_attach_sample_instance_to_mixer(bkgrnd_music_inst, al_get_default_mixer());
   al_attach_sample_instance_to_mixer(w_hit_inst, al_get_default_mixer());
   al_attach_sample_instance_to_mixer(p_hit_inst, al_get_default_mixer());
   al_attach_sample_instance_to_mixer(score_inst, al_get_default_mixer());
}

//Destructor
Audio::~Audio()
{
   //release the sample instances
   al_destroy_sample_instance(bkgrnd_music_inst);
   al_destroy_sample_instance(w_hit_inst);
   al_destroy_sample_instance(p_hit_inst);
   al_destroy_sample_instance(score_inst);

   //release the sample resources
   al_destroy_sample(bkgrnd_music);
   al_destroy_sample(w_hit);
   al_destroy_sample(p_hit);
   al_destroy_sample(score);
}

bool Audio::samplesLoaded()
{
   if(bkgrnd_music != NULL && w_hit != NULL && p_hit != NULL || score != NULL)
   {
      return true;
   }
}
	 
