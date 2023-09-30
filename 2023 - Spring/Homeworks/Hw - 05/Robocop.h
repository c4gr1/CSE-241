#ifndef ROBOCOP_H
#define ROBOCOP_H

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

//  .h library for robocop 

namespace PA5
{

//  inherited from humanic class
class Robocop : public Humanic
{
    public:
    Robocop(int newType,int newStrenght,int newHit,string name);    // constructor

}; 
}
#endif