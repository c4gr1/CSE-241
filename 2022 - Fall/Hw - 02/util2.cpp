#include "util1.h"
#include "util2.h"
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

/*************************************************************************************/

/* Function that fills the board vector */

void Tetris::makeBoard(int size)
{

	for(int i=0; i<size ;i++)
	{	
		
		vector<char> v2;
		
		for(int j=0; j<size ;j++)
		{		
			if(i==0 || i==size-1) v2.push_back('#');
			else if (j==0 || j==size-1) v2.push_back('#');
			else v2.push_back(' ');
		}
			
		board.push_back(v2);
		
	}	
}	

/*************************************************************************************/

/* Function that prints the game board */

void Tetris::Draw() const
{

	for(int i=0; i<size ;i++)
	{	
		for(int j=0; j<size ;j++)
		{
		
			cout << board[i][j];
		
		}
	
		cout << endl;
		
	}
	
}
/*************************************************************************************/

/* Functions that assigns the value of class private members */

void Tetris::setSize(int s)
{

	size=s;

}

/*************************************************************************************/

/* Functions that assigns the value of class private members */

void Tetris::setType(char s)
{

	type=s;

}

/*************************************************************************************/

/* Default constructor */

Tetris::Tetris():size(10),type('O')
{

	//Initially empty	
	
}

/*************************************************************************************/

/* Initialization constructor */

Tetris::Tetris(int size,int type)
{

	setSize(size);
	setType(type);

}

/*************************************************************************************/

/* Functions that returns the value of class private members */

int Tetris::getSize() const
{

	return size;

}

/*************************************************************************************/

/* Functions that returns the value of class private members */

char Tetris::getType() const
{

	return type;

}

/*************************************************************************************/

/* Function that reset the previous value of screen when tetrominos drops from screen */

void Tetris::resetBoard()
{

	for(int i=1;i<cursorh;i++)
			for(int j=1;j<size-1;j++)
				board[i][j]=' ';


}


/*************************************************************************************/

/* Function that upgrades the board vector */

void Tetris::Add()
{
	
	int h,w,temp1,temp2;
	
	temp1=cursorh;
	temp2=cursorw;
	
	switch(type)
	{
	
	case ('I'): 
				h=1;
				w=4;
				tetromino={
					{'I','I','I','I'}
				};
				
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					board[temp1+i][temp2+j]=tetromino[i][j];	
							
			break;	
	
	case ('O'): 
				h=2;
				w=2;
				tetromino={
				 	{'O','O'},
					{'O','O'}	
				 };
				 
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					board[temp1+i][temp2+j]=tetromino[i][j];
			
			break;
			
	case ('T') : 
				h=2;
				w=3;
				tetromino={
				 	{'T','T','T'},
					{' ','T',' '}	
				 };
				 
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					board[temp1+i][temp2+j]=tetromino[i][j];
			
			break;	
			
	case ('J'): 
				h=3;
				w=2;				
				tetromino={
				 	{' ','J'},
					{' ','J'},
					{'J','J'}	
				 };
				 
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					board[temp1+i][temp2+j]=tetromino[i][j];
			
			break;
			
	case ('L') : 
	
				h=3;
				w=2;
				tetromino={
				 	{'L',' '},
					{'L',' '},
					{'L','L'}	
				 };
				 
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					board[temp1+i][temp2+j]=tetromino[i][j];
				 		
			break;
			
	case ('S'): 
				
				h=2;
				w=3;
				tetromino={
				 	{' ','S','S'},
					{'S','S',' '},	
				 };

			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					board[temp1+i][temp2+j]=tetromino[i][j];	
							
			break;
			
	case ('Z') : 
				h=2;
				w=3;	
				tetromino={
				 	{'Z','Z',' '},
					{' ','Z','Z'},	
				 };
				 
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					board[temp1+i][temp2+j]=tetromino[i][j];	
							
			break;			

	}
}	
