#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "World.h"
#include "Robot.h"
#include "Humanic.h"
#include "OptimusPrime.h"
#include "Robocop.h"
#include "Roomba.h"
#include "Bulldozer.h"  

using namespace std;
using namespace PA5;

//  main function that makes similation for robot

//  variable that holds the number of each robot type
const int initial_count_of_each_robot_type = 5;

int main(){

    srand(time(NULL));  //  command that makes different variations of rand() function

    World w;    //  World class object that holds the robots in the 10x10 grid

    int number_of_robots = 20;  //   varaible for calculating for the last robot

    int optimusPrimeCount=0;    //  initial number of optimusprime type

    //  while loop for assigning the robots to grid randomly
    while(optimusPrimeCount<initial_count_of_each_robot_type)
    {
        //  creating random coordinates
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        //  checking the coordinates
        if (w.getAt(x,y)==NULL)
        {
            string name = "optimusprime_"+to_string(optimusPrimeCount); // name of the robot
            optimusPrimeCount++;    //  calculating the robots count 
            OptimusPrime *a = new OptimusPrime(0,100,100,name); // creating the object
            w.setAt(x,y,a); //  setting the robot to grid 
        }
 
    }

    int robocopCount=0; //  initial number of robocop type

    //  while loop for assigning the robots to grid randomly
    while(robocopCount<initial_count_of_each_robot_type)
    {
        //  creating random coordinates
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        //  checking the coordinates
        if (w.getAt(x,y)==NULL)
        {
            string name = "robocop_"+to_string(robocopCount);   // name of the robot
            robocopCount++; //  calculating the robots count
            Robocop *b = new Robocop(1,30,40,name); // creating the object
            w.setAt(x,y,b); //  setting the robot to grid 
        }
    }

    int roombaCount=0;  //  initial number of roomba type

    //  while loop for assigning the robots to grid randomly
    while(roombaCount<initial_count_of_each_robot_type)
    {
        //  creating random coordinates
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        //  checking the coordinates
        if (w.getAt(x,y)==NULL)
        {
            string name = "roomba_"+to_string(roombaCount); // name of the robot
            roombaCount++;  //  calculating the robots count
            Roomba *c = new Roomba(2,3,10,name);    // creating the object
            w.setAt(x,y,c); //  setting the robot to grid 
        }
    }

    int bulldozerCount=0;   //  initial number of bulldozer type

    //  while loop for assigning the robots to grid randomly
    while(bulldozerCount<initial_count_of_each_robot_type)
    {
        //  creating random coordinates
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;

        //  checking the coordinates
        if (w.getAt(x,y)==NULL)
        {
            string name = "bulldozer_"+to_string(bulldozerCount);   // name of the robot
            bulldozerCount++;   //  calculating the robots count
            Bulldozer *d = new Bulldozer(3,50,200,name);    // creating the object
            w.setAt(x,y,d); //  setting the robot to grid 
        }   
    }

/*
//  If you want to checks the grid and type of robot at grid use code below
//    w.Display();
//
//    for(int i=0;i<10;i++)
//       for(int j=0;j<10;j++) if(w.getAt(i,j)!=NULL) cout << w.getAt(i,j)->getName() << endl;
//
*/

    int i,j;    //  variable for loops
    int k;  //  variable for value of simulation function

    //  for loop for simulating the robots int the grid
    for(i=0;i<WORLDSIZE;i++)
        for(j=0;j<WORLDSIZE;j++)
        {
            //  this function returns 1 if attacker robot wins
            //  returns 0 if deferder robot wins
            //  if no war returns -1
            k = w.SimulateOneStep(i,j);

            //  if value of k 1 or 0 we are deleting the number of robots count so we have a end condition
            if(k!=-1) 
            {
                cout << endl;
                //w.Display();
                number_of_robots--;
                //cout << "NUM_OF_ROB IS " << number_of_robots << endl; 
            }

            if(number_of_robots==1) break;  //  when last robots is staying the grid,simulation is over
                
        }         

    return 0;
}