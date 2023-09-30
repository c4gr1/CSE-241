#include <iostream>
#include <vector>
#include "util1.h"
#include "util2.h"
#include <unistd.h>

using namespace std;

int main()
{
	
	cout << "\n-----DRIVER 1 PART-----\n";
	
	Tetromino test1;
	Tetromino test2(static_cast<Shapes>('T'));
	
	Tetris test3;
	Tetris test4(10,'L');
	
	char getTest1,getTest2;
	
	cout << "\n---DEFAULT CONSTRUCTOR OF TETROMINO CLASS---\n";
	test1.print();
	
	cout << "\n---USER-DEFINED CONSTRUCTOR TETROMINO CLASS---\n";
	test2.print();
	
	cout << "\n---DIRECTION_R FUNCTION FOR USER-DEFINED CONSTRUCTOR TETROMINO CLASS---\n";
	test2.direction_R(test2.v1);
	test2.print();

	cout << "\n---DIRECTION_L FUNCTION FOR USER-DEFINED CONSTRUCTOR TETROMINO CLASS---\n";
	test2.direction_L(test2.v1);
	test2.direction_L(test2.v1);
	test2.print();
	
	cout << "\n---DEFAULT CONSTRUCTOR OF TETRIS CLASS---\n";
	cout << "size :" << test3.getSize() << "----" << "type :" << test3.getType();
	
	cout << "\n\n---USER-DEFINED CONSTRUCTOR OF TETRIS CLASS---\n";
	cout << "size :" << test4.getSize() << "----" << "type :" << test4.getType();
	
	cout << "\n\n---MAKEBOARD FUNCTION OF TETRIS CLASS---\n";
	test3.makeBoard(test3.getSize());
	test3.Draw();
	
	cout << "\n-----DRIVER 2 PART-----\n\n";
	
	return 0;
	
}
