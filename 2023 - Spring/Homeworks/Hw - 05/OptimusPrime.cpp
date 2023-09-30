#include <iostream>
#include <string>
#include "Humanic.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "OptimusPrime.h"

using namespace std;

//  .cpp file contains the implementation of the OptimusPrime class functions

namespace PA5
{

//  constructor
OptimusPrime::OptimusPrime(int newType,int newStrenght,int newHit,string name) : Humanic(newType,newStrenght,newHit,name)
{}

//  function that returns the type fo robot
string OptimusPrime::getType()
{
    //  switch case conditions for finding the type
    switch (type)
    {
    case 0: return "optimusprime";
    case 1: return "robocop";
    case 2: return "roomba";
    case 3: return "bulldozer";
    }

    return "unknown";

}

//  function that calculates the damage of robot
int OptimusPrime::getDamage() 
{
    //  Optimus prime robots inherited from humanic class
    int damage = Humanic::getDamage();

    //  Also they can hit strong attack with chance of 15
    if(rand() % 100 < 15)
    {
        damage *= 2;    //  Damage doubled if conditions ok
        cout << "Strong attack by " << getName() << "! Damage points doubled!" << endl;

    }

    return damage;

}


}