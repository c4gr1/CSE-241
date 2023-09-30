#include <iostream>
#include <string>

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Bulldozer.h"

using namespace std;

// .cpp file that contains the implementation of Bulldozer class function

namespace PA5
{

//  Default constructor of Bulldozer class that uses the Robot Constructor also
Bulldozer::Bulldozer(int newType,int newStrenght,int newHit,string name) : Robot(newType,newStrenght,newHit,name)
{}

//  Function that returns type of robot
//  case 0 : optimusprime
//  case 1 : robocop
//  case 2 : roomba
//  case 3 : bulldozer
string Bulldozer::getType()
{
    //  switch-case condition for finding the type related with the above information
    switch (type)
    {
    case 0: return "optimusprime";
    case 1: return "robocop";
    case 2: return "roomba";
    case 3: return "bulldozer";
    }

    return "unknown";

}

//  Function that calculates the Bulldozer's damage
//  Its strenght is 50 and it hits damage between 0-50
int Bulldozer::getDamage() 
{

    int damage = (rand() % getStrenght()) + 1 ;
    //  Printing the damage informataion for attacker robot
    cout << getName() << " attacks for " << damage << " points!" << endl;

    return damage;

}

}