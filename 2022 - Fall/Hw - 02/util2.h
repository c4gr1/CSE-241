#ifndef _UTIL2_H_
#define _UTIL2_H_

#include <iostream>
#include <vector>
#include "util1.h"
#include "util2.h"
#include <unistd.h>

using namespace std;

/*  Tetris class for creating game board and adding tetrominos to board */

class Tetris
{
public:
		
	int cursorh;	// Variable that takes the cursor columm position
	int cursorw=1;	// Variable that takes the cursor row position
		
	vector<vector<char>> board;	// Vector variable for board
	vector<vector<char>> tetromino;	// Vector variable for adding tetrominos the board
	
	Tetris();	// Default constructor
	Tetris(int size,int type);	// Initialization constructor
	
	void setSize(int s);	// Functions that assigns the value of class private members
	void setType(char t);	
	
	int getSize() const;	//	Functions that returns the value of class private members
	char getType() const;
		
	void makeBoard(int size);	// Function that fills the board vector
	void Add();	// Function that upgrades the board vector
	void resetBoard();	// Function that reset the previous value of screen when tetrominos drops from screen
	
	void Draw() const;	// Function that prints the game board


private:
	
	int size;	// variable that takes the size of board
	
	char type;	// variable that takes the type of tetrominos

};

#endif
