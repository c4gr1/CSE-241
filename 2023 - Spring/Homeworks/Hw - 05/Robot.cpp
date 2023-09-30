#include <iostream>
#include <string>
#include "Robot.h"

using namespace std;

//  .cpp file that contains the implementation of robot class functions

namespace PA5
{

//  Default constructor
Robot::Robot()
{
    type=0;
    strenght=0;
    hitPoints=0;
    name="";
}

//  Initializing constructor that uses the given informations
Robot::Robot(int newType,int newStrenght,int newHit,string name)
{

    type=newType;
    strenght=newStrenght;
    hitPoints=newHit;
    this->name=name;
}

//  Destructor
Robot::~Robot()
{}

//  setter for robot type
void Robot::setRobotType(int type)
{
    this->type=type;
}

//  getter for tobot type
int Robot::getRobotType() const
{
    return type;
}

//  setter for strenght
void Robot::setStrenght(int strenght)
{
    this->strenght=strenght;
}

//  getter for strenght
int Robot::getStrenght() const
{
    return strenght;
}

//  setter for hitpoints
void Robot::setHitPoints(int hitPoints)
{
    this->hitPoints=hitPoints;
}

//  getter for hitpoints
int Robot::getHitPoints() const
{
    return hitPoints;
}

//  setter for name
void Robot::setName(string name)
{
    this->name=name;
}

//  getter for name
string Robot::getName() const
{
    return name;
}
















}