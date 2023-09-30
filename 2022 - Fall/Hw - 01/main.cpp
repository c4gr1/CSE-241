#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count=0;	// Variable that takes the number of tetromino
	
	char userShape;	// Variable that takes the shapes of tetromino
	
	Shapes userEnumShape;	//Variable that takes the shapes of tetromino in enum type

	cout << "How many tetrominos ?\n";
	
	/* A loop for valid user input if user selects wrong input program will ask again */
	
	while(count<=0)
	{
	
		cin >> count;
	
		if(count<=0) cout << " wrong input try again \n";
	
	}
	
	vector<Tetromino> tetris(count);	// Vector of class
		
	cout << "What are the types ?\n";
		
	for(int i=0;i<count;i++)
	{		
		cin >> userShape;
	
		if(userShape=='o' || userShape=='O' || userShape=='t' || userShape=='T'|| userShape=='i'|| userShape=='I'|| userShape=='s'
		|| userShape=='S'|| userShape=='z'|| userShape=='Z'|| userShape=='l' || userShape=='L' || userShape=='j' || userShape=='J')
		{		
			checkLetter(userShape);	// Function that checks the user shape input and matches the letter like 's' = 'S'
					
			userEnumShape=static_cast<Shapes>(userShape);	// Changing the variable type for the sending the class
		
			tetris[i].set(userEnumShape);	// Creating the tetromino objects	
		}

		else
		{	
			i--;
			cout << "wrong input try again;\n";	
		}	
	}
	
	/* Printing the tetromino objects */
		
	cout << "Your Tetrominos\n\n";	
	
	for (int i = 0; i < tetris.size(); i++)
        {
            tetris[i].print();
            cout << endl;                 
        }
        
    cout << "Horizontaly best fit tetrominos !! NOTE : I COULDNT PRINT TETROMINOS LEFT-RİGHT SO I PRINTED THEM VERTICALLY\n\n" ;  
    
    //Loop for the check the tetrominos if they can fit or not , if they can not fit and rotate function changes the tetromino rotation
                  
    for (int i = 0; i < tetris.size()-1; i++)
        {        
         if(tetris[i].canFit(tetris[i].get(),tetris[i+1].get())==false)
         	{
         		if(tetris[i].get()==static_cast<Shapes>('T'))	tetris[i].direction_L(tetris[i].v1);
         		else if(tetris[i].get()==static_cast<Shapes>('S'))	tetris[i].direction_L(tetris[i].v1);
         		else if(tetris[i].get()==static_cast<Shapes>('J'))	tetris[i].direction_R(tetris[i].v1);      	   
         	}                
        } 
    
    //Loop for best fit tetrominos
        
    for (int i = 0; i < tetris.size(); i++)
        {
            tetris[i].print();            
        }       
        
 	return 0;
}
