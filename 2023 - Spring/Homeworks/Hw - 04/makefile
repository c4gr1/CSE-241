all: clear clean compile run

compile: main.cpp SchoolManagerSystem.cpp Student.cpp Course.cpp
	@g++ -o test  main.cpp SchoolManagerSystem.cpp Student.cpp Course.cpp -std=c++11

run:

	./test
	
clean:

	@rm -f *.o

clear:
	@clear			
