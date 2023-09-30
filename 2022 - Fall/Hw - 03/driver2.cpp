#include <iostream>
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
	int width=0;  // Tetromino widht
	int height;
	char letters[]={'I','O','T','J','L','S','Z'};	// For creating random letter
	
/* Do-while part for user inputs */	

	do
	{				
		cout << "enter the board size( board size can not be less than 6 ): " ;	/*  */
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
					
			if(type=='I') width=4;
			else if(type=='O') width=2;
			else if(type=='T') width=3;
			else if(type=='L') width=2;
			else if(type=='J') width=2;
			else if(type=='S') width=3;
			else if(type=='Z') width=3;
			
			if(type=='I') height=1;
			else if(type=='O') height=2;
			else if(type=='T') height=2;
			else if(type=='L') height=3;
			else if(type=='J') height=3;
			else if(type=='S') height=2;
			else if(type=='Z') height=2;
			
			tetris.middle=size/2-width/2;
																				
					for(int i=1;i<size;i++){
						
						if(i==1) {
						
							cout << " enter the rotation and count(like R 3)\n";
					
							cin >> tetris.rotation >> tetris.rotationCount;
							
							cout << " enter the  move rotation and count(like R 3)\n";
					
							cin >> tetris.moveRotation >> tetris.moveRotationCount;							
							
							if(tetris.rotation=='R' || tetris.rotation=='r')
							tetris.middle=tetris.middle+tetris.rotationCount;
						
							if(tetris.rotation=='L' || tetris.rotation=='l')
							tetris.middle=tetris.middle-tetris.rotationCount;
							
						
						}
						
						while(tetris.checkBoard(i,width)==true)						
						{
							
							tetris.Add();
							if(i!=1 )tetris.resetBoard(i-height,width);
							tetris.Draw();	
																
							tetris.cursorh++;
						 	usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";

						}									
					}
				}
				
		else if(type=='q' || type=='Q') cout << "Game Over !!!\n";	// Condition for terminating game
	
		else cout << "invalid tetromino \n";	
			
	}while(type!='q' && type!='Q');
	
	return 0;
	
}
