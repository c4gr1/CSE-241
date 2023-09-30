all: clear clean compile run

compile: main.cpp util.cpp 
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++ -o test main.cpp util.cpp -std=c++11

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o

clear:
	@clear
