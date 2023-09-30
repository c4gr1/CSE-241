#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include "World.h"

using namespace std;

//  .h library for robot class which is base class for all robot type

namespace PA5
{

    class World;    //  defining world class for pretending the compiler errors

    class Robot
    {
        friend class World; //  world class using for grid
        public:

        Robot();    //  default constructor
        Robot(int newType,int newStrenght,int newHit,string name);  // initializer constructor
        ~Robot();   //  destructor

        virtual string getType()=0; //  virtual functions those are going to be implement in the derived class
        virtual int getDamage()=0;
        
        void setRobotType(int type);    //  setters-getters for member variables
        int getRobotType() const;
        void setStrenght(int strenght);
        int getStrenght() const;
        void setHitPoints(int hitPoints);
        int getHitPoints() const;
        void setName(string name);
        string getName() const;

        protected:
        int type;   //  holds robot type
        int strenght;   //  holds robot strenght
        int hitPoints;  //  holds robot hitpoints
        string name;     // holds robot name
    };
}
#endif