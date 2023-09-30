#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include <iostream>
#include <string>
#include "World.h"
#include "Robot.h"
#include "Humanic.h"

#include <iostream>
#include <string>   
#include <cstdlib>
#include <time.h>

using namespace std;

//  .h library for optimusprime robot type

namespace PA5
{

//  inherited from humanic class
class OptimusPrime : public Humanic
{
    public:
    OptimusPrime(int newType,int newStrenght,int newHit,string name);   //  constructor
    string getType() override;  //  function that returns the type of robots
    int getDamage() override;   //  function that calculates the robots
    
}; 
}
#endif