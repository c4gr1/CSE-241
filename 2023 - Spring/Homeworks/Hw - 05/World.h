#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
#include "Robot.h"
//#include "Humanic.h"
//#include "OptimusPrime.h"
//#include "Robocop.h"
//#include "Roomba.h"
//#include "Bulldozer.h"

using namespace std;

//  .h library for World class

const int WORLDSIZE = 10;   //  const variable for grid sizes

namespace PA5
{
    class Robot;    //  forward declation of robot class

    class World
    {
    public:
        
        friend class Robot; //  for assigning robots to grid

        World();    //  default constructor
        ~World();   //  Destructor
        Robot* getAt(int x,int y);  //  returns the information at given coordinates
        void setAt(int x,int y,Robot *rbt); //  sets robot to grid at given coordinates
        void Display(); //  prints the grid
        int SimulateOneStep(int x,int y);   //  simulation function it return 1 if attacker wins 0 for defender wins -1 for nothing
    
    private:

        Robot* grid[WORLDSIZE][WORLDSIZE];  //  variable for grid

    };
}

#endif 