GPP = g++11
CFLAGS = -std=c++11 -I /home/lib2720/allegro/include/
LIBDIR = /home/lib2720/allegro/lib/

LNFLAGS = -lallegro -lallegro_primitives -lallegro_color -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec -lcppunit -ldl
MYOBJECTS = Display.o Audio.o main-game.o Simulator.o ScreenMaster.o Score.o PlayerPaddle.o Paddle.o Ball.o ComputerPaddle.o MenuMaster.o

TESTOBJ = testpong.o Audio.o PlayerPaddle.o Ball.o Paddle.o Score.o


all : tests Pong

tests : $(TESTOBJ)
	$(GPP) -L $(LIBDIR) $(TESTLIBS) -o $@ $^ $(LNFLAGS)

Pong : $(MYOBJECTS)
	$(GPP) -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : %.cc
	$(GPP) $(CFLAGS) -c $^

main-game.o : ScreenMaster.h Ball.h
ScreenMaster.o : ScreenMaster.h
Score.o : Score.h
Simulator.o : Simulator.h
Display.o : Display.h
Audio.o : Audio.h
PlayerPaddle.o : PlayerPaddle.h
Paddle.o : Paddle.h
Ball.o : Ball.h Vector.h
ComputerPaddle.o : ComputerPaddle.h
MenuMaster.o : MenuMaster.h
testpong.o : tests.h

clean:
	rm -rf *.o *~ *% *# .#* *.h.gch

clean-all: clean
	rm -f Pong tests
