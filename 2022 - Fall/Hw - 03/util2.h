#ifndef _UTIL2_H_
#define _UTIL2_H_

#include <iostream>
#include "util1.h"
#include "util2.h"
#include <unistd.h>

using namespace std;

/*  Tetris class for creating game board and adding tetrominos to board */

class Tetris
{
public:
		
	int cursorh;	// Variable that takes the cursor columm position
	char moveRotation;	// Variable that takes the rotation of tetromino
	char rotation;	// Variable that takes the rotation of tetromino on board
	int rotationCount;
	int moveRotationCount;
	int middle;	// Variable for printing tetromino on the middle of board
		
	char ** board;	// Dynamic variable for board
	char ** tetromino;	// Dynamic variable for tetromino
	
	Tetris();	// Default constructor
	Tetris(int size,int type);	// Initialization constructor
	Tetris(const Tetris& object);	// Copy constructor
	//~Tetris();
	
	void setSize(int s);	// Functions that assigns the value of class private members
	void setType(char t);	
	
	int getSize() const;	//	Functions that returns the value of class private members
	char getType() const;
		
	void makeBoard(int size);	// Function that fills the board vector
	void Add();	// Function that upgrades the board vector
	void resetBoard(int back,int width);	// Function that resets the previous value of screen when tetrominos drops from screen
	bool checkBoard(int next,int width);	// Function that checks the next step of animation and return true or false 
	void Draw() const;	// Function that prints the game board


private:
	
	int size;	// variable that takes the size of board
	
	char type;	// variable that takes the type of tetrominos

};

#endif
