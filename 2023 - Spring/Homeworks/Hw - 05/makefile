all: clear clean compile run

compile: main.cpp Bulldozer.cpp Humanic.cpp OptimusPrime.cpp Robocop.cpp Robot.cpp Roomba.cpp World.cpp
	@g++ -o test main.cpp Bulldozer.cpp Humanic.cpp OptimusPrime.cpp Robocop.cpp Robot.cpp Roomba.cpp World.cpp  -std=c++11

run:

	./test
	
clean:

	@rm -f *.o

clear:
	@clear	