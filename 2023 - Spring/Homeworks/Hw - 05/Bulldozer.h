#ifndef BULLDOZER_H
#define BULLDOZER_H

#include <iostream>
#include <string>
#include "World.h"
#include "Robot.h"

#include <iostream>
#include <string>   
#include <cstdlib>
#include <time.h>

using namespace std;

//  .h library for Bulldozer type robot which containst the functions prototype

namespace PA5
{

//  Bulldozer class is created by Robot class (inherited from robot class)

class Bulldozer : public Robot  
{
    public:
    Bulldozer(int newType,int newStrenght,int newHit,string name);  //  Constructor for Bulldozer
    string getType() override;  //  Function that returns the type of robot
    int getDamage() override;   //  Function that calculates the damage of robot

}; 
}
#endif