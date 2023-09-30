#include "util1.h"
#include "array1d.h"
#include "fstream"
#include <cstdlib>


using namespace std;

namespace cagriYildiz{

/*************************************************************************************/

/* Function that fills the board vector */

void array1d::makeBoard(int size)
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

void array1d::Animate() const
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

void array1d::setSize(int s)
{

	size=s;

}

/*************************************************************************************/

/* Functions that assigns the value of class private members */

void array1d::setType(char s)
{

	type=s;

}

/*************************************************************************************/

/* Default constructor */

array1d::array1d():size(10),type('O')
{

	//Initially empty	
	
}

/*************************************************************************************/

/* Initialization constructor */

array1d::array1d(int size,int type)
{

	setSize(size);
	setType(type);

}

/*************************************************************************************/

/* Functions that returns the value of class private members */

int array1d::getSize() const
{

	return size;

}

/*************************************************************************************/

/* Functions that returns the value of class private members */

char array1d::getType() const
{

	return type;

}

/*************************************************************************************/

/* Function that reset the previous value of screen when tetrominos drops from screen */

void array1d::resetBoard(int back,int width) 
{

		for(int j=0;j<width;j++)
				board[back][middle+j]=' ';


}


/*************************************************************************************/

bool array1d::checkBoard(int next,int widht) const
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

void array1d::lastMove() const{


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

int array1d::numberOfMoves()const{return numberofmoves;}

/*************************************************************************************/
void array1d::to1dfrom2d(){


	int newsize=size*size;
	
	board1d = new char [size];
	
	for(int i=0;i<newsize;i++)
		for(int j=0;j<size;j++)
			for(int k=0;k<size;k++) board1d[i]=board[j][k]; 

}

/*************************************************************************************/
void array1d::writeToFile() const{


	ofstream outStream;
	
	outStream.open("Board1D.txt");
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){  outStream << board[i][j];}
		outStream << "\n";
	
	}


	outStream.close();


}


/*************************************************************************************/

void array1d::readFromFile(){


	ifstream inStream;
	
	inStream.open("game1d.txt");
	
	if(inStream.fail())
	{
	
		cout << "Input file opening failed \n";
		exit(1);
	}
	
	
	inStream >> size >> type ;


	inStream.close();

}
/*************************************************************************************/

/* Function that upgrades the board vector */

	array1d &array1d::operator+=(char tetro)
{
	
	int h,w,temp1,temp2;
	
	temp1=cursorh;
	
	numberofmoves++;
		
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
	
	return *this;
	
}
}	
