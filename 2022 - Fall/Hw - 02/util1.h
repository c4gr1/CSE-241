#ifndef _UTIL1_H_
#define _UTIL1_H_

#include <iostream>
#include <vector>
#include "util1.h"
#include "util2.h"
#include <unistd.h>

using namespace std;

/* Enum class for the tetromino shapes */

enum class Shapes { Tetromino_I = 'I',Tetromino_O = 'O',Tetromino_T = 'T',Tetromino_J = 'J',Tetromino_L = 'L',Tetromino_S = 'S',Tetromino_Z = 'Z' };

/* Tetromino class for the creating tetromino objects */

class Tetromino
{
public:

		vector<vector<char>> v1;	// 2D vector for tetrominos
				
		Tetromino();	// Initializes the tetromino to Tetromino 'O'	
		Tetromino(Shapes s);	// Initializes the tetromino to arguments
		
		void set(Shapes s);	// Function that takes enum parameter and assigns it to tetromino vector		
		Shapes get() const;	// Function that returns value of shape
				
		void print() const;	//Function that print the vector
		 
		void direction_R(vector<vector<char>> &v2);
		void direction_L(vector<vector<char>> &v2);	// Function that changes the rotate of given vector
		
		bool canFit(Shapes s1, Shapes s2) const;
	
private:

	Shapes shape;	// Variable that takes the user choice
	
};

void checkLetter(char & s);	// Function that checks the user shape input and matches the letter like 's' = 'S' 
void change(char& a, char& b);	//Function that changes the values of variable

#endif
