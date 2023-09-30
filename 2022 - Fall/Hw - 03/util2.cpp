#include "util1.h"
#include "util2.h"
#include <iostream>
#include <unistd.h>

using namespace std;

/*************************************************************************************/

/* Function that fills the board vector */

void Tetris::makeBoard(int size)
{
	
	board= new char *[size];
	
	for(int i=0 ; i<size ;i++) board[i] = new char[size];	
		
	for(int i=0; i<size ;i++)
	{				
		for(int j=0; j<size ;j++)
		{		
			if(i==0 || i==size-1) board[i][j]='#';
			else if (j==0 || j==size-1) board[i][j]='#';
			else board[i][j]=' ';
		}					
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

Tetris::Tetris(const Tetris& object):size(object.getSize()),type(object.getType())

{

	board= new char *[size];
	
	for(int i=0 ; i<size ;i++) board[i] = new char[size];
	
	
	tetromino= new char *[2];
	
	for(int i=0 ; i<2 ;i++) tetromino[i] = new char[2];	
				
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++) tetromino[i][j]='O';



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

void Tetris::resetBoard(int back,int width)
{

		for(int j=0;j<width;j++)
				board[back][middle+j]=' ';


}


/*************************************************************************************/

bool Tetris::checkBoard(int next,int widht)
{
 
	if(next>=size) return false;
	
	else{

		for(int j=0;j<widht;j++){
			if(board[next][middle+j]!=' ') return false	;	
		}
		
		
	return true;
	
	}		
}


/*************************************************************************************/

/* Function that upgrades the board vector */

void Tetris::Add()
{
	
	int h,w,temp1,temp2;
	
	temp1=cursorh;
		
	switch(type)
	{
	
	case ('I'): 
				h=1;
				w=4;
				
				tetromino= new char *[1];
	
				for(int i=0 ; i<1 ;i++) tetromino[i] = new char[4];	
				
				for(int i=0;i<1;i++)
					for(int j=0;j<4;j++) tetromino[i][j]='I';
							
						
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						board[temp1+i][middle+j]=tetromino[i][j];	
							
				break;	
	
	case ('O'): 
				h=2;
				w=2;

				tetromino= new char *[2];
	
				for(int i=0 ; i<2 ;i++) tetromino[i] = new char[2];	
				
				for(int i=0;i<2;i++)
					for(int j=0;j<2;j++) tetromino[i][j]='O';				

				 
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						board[temp1+i][middle+j]=tetromino[i][j];
			
				break;
			
	case ('T') : 
				h=2;
				w=3;
				
				tetromino= new char *[2];
	
				for(int i=0 ; i<2 ;i++) tetromino[i] = new char[3];	
				
				for(int i=0;i<2;i++)
					for(int j=0;j<3;j++){
						 if((i==1 && j==0) || (i==1 && j==2) ) tetromino[i][j]=' ';
						 else 	 tetromino[i][j]='T';		
					}
				 
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						board[temp1+i][middle+j]=tetromino[i][j];
			
				break;	
			
	case ('J'): 
				h=3;
				w=2;
				
				tetromino= new char *[3];
	
				for(int i=0 ; i<3 ;i++) tetromino[i] = new char[2];	
				
				for(int i=0;i<3;i++)
					for(int j=0;j<2;j++){
						 if((i==0 && j==0) || (i==1 && j==0) ) tetromino[i][j]=' ';
						 else 	 tetromino[i][j]='J';
					}								

				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						board[temp1+i][middle+j]=tetromino[i][j];
				
				break;
			
	case ('L') : 
	
				h=3;
				w=2;
				
				tetromino= new char *[3];
	
				for(int i=0 ; i<3 ;i++) tetromino[i] = new char[2];	
				
				for(int i=0;i<3;i++)
					for(int j=0;j<2;j++){
						 if((i==0 && j==1) || (i==1 && j==1) ) tetromino[i][j]=' ';
						 else 	 tetromino[i][j]='L';				
					}
				 
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						board[temp1+i][middle+j]=tetromino[i][j];
					 		
				break;
			
	case ('S'): 
				
				h=2;
				w=3;
				
				tetromino= new char *[2];
	
				for(int i=0 ; i<2 ;i++) tetromino[i] = new char[3];	
				
				for(int i=0;i<2;i++)
					for(int j=0;j<3;j++){
						 if((i==0 && j==0) || (i==1 && j==2) ) tetromino[i][j]=' ';
						 else 	 tetromino[i][j]='S';				
					}

				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						board[temp1+i][middle+j]=tetromino[i][j];	
								
				break;
			
	case ('Z') : 
				h=2;
				w=3;	

				tetromino= new char *[2];
	
				for(int i=0 ; i<2 ;i++) tetromino[i] = new char[3];	
				
				for(int i=0;i<2;i++)
					for(int j=0;j<3;j++){
						 if((i==0 && j==2) || (i==1 && j==0) ) tetromino[i][j]=' ';
						 else 	 tetromino[i][j]='Z';
					}
				 
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						board[temp1+i][middle+j]=tetromino[i][j];	
								
				break;			

	}
}	
