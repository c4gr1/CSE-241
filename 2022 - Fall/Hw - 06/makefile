all: clear clean compile run

compile: main.cpp pfarray.cpp 
	@g++ -o test1  main.cpp pfarray.cpp -std=c++11

run:

	@echo "Running the test1...."
	./test1

clean:

	@rm -f *.o

clear:
	@clear			