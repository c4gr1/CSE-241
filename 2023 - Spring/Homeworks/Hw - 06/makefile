all: clear clean compile run

compile: main.cpp catalog.cpp 
	@g++ -o test  main.cpp catalog.cpp -std=c++11

run:

	./test
	
clean:

	@rm -f *.o

clear:
	@clear			