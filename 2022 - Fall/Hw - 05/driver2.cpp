#include <iostream>
#include <vector>
#include "util1.h"
#include "vectorle.h"
#include "array1d.h"
#include <unistd.h>	// Library for cursor movements
#include <cstdlib>	// Library for random tetrominos
#include <ctime>	// Library for random tetrominos

using namespace std;
using namespace cagriYildiz;

int main()
{


	srand(time(NULL));

	Tetris tetris;	// Class object for game
	array1d arr1d; 
	
	int size,tempsize;	// Board size
	char type;	// Tetromino type
	int width=0;  // Tetromino widht
	int height;
	char letters[]={'I','O','T','J','L','S','Z'};	// For creating random letter
	char boardtype;	
	
	cout << "\n\n---DRIVER 2 PART---\n\n";	
			
/* Do-while part for user inputs */	
	do{
		
		try
		{				
			cout << "Enter the board size( board size can not be less than 6 )" << endl;	/*  */
			cout << "board size : " ;
			cin >> size ;
			
			if(size<6) throw size;  // Size cant be less than 6
					
		}
		
		catch(int e){
		
		cout << "Board size cant be " << e << " try again "<< endl ; 
		
		}		
		
	}while(size<6);	
		
		
	
		cout << "enter the  class type( V for vector and '1' for 1d Array ) : " << endl;	/*  */
		cout << "class type : " ;
		cin >> boardtype ;
		
		
	tempsize=size;
	
	if(boardtype=='V' || boardtype=='v')
	{
	tetris.setSize(size);
	
	tetris.makeBoard(tetris.getSize());	// Creating game board
		
	do
	{
		
		tetris.cursorh=1;	// Settings for tetrominos animation
		
		cout << "what type of tetromino (I-O-T-L-J-S-Z) for random tetromino press 'R',for quit press 'Q':" << endl;
			
		cout << "Tetromino type is : ";	
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
						
							cout << "enter the rotation and count(like R 3)\n";
							
							cout << "Rotation is : ";
							cin >> tetris.rotation;
						
							cout << "Rotation count is : ";
							cin >> tetris.rotationCount;
							
							cout << "enter the  move rotation and count(like R 3)\n";
					
							cout << "Rotation is : ";
							cin >> tetris.moveRotation;
							
							cout << "Rotation count is : ";
							cin >> tetris.moveRotationCount;						
							
							if(tetris.rotation=='R' || tetris.rotation=='r')
							tetris.middle=tetris.middle+tetris.rotationCount;
						
							if(tetris.rotation=='L' || tetris.rotation=='l')
							tetris.middle=tetris.middle-tetris.rotationCount;
							
						
						}
						
						while(tetris.checkBoard(i,width)==true)						
						{
							
							tetris+=type;
							if(i!=1 )tetris.resetBoard(i-height,width);
							
							cout << "Number of Moves : " << tetris.numberOfMoves() << endl;	
							
							tetris.Animate();
															
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
	
	}
	
		if(boardtype=='1')
	{
	arr1d.setSize(size);
	
	arr1d.makeBoard(arr1d.getSize());	// Creating game board
		
	do
	{
		
		arr1d.cursorh=1;	// Settings for tetrominos animation
		
		cout << "what type of tetromino (I-O-T-L-J-S-Z) for random tetromino press 'R',for quit press 'Q':"<<endl;
		
		cout << "Tetromino type is : ";		
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
			
			arr1d.setType(type);	// Creating the tetrominos
			
			
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
			
			arr1d.middle=size/2-width/2;
																				
					for(int i=1;i<size;i++){
						
						if(i==1) {

							cout << "enter the rotation and count(like R 3)\n";
							
							cout << "Rotation is : ";
							cin >> arr1d.rotation;
							
							cout << "Rotation count is : ";
							cin >> arr1d.rotationCount;
							
							cout << "enter the  move rotation and count(like R 3)\n";
					
							cout << "Rotation is : ";
							cin >> arr1d.moveRotation;
							
							cout << "Rotation count is : ";
							cin >> arr1d.moveRotationCount;							
							
							if(arr1d.rotation=='R' || arr1d.rotation=='r')
							
							arr1d.middle=arr1d.middle+arr1d.rotationCount;
						
							if(arr1d.rotation=='L' || arr1d.rotation=='l')
							arr1d.middle=arr1d.middle-arr1d.rotationCount;
							
						
						}
						
						while(arr1d.checkBoard(i,width)==true)						
						{
							
							arr1d+=type;
							if(i!=1 )arr1d.resetBoard(i-height,width);
							
							cout << "Number of Moves : " << arr1d.numberOfMoves() << endl;	
							
							arr1d.Animate();
															
							arr1d.cursorh++;
						 	usleep(50*10000);
							cout << "\033[3;1H";
							cout << "\033[2J";

						}									
					}
				}
				
		else if(type=='q' || type=='Q') cout << "Game Over !!!\n";	// Condition for terminating game
	
		else cout << "invalid tetromino \n";	
			
	}while(type!='q' && type!='Q');
	
	}
	
	if(boardtype=='V' || boardtype=='v')
	{	
		cout << "AFTER YOUR LAST MOVE THIS IS HOW FINAL BOARD IS LOOK LIKE : \n\n"; 
		tetris.lastMove();
		
		cout << "\nBOARD IS SAVING TO .TXT FILE .......\n\n";
	 	tetris.writeToFile();
	}
	
	if(boardtype=='1')
	{
	 	cout << "AFTER YOUR LAST MOVE THIS IS HOW FINAL BOARD IS LOOK LIKE : \n\n"; 
	 	arr1d.lastMove();
	 	
		cout << "\nBOARD IS SAVING TO .TXT FILE .......\n\n"; 	
	 	arr1d.writeToFile();
	 }
	
	
	return 0;

}	
