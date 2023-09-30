#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL));

    //Hit changes for players

    int aaron=3;
    int bob=2;
    int charlie=1;
    int counter=0;

    //Winning times of players

    int aaronWins=0;
    int bobWins=0;
    int charlieWins=0;

    //if random number 1 it means player hits the other player other number means player misses shot

    int changeFactorAaron;
    int changeFactorBob;
    int changeFactorCharlie;

    //Percentage of players winning after 10.000 similulation

    double aaronChanges;
    double bobChanges;
    double charlieChanges;

    //While loop for 10.000 times similation

    while(counter!=10000){

        //Changes factor for player if number 1 it means player hits

        changeFactorAaron=rand()%3+1;
        changeFactorBob=rand()%2+1;
        changeFactorCharlie=rand()%1+1;

        //Possible variations of player according to changeFactor

        if(changeFactorAaron==1 && changeFactorCharlie==1){

            charlieWins++;

        }

        else if(changeFactorAaron!=1 && changeFactorBob==1){

            changeFactorAaron=rand()%3+1;
            changeFactorBob=rand()%2+1;

            if(changeFactorAaron==1) aaronWins++;
            else if(changeFactorAaron!=1 && changeFactorBob==1) bobWins++;
            else if(changeFactorAaron!=1 && changeFactorBob!=1){
                
                changeFactorAaron=rand()%3+1;
                changeFactorBob=rand()%2+1;

                if(changeFactorAaron==1) aaronWins++;
                else if(changeFactorAaron!=1 && changeFactorBob==1) bobWins++;

            }

        }    

        else if (changeFactorAaron!=1 && changeFactorBob!=1){

            charlieWins++;

        } 

        counter++; 

    }

    //Players percentage

    aaronChanges=(static_cast<double>(aaronWins)*100)/10000;
    bobChanges=(static_cast<double>(bobWins)*100)/10000;
    charlieChanges=(static_cast<double>(charlieWins)*100)/10000;

    cout << "Aaron won " << aaronWins << "/10000 duels or " << aaronChanges << "%" << endl;
    cout << "Bob won " << bobWins << "/10000 duels or " << bobChanges << "%"  << endl;
    cout << "Charlie won " << charlieWins << "/10000 duels or " << charlieChanges << "%"  << endl;

    return 0;
    
}
