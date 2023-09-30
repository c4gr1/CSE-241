#include <iostream>
#include <vector>
#include "util1.h"
#include "vectorle.h"
#include <unistd.h>
#include "abstractClass.h"
#include "array1d.h"

using namespace std;

/*************************************************************************************/

/* Function that takes enum parameter and assigns it to the vector  */

void Tetromino::set(Shapes s)
{
	
	shape=s;
		
	switch(s)
	{
	
	case static_cast<Shapes>('I'): v1={
					{'I','I','I','I'}
				};
				
			break;	
	
	case static_cast<Shapes>('O'): v1={
				 	{'O','O'},
					{'O','O'}	
				 };
			
			break;
			
	case static_cast<Shapes>('T') : v1={
				 	{'T','T','T'},
					{' ','T',' '}	
				 };
			
			break;	
			
	case static_cast<Shapes>('J'): v1={
				 	{' ','J'},
					{' ','J'},
					{'J','J'}	
				 };
			
			break;
			
	case static_cast<Shapes>('L') :	v1={
				 	{'L',' '},
					{'L',' '},
					{'L','L'}	
				 };
			
			break;
			
	case static_cast<Shapes>('S') : v1={
				 	{' ','S','S'},
					{'S','S',' '},	
				 };
			
			break;
			
	case static_cast<Shapes>('Z') : v1={
				 	{'Z','Z',' '},
					{' ','Z','Z'},	
				 };
			
			break;						
	
	
	}
}

/*************************************************************************************/

/* Function that returns the value of object  */

Shapes Tetromino::get() const
{

	return shape;

}

/*************************************************************************************/	

/* Function that prints the vector's element in the object  */
	
void Tetromino::print() const
{	
			
		for (int i = 0; i < v1.size(); i++)
		{
		    for (int j = 0; j < v1[i].size(); j++)
		    {
		        cout << v1[i][j] << " ";
		    }    
		    cout << endl;
		}
		
}


/*************************************************************************************/

/* Function that changes the rotate of the every tetrominos object
   Firstly it finds the transpose of given vector and then finds the
   reverse vector and turns the tetromino right

 */

void Tetromino::direction_R(vector<vector<char>> &v2)
{

    vector<vector<char> > transpose(v2[0].size(), vector<char>());

    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
        {
            transpose[j].push_back(v2[i][j]);
        }
    }

    v2 = transpose;

	for (int i = 0; i < v2.size(); i++)
	 {
        int firstElement= 0;
        int lastElement = v2[i].size() - 1;

        while (firstElement < lastElement)
        {
            change(v2[i][firstElement], v2[i][lastElement]);
           	firstElement++;
            lastElement--;
        }
    }

}

/*************************************************************************************/

/* Function that turns the tetrominos left */

void Tetromino::direction_L(vector<vector<char>> &v2)
{

	direction_R(v2);
	direction_R(v2);
	direction_R(v2);

}

/*************************************************************************************/

/* Function that changes the values of variable  */

void change(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

/*************************************************************************************/

/* Default constructor for class which assigns it default 'O' tetromino   */

Tetromino::Tetromino()
{

	v1={ 
		{'O','O'},
		{'O','O'}	
	   };

}

/*************************************************************************************/

/* Constructor for class which using for user definition   */

Tetromino::Tetromino(Shapes s)
{

	set(s);

}

/*************************************************************************************/

/* Function that checks the user shape input and matches the letter like 's' = 'S' */

void checkLetter(char & s)
{

		if(s=='o') s='O';
		else if(s=='t') s='T';
		else if(s=='i') s='I';
		else if(s=='s') s='S';
		else if(s=='z') s='Z';
		else if(s=='l') s='L';
		else if(s=='j') s='J';


}

/*************************************************************************************/

/* Function that checks the tetrominos and decides if they can fit or not */

bool Tetromino::canFit(Shapes s1, Shapes s2) const
{

	if(s1==static_cast<Shapes>('I'))
	{
	
		if(s2==static_cast<Shapes>('O')) return true;
		else if(s2==static_cast<Shapes>('T')) return false;
		else if(s2==static_cast<Shapes>('I')) return true;
		else if(s2==static_cast<Shapes>('S')) return false;
		else if(s2==static_cast<Shapes>('Z')) return true;
		else if(s2==static_cast<Shapes>('L')) return true;
		else if(s2==static_cast<Shapes>('J')) return false; 
		else return true;
	}
	
	else if(s1==static_cast<Shapes>('O'))
	{
	
		if(s2==static_cast<Shapes>('O')) return true;
		else if(s2==static_cast<Shapes>('T')) return false;
		else if(s2==static_cast<Shapes>('I')) return true;
		else if(s2==static_cast<Shapes>('S')) return false;
		else if(s2==static_cast<Shapes>('Z')) return true;
		else if(s2==static_cast<Shapes>('L')) return true;
		else if(s2==static_cast<Shapes>('J')) return false; 
		else return true;
		
	}
	
	else if(s1==static_cast<Shapes>('T'))
	{
	
		if(s2==static_cast<Shapes>('O')) return true;
		else if(s2==static_cast<Shapes>('T')) return false;
		else if(s2==static_cast<Shapes>('I')) return true;
		else if(s2==static_cast<Shapes>('S')) return false;
		else if(s2==static_cast<Shapes>('Z')) return false;
		else if(s2==static_cast<Shapes>('L')) return false;
		else if(s2==static_cast<Shapes>('J')) return false; 
		else return true;
		
	}
	
	else if(s1==static_cast<Shapes>('S'))
	{
	
		if(s2==static_cast<Shapes>('O')) return true;
		else if(s2==static_cast<Shapes>('T')) return false;
		else if(s2==static_cast<Shapes>('I')) return true;
		else if(s2==static_cast<Shapes>('S')) return false;
		else if(s2==static_cast<Shapes>('Z')) return true;
		else if(s2==static_cast<Shapes>('L')) return true;
		else if(s2==static_cast<Shapes>('J')) return false; 
		else return true;
		
	}

	else if(s1==static_cast<Shapes>('Z'))
	{
	
		if(s2==static_cast<Shapes>('O')) return true;
		else if(s2==static_cast<Shapes>('T')) return false;
		else if(s2==static_cast<Shapes>('I')) return true;
		else if(s2==static_cast<Shapes>('S')) return false;
		else if(s2==static_cast<Shapes>('Z')) return true;
		else if(s2==static_cast<Shapes>('L')) return true;
		else if(s2==static_cast<Shapes>('J')) return false; 
		else return true;
		
	}

	else if(s1==static_cast<Shapes>('L'))
	{
	
		if(s2==static_cast<Shapes>('O')) return true;
		else if(s2==static_cast<Shapes>('T')) return false;
		else if(s2==static_cast<Shapes>('I')) return true;
		else if(s2==static_cast<Shapes>('S')) return false;
		else if(s2==static_cast<Shapes>('Z')) return true;
		else if(s2==static_cast<Shapes>('L')) return true;
		else if(s2==static_cast<Shapes>('J')) return false; 
		else return true;
		
	}
	
	else if(s1==static_cast<Shapes>('J'))
	{
	
		if(s2==static_cast<Shapes>('O')) return true;
		else if(s2==static_cast<Shapes>('T')) return false;
		else if(s2==static_cast<Shapes>('I')) return true;
		else if(s2==static_cast<Shapes>('S')) return false;
		else if(s2==static_cast<Shapes>('Z')) return true;
		else if(s2==static_cast<Shapes>('L')) return true;
		else if(s2==static_cast<Shapes>('J')) return false; 
		else return true;
		
	}
	
	else return true;


}
	
/*************************************************************************************/
