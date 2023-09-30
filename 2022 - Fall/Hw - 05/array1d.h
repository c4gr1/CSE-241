#ifndef _ARRAY1D_H_
#define _ARRAY1D_H_

#include <iostream>
#include <unistd.h>
#include "abstractClass.h"

using namespace std;

namespace cagriYildiz{

class array1d : public abstractClass
{
public:
				
	char * board1d;
	
	array1d();	// Default constructor
	array1d(int size,int type);	// Initialization constructor
	
	void setSize(int s);	// Functions that assigns the value of class private members
	void setType(char t);	
	
	int getSize() const;	//	Functions that returns the value of class private members
	char getType() const;
		
	void makeBoard(int size);	// Function that fills the board vector
	void resetBoard(int back,int width);	// Function that reset the previous value of screen when tetrominos drops from screen
	bool checkBoard(int next,int width)const;
	void Animate()const ;	// Function that prints the game board
	
	void writeToFile()const;
	void readFromFile();
	
	array1d &operator+=(char tetro);		// Function that upgrades the board vector	
	
	char ** board;	// Vector variable for board
	char ** tetromino;	// Vector variable for adding tetrominos the board
	void to1dfrom2d();	// Function for creating 1d array
		
	int numberOfMoves()const;
	void lastMove() const;
		
	int cursorh;	// Variable that takes the cursor columm position
	char moveRotation;	// Variable that takes the rotation of tetromino
	char rotation;	// Variable that takes the rotation of tetromino on board
	int rotationCount;
	int moveRotationCount;
	int middle;	// Variable for printing tetromino on the middle of board

private:
	
	int size;	// variable that takes the size of board
	
	char type;	// variable that takes the type of tetrominos
	
	int numberofmoves=0;

};

}
#endif
