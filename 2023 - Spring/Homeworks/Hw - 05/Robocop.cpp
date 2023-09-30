#include <iostream>
#include <string>
#include "Humanic.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Robocop.h"

using namespace std;

//  .cpp file that contains the implemantation of robocop class
//  it uses the humanic class functions

namespace PA5
{

//  constructor
Robocop::Robocop(int newType,int newStrenght,int newHit,string name) : Humanic(newType,newStrenght,newHit,name)
{}

}