#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
#include <string>
#include "World.h"
#include "Robot.h"

#include <iostream>
#include <string>   
#include <cstdlib>
#include <time.h>

using namespace std;

//  .h library for roomba class which is inherited from robot class

namespace PA5
{

class Roomba : public Robot
{
    public:
    Roomba(int newType,int newStrenght,int newHit,string name); // constructor
    string getType() override;  //  function that returns the type of robot
    int getDamage() override;   // function that calculates the damage of robot
    
}; 
}
#endif