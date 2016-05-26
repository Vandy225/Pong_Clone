// CPSC 2720
// Group Project
// Tests

#ifndef __TESTS_H
#define __TESTS_H

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include "Ball.h"
#include "Paddle.h"
#include "PlayerPaddle.h"
#include "Score.h"
#include "Audio.h" // for testing the audio class
#include <ctime>
#include <cstdlib>
#include <random>

class Tests: public CppUnit::TestFixture {
  public:
   
   CPPUNIT_TEST_SUITE(Tests);
   CPPUNIT_TEST(sampleLoadTest);
   CPPUNIT_TEST(testHorzBounce);
   CPPUNIT_TEST(testVerticalTop);
   CPPUNIT_TEST(testVerticalBottom);
   CPPUNIT_TEST(testMove);
   CPPUNIT_TEST(testScore);
   CPPUNIT_TEST(testResetBall);
   CPPUNIT_TEST_SUITE_END();

  private:
   Audio *a;
   Ball *b;
   Ball *b2;
   Paddle *p;
   Score* s;

  public:
   void setUp()
   {
      a = new Audio;
   }

   void tearDown()
   {
      delete a;
      delete b;
      delete b2;
      delete p;
      delete s;
   }

   void sampleLoadTest()
   {
      CPPUNIT_ASSERT(a->samplesLoaded() == true);
   }
   
   void testHorzBounce(){
      p = new PlayerPaddle(20.0,100.0,399.0,300.0,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN);
      b = new Ball(380.0,300.0,20.0, Vector(150.0,0.0));
      Vector test = b->getBallSpeed();
      b->collisionCheck(1,*p);
      CPPUNIT_ASSERT(b->getBallSpeed() == Vector(-test.x,test.y));
   }

   void testVerticalTop()
   {
      p = new PlayerPaddle(20.0,100.0,400,300.0,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN);
      b = new Ball(400,231.0,20.0, Vector(0,10));
      Vector test = b->getBallSpeed();
      b->collisionCheck(1,*p);
      CPPUNIT_ASSERT(b->getBallSpeed() == Vector(test.x,-test.y));
   }

   void testVerticalBottom(){
      p = new PlayerPaddle(20.0,100.0,400,300.0,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN);
      b = new Ball(400,369.0,20.0, Vector(0,-10));
      b->collisionCheck(1,*p);
      CPPUNIT_ASSERT(b->getBallSpeed() == Vector(0,10));
   }

   void testMove(){
      b = new Ball(400,-5,20,Vector(0,1));
      b->move(1);
      CPPUNIT_ASSERT(b->GetPos().x == 400 && b->GetPos().y == 20);
      
      b2 = new Ball(400,605,20,Vector(0,-1));
      b2->move(1);
      CPPUNIT_ASSERT(b2->GetPos().x == 400 && b2->GetPos().y == 580);
   }

   void testScore(){
      s = new Score(400,300);
      s->setMaxScore(20);
      CPPUNIT_ASSERT(s->getScore() == 0);
      for(int i = 0; i < 20; i++){
	 s->scoreUp2();
      }
      CPPUNIT_ASSERT(s->getScore() == 20);
      s->resetScore();
      CPPUNIT_ASSERT(s->getScore() == 0);
   }

   void testResetBall(){
      srand(time(NULL));
      b = new Ball(605,400,20,Vector(10,0));
      b->resetBall();
      CPPUNIT_ASSERT(b->GetPos().x == 400 && b->GetPos().y == 300);
   }
      
	 
};
#endif
