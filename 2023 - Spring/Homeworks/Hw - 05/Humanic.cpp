#include <iostream>
#include <string>
#include "Humanic.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

//  .cpp file that containst the implementation of Humanic class functions

namespace PA5
{

//  Constructor for Humanic class
Humanic::Humanic(int newType,int newStrenght,int newHit,string name) : Robot(newType,newStrenght,newHit,name)
{}

//  Function that returns the type of robot
string Humanic::getType()
{

    //  switch-case condition for finding the type
    switch (type)
    {
    case 0: return "optimusprime";
    case 1: return "robocop";
    case 2: return "roomba";
    case 3: return "bulldozer";
    }

    return "unknown";

}

//  Function that calculates the damage for given type
int Humanic::getDamage() 
{

    //  damage of optimusprime can be between 0-100
    //  damage of robocop can be between 0-30
    int damage = (rand() % getStrenght()) + 1 ;
    
    //  Attackers hitting information
    cout << getName() << " attacks for " << damage << " points!" << endl;

    //  Humanic type robots can damage extra 50 dmg with chance of 10
    if(rand() % 10 == 0)
    {
        damage += 50;
        cout << "Tactical nuke attack by " << getName() << "! Additional 50 points!" << endl;

    }

    return damage;

}


}