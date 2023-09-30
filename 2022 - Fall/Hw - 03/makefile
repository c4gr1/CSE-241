all: clear clean compile run

compile: driver1.cpp driver2.cpp util1.cpp util2.cpp 
	@g++ -o test1  driver1.cpp util1.cpp util2.cpp -std=c++11
	@g++ -o test2  driver2.cpp util1.cpp util2.cpp -std=c++11

run:

	@echo "Running the test1...."
	./test1
	
	@echo "Running the test2...."
	./test2

clean:

	@rm -f *.o

clear:
	@clear			
