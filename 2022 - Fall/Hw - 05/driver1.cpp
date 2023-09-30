#include <iostream>
#include <vector>
#include "util1.h"
#include "vectorle.h"
#include <unistd.h>
#include "abstractClass.h"
#include "array1d.h"

using namespace std;
using namespace cagriYildiz;

/* cpp file for checking variables and functions */

int main()
{
	
	cout << "\n-----DRIVER 1 PART-----\n";
	
	cout << "\n\n---PLUS MINUS TABLE---\n\n";
	
	cout << "ABSTACT TETRIS CLASS +++" << endl;
	cout << "CONCRETE TETRIS VECTOR CLASS +++" << endl;
	cout << "CONCRETE TETRIS 1D CLASS +++" << endl;
	cout << "FUNCTION DRAW +++ " << endl;
	cout << "FUNCTION WRITETOFILE +++ " << endl;
	cout << "FUNCTION  OPERATOR+= +++ " << endl;
	cout << "FUNCTION ANIMATE +++ " << endl;
	cout << "FUNCTION FIT (DID NOT IMPLEMENTED) +++ " << endl;
	cout << "FUNCTION LAST MOVE +++ " << endl;
	cout << "FUNCTION NUMBER OF MOVES +++ " << endl;
	cout << "NAMESPACES AND SEPARATE INTERFACES +++ " << endl;
	cout << "EXCEPTIONS +++ " << endl << endl;
	
	cout << "FUNCTION READFROMFILE --- " << endl;
	cout << "TEMPLATE CLASS --- " << endl;
	cout << "MY TETROMINOS CANT RETURN AROUND ITSELF ---" << endl;
	cout << "2 DAYS LATE SUBMIT ---" << endl ;
	
	
	Tetromino test1;
	Tetromino test2(static_cast<Shapes>('T'));
	
	Tetris test3;
	Tetris test4(10,'L');
	
	array1d test5;
	array1d test6(15,'T');
	
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
	
	cout << "\n---DEFAULT CONSTRUCTOR OF VECTOR TETRIS CLASS---\n";
	cout << "size :" << test3.getSize() << "----" << "type :" << test3.getType();
	
	cout << "\n\n---USER-DEFINED CONSTRUCTOR OF VECTOR TETRIS CLASS---\n";
	cout << "size :" << test4.getSize() << "----" << "type :" << test4.getType();
	
	cout << "\n\n---DEFAULT ANIMATE FUNCTION OF VECTOR TETRIS CLASS---\n";
	test3.makeBoard(test3.getSize());
	test3.Animate();
	
	cout << "\n\n---NUMBEROFMOVES FUNCTION OF VECTOR CLASS---\n";
	cout << "Number of initial moves is => " << test3.numberOfMoves() << endl;
	
	cout << "\n---DEFAULT CONSTRUCTOR OF 1D TETRIS CLASS---\n";
	cout << "size :" << test5.getSize() << "----" << "type :" << test5.getType();
	
	cout << "\n\n---USER-DEFINED CONSTRUCTOR OF 1D TETRIS CLASS---\n";
	cout << "size :" << test6.getSize() << "----" << "type :" << test6.getType();
	
	cout << "\n\n---DEFAULT ANIMATE FUNCTION OF 1D TETRIS CLASS---\n";
	test3.makeBoard(test6.getSize());
	test3.Animate();
	
	cout << "\n\n---NUMBEROFMOVES FUNCTION OF 1D TETRIS CLASS---\n";
	cout << "Number of initial moves is => " << test3.numberOfMoves() << endl;
	
	cout << "\nTHE REST OF THE FUNCTIONS CAN BE TESTED DRIVER 2 PART YOU CAN SEE THE .TXT FILES AFTER EXECUTION \n";
	
	cout << endl << endl ;
	
	
	return 0;
	
}
