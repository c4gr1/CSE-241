#include <iostream>
#include <string>

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Roomba.h"

using namespace std;

//  .cpp file that contains the implemantation of roomba class functions

namespace PA5
{

//  constructor
Roomba::Roomba(int newType,int newStrenght,int newHit,string name) : Robot(newType,newStrenght,newHit,name)
{}

//  function that returns type of robot
string Roomba::getType()
{

    //  switch case condition for finding type
    switch (type)
    {
    case 0: return "optimusprime";
    case 1: return "robocop";
    case 2: return "roomba";
    case 3: return "bulldozer";
    }

    return "unknown";

}

//  function that calculates the damage of robots
int Roomba::getDamage() 
{
    //  roomba type robots are fast so they hits twice
    //  damage between 0-10
    int damage = (rand() % getStrenght())+1;
    int damage2 = (rand() % getStrenght())+1;
    //  hitting information
    cout << getName() << " attacks for " << damage << " points!" << endl;
    cout << getName() << " attacks for " << damage2 << " points!" << endl;
    return damage+damage2;

}


}