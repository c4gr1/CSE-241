#ifndef HUMANIC_H
#define HUMANIC_H

#include <iostream>
#include <string>
#include "World.h"
#include "Robot.h"

//  .h library for humanic type robot

namespace PA5
{

//humanic class is inherited from robot class
class Humanic : public Robot   
{
    public:
    Humanic(int newType,int newStrenght,int newHit,string name);    //  Constructor
    string getType() override;  //  Function that returns robot type
    int getDamage() override;   //  Function that calculates the robot type

};

}

#endif