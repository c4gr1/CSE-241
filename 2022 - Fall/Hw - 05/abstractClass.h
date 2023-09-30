#ifndef _ABSTRACTCLASS_H_
#define _ABSTRACTCLASS_H_

#include "vectorle.h"

using namespace std;

class abstractClass
{
public:
		
	virtual void makeBoard(int size)=0;	// Function that fills the board vector
	virtual abstractClass &operator+=(char )=0;
	virtual void resetBoard(int back,int width)=0;	// Function that resets the previous value of screen when tetrominos drops from screen
	virtual bool checkBoard(int next,int width)const=0;	// Function that checks the next step of animation and return true or false 
	virtual void Animate()const=0 ;	// Function that prints the game board
	void fit();	
	virtual	int numberOfMoves()const=0;	//Function that returns the number of tetromino moves
	virtual void writeToFile()const=0;	// Function that writes the board to file
	virtual void readFromFile()=0;	// Function that reads for board from file
	virtual void lastMove() const =0;	// Function that shows the final board
	
	

};

#endif
