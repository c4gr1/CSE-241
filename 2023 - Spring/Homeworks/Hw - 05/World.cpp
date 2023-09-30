#include <iostream>
#include <string>
#include "World.h"

using namespace std;

//  .cpp file that contains the implementation of world class functions 

namespace PA5
{

//  default constructor that creates the grid with null elements
World::World()
{
    int i,j;
    for(i=0;i<WORLDSIZE;i++)
    {
        for(j=0;j<WORLDSIZE;j++)
        {

            grid[i][j] = NULL;  //  filling the grid with null elements

        }
    }
}

//  destructor for world class
World::~World()
{
    int i,j;
     
    for(i=0;i<WORLDSIZE;i++)
    {
        for(j=0;j<WORLDSIZE;j++)
        {

            if(grid[i][j]!= NULL) delete grid[i][j];    //  deleting the grid elements

        }
    }   
}

//  function that returns the information in given coordinates
Robot * World::getAt(int x,int y){
    //  checking the coordinates
    if((x>=0)&&(x<WORLDSIZE)&&(y>=0)&&(y<WORLDSIZE)){
        return grid[x][y];
    }
    return NULL;
}

//  function that sets the given information to given coordinates
void World::setAt(int x,int y,Robot *rbt){
    //  checking coordinates
    if((x>=0)&&(x<WORLDSIZE)&&(y>=0)&&(y<WORLDSIZE)){
        grid[x][y]=rbt;
    }
}

//  function that prints the grid
void World::Display(){
    int i,j;

    //  printing the grid with the given conditions

    for(i=0;i<WORLDSIZE;i++){

        for(j=0;j<WORLDSIZE;j++)
        {
            if(grid[i][j]==NULL)    
                cout<<".";
            else if(grid[i][j]->getType()=="optimusprime")
                cout<<"O";
            else if(grid[i][j]->getType()=="robocop")
                cout<<"R";
            else if(grid[i][j]->getType()=="roomba")
                cout<<"M";
            else 
                cout<<"B";                                
       
        }
        cout<<endl;
    }
}

//  funtion that simulates the robots and results the war results
//  -1 for nothing
//  0 for if defenders is winner
//  1 for if attacker is winner
int World::SimulateOneStep(int x,int y)
{

    int i,j;    //  variables for loops

    //  checking given grid
    if(grid[x][y]==NULL) 
    {  
    return -1;
    }
    else 
    {
        //  chechking the grids situation
        //  if robots at end of row we have to check that condition
        if(y+1>=WORLDSIZE)
        {
            x=x+1;
            y=-1;
            if(x>=WORLDSIZE){x=0;y=-1;}
            
        }

    //  loop for fight in the given rows robots
     for(i=x;i<=x;i++)
        for(j=y+1;j<WORLDSIZE;j++)
        {
            //  condition for finding the defender
            if(grid[i][j]!=NULL)
            {
                //  attacker and defenders features

                int atackerHitpoints = grid[x][y]->getHitPoints();
                int defenderHitpoints = grid[i][j]->getHitPoints();

                // loop for one of the robot is dead
                while(atackerHitpoints>0 && defenderHitpoints>0)
                {
                    //  attacker hits the defenders
                    int dmg = grid[x][y]->getDamage();

                    //  fight information
                    cout << grid[x][y]->getName() << "(" << grid[x][y]->getHitPoints() << ")"
                         << " hits "                   
                         << grid[i][j]->getName() << "(" << grid[i][j]->getHitPoints() << ")"
                         << " with " << dmg << endl;

                    defenderHitpoints=defenderHitpoints-dmg;    //decreasing the robots hitpoints   
                    //  grid[i][j]->setHitPoints(defenderHitpoints);    if you want to upgrade the hitpoints of robots
                    //  current sitiation of defender
                    cout << "The new hitpoints of "<< grid[i][j]->getName() << " is " << defenderHitpoints << endl;

                    //  checking the defender is dead or not
                    if(defenderHitpoints<0) 
                    {

                    cout << grid[i][j]->getName() << " is DEAD !" << endl;    
    
                    //  if defender is dead,attacker swaps with it and defender deleting

                    grid[i][j]=NULL;
                    
                    grid[i][j]=grid[x][y];

                    grid[x][y]=NULL;
                    
                    return 1;
                    
                    }

                    //  defender attack simulation

                    int dmg2 = grid[i][j]->getDamage();

                    //  fight information
                    cout << grid[i][j]->getName() << "(" << grid[i][j]->getHitPoints() << ")"
                         << " hits "                   
                         << grid[x][y]->getName() << "(" << grid[x][y]->getHitPoints() << ")"
                         << " with " << dmg2 << endl;

                    atackerHitpoints=atackerHitpoints-dmg2; //decreasing the robots hitpoints
                    //  grid[x][y]->setHitPoints(atackerHitpoints); if you want to upgrade the hitpoints of robots
                    //  current sitiation of attacker
                    cout << "The new hitpoints of "<< grid[x][y]->getName() << " is " << atackerHitpoints << endl;

                    //  checking the attacker is dead or not
                    if(atackerHitpoints<0) 
                    {

                    //  if attacker is dead,attacker deletes

                    cout << grid[x][y]->getName() << " is DEAD !" << endl; 
                    
                    grid[x][y]=NULL;
                                  
                    return 0;

                    }

                }

            }

        }
    //  loop for fight in the another rows robots
    for(i=x+1;i<WORLDSIZE;i++)
        for(j=0;j<WORLDSIZE;j++)
        {
            //  condition for finding the defender
            if(grid[i][j]!=NULL)
            {
                //  attacker and defenders features

                int atackerHitpoints = grid[x][y]->getHitPoints();
                int defenderHitpoints = grid[i][j]->getHitPoints();

                // loop for one of the robot is dead
                while(atackerHitpoints>0 && defenderHitpoints>0)
                {
                    //  attacker hits the defenders
                    int dmg = grid[x][y]->getDamage();

                    //  fight information
                    cout << grid[x][y]->getName() << "(" << grid[x][y]->getHitPoints() << ")"
                         << " hits "                   
                         << grid[i][j]->getName() << "(" << grid[i][j]->getHitPoints() << ")"
                         << " with " << dmg << endl;

                    defenderHitpoints=defenderHitpoints-dmg;    //decreasing the robots hitpoints
                    //  grid[i][j]->setHitPoints(defenderHitpoints);    if you want to upgrade the hitpoints of robots
                    //  current sitiation of defender
                    cout << "The new hitpoints of "<< grid[i][j]->getName() << " is " << defenderHitpoints << endl;

                    //  checking the defender is dead or not
                    if(defenderHitpoints<0) 
                    {

                    //  if defender is dead,attacker swaps with it and defender deleting

                    cout << grid[i][j]->getName() << " is DEAD !" << endl;    
    
                    grid[i][j]=NULL;
                    
                    grid[i][j]=grid[x][y];

                    grid[x][y]=NULL;
                    
                    return 1;
                    
                    }

                    //  defender attack simulation

                    int dmg2 = grid[i][j]->getDamage();

                    cout << grid[i][j]->getName() << "(" << grid[i][j]->getHitPoints() << ")"
                         << " hits "                   
                         << grid[x][y]->getName() << "(" << grid[x][y]->getHitPoints() << ")"
                         << " with " << dmg2 << endl;

                    atackerHitpoints=atackerHitpoints-dmg2; //decreasing the robots hitpoints
                    //  grid[x][y]->setHitPoints(atackerHitpoints); if you want to upgrade the hitpoints of robots
                    //  current sitiation of attacker   
                    cout << "The new hitpoints of "<< grid[x][y]->getName() << " is " << atackerHitpoints << endl;

                    //  checking the attacker is dead or not
                    if(atackerHitpoints<0) 
                    {

                    //  if attacker is dead,attacker deletes

                    cout << grid[x][y]->getName() << " is DEAD !" << endl; 
                    
                    grid[x][y]=NULL;
                                  
                    return 0;

                    }

                }

            }

        }

        return -1;

    }
}

}