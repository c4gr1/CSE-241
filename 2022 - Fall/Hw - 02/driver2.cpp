#include <iostream>
#include <vector>
#include "util1.h"
#include "util2.h"
#include <unistd.h>	// Library for cursor movements
#include <cstdlib>	// Library for random tetrominos
#include <ctime>	// Library for random tetrominos

using namespace std;

int main(){

	srand(time(NULL));

	Tetris tetris;	// Class object for game 
	
	int size,tempsize;	// Board size
	char type;	// Tetromino type
	int width=0; // Tetromino widht
	char letters[]={'I','O','T','J','L','S','Z'};	// For creating random letter
	
/* Do-while part for user inputs */	
	
	do
	{				
		cout << "enter the  board size( board size can not be less than 6 ): " ;	/*  */
		cin >> size;
				
	}while(size<6);  // Size cant be less than 6	
	
	tempsize=size;
	
	tetris.setSize(size);	
	
	tetris.makeBoard(tetris.getSize());	// Creating game board
		
	do
	{
		
		tetris.cursorh=1;	// Settings for tetrominos animation
		
		cout << "what type of tetromino (I-O-T-L-J-S-Z) for random tetromino press 'R',for quit press 'Q':";
			
		cin >> type;
		
		if(type=='o' || type=='O' || type=='i' || type=='I' || type=='t' || type=='T' || type=='r' || type=='R' ||type=='l' || type=='L' || type=='j' || type=='J' || type=='s' || type=='S' || 		   type=='z' || type=='Z')
		{
		
			if(type=='i') type='I';
			else if(type=='o') type='O';
			else if(type=='t') type='T';
			else if(type=='l') type='L';
			else if(type=='j') type='J';
			else if(type=='s') type='S';
			else if(type=='z') type='Z';
			
			int d=rand()%7;		// For creating random tetrominos input 
			
			if(type=='R' || type=='r') {type=letters[d];}	// For creating random tetrominos input 
			
			tetris.setType(type);	// Creating the tetrominos
			
			/* Settings for board  */
					
			if(type=='I') width=width+4;
			else if(type=='O') width=width+2;
			else if(type=='T') width=width+3;
			else if(type=='L') width=width+2;
			else if(type=='J') width=width+2;
			else if(type=='S') width=width+3;
			else if(type=='Z') width=width+3;
			
			/* to avoid endless input */
			
			if(size<=3) 
			{
				cout<< "no space left game terminated \n";
					return 0;
				
			}
			
			else
			{
				
				if(width>size-2){tetris.cursorw=1;}		// For reseting the cursor 		
				
				if(width<size)	// Case for board situations
				{	
					if(type=='I')
					{
						for(int i=0;i<size-2;i++)
						{			
							tetris.Add();
							tetris.resetBoard();
							tetris.Draw();	
											
							tetris.cursorh++;
							usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";			
						}						}
				
					else if(type=='O'  || type=='S' ||  type=='Z' || type=='T')        
					{    
						for(int i=0;i<size-3;i++)
						{										
							tetris.Add();
							tetris.resetBoard();
							tetris.Draw();
								
							tetris.cursorh++;
							usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";			
						}						}	
					
					else if(type=='J' || type=='L')
					{	
					for(int i=0;i<size-4;i++)
						{
							tetris.Add();
							tetris.resetBoard();
							tetris.Draw();
												
							tetris.cursorh++;
							usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";		
						}	
					}	
		  	 	}
			   
		   		else if(width>=size)	// To avoid overlapping tetrominos
		   		{			
		   			
		   			size=size-3;
				
					width=0;
							
					if(type=='I')
					{
						for(int i=0;i<size-2;i++)
						{			
							tetris.Add();
							tetris.resetBoard();
							tetris.Draw();	
											
							tetris.cursorh++;
							usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";			
						}	
					}
					
					else if(type=='O'  || type=='S' ||  type=='Z' || type=='T')        
					{    
						for(int i=0;i<size-3;i++)
						{		
							tetris.Add();
							tetris.resetBoard();
							tetris.Draw();
																
							tetris.cursorh++;
							usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";			
						}
					}	
						
					else if(type=='J' || type=='L')
					{	
						for(int i=0;i<size-4;i++)
						{		
							tetris.Add();
							tetris.resetBoard();
							tetris.Draw();
												
							tetris.cursorh++;
							usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";		
						}					
					}
						
				}
			
			/* Tetrominos widhts*/
									   
			if(type=='I') tetris.cursorw+=4;
			else if(type=='S' || type=='Z' || type=='T') tetris.cursorw+=3;	       
			else if(type=='O' || type=='J' || type=='L')	tetris.cursorw+=2;
			  		   
			}
	
		}
	
		else if(type=='q' || type=='Q') cout << "Game Over !!!\n";	// Condition for terminating game
	
		else cout << "invalid tetromino \n";	
			
	}while(type!='q' && type!='Q');
	
	return 0;
	
}
