#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int humanTurn(int humanTotalScore); // Function that returns points for human
int computerTurn(int computerTotalScore); // Function that returns points for computer

int main(){

    cout << "Welcome to the dice game " << endl;

    srand(time(NULL));

    int humanTotalScore=0;  // Initial points for players
    int computerTotalScore=0;

    int numberOfTurn=1; // Variable for players turn



    while(humanTotalScore<100 || computerTotalScore<100 ){  // Conditions for winning the game

        if(numberOfTurn%2==1){  // Human's Turn
            cout << "Your current points is " << humanTotalScore << endl;
            humanTotalScore=humanTotalScore+humanTurn(humanTotalScore);
                if(humanTotalScore >=100){ // Human's winning condition
                cout << "You WON your points "<< humanTotalScore << endl;
                break;
                }
        }

        else if(numberOfTurn%2==0){ // Computer's Turn
            cout << "Computer current points is " << computerTotalScore << endl;
            computerTotalScore=computerTotalScore+computerTurn(computerTotalScore);
                if(computerTotalScore >=100){ // Computer's winning condition  
                cout << "Computer WON computer points " << computerTotalScore << endl;
                break;
                }
        }
        
        numberOfTurn++;

    }

}

int humanTurn(int humanTotalScore){

    char decision;
    int dice;
    int turnTotal=0;    // total points in that turn

    do{

        cout << "do you want to input to roll again (press r) or hold (press h)" << endl;

        cin >> decision;

        if(decision=='r'){ 

            dice= rand()%6+1;   // dice points

            if(dice==1){    // Lose condition for turn

                cout << "You took 0 points " << endl;
                return 0;
            }

            else{

                turnTotal = turnTotal + dice;
                


            }
        }

    }while(decision!='h');  // condition for holding points

    cout << "You took " << turnTotal << " points " << endl;

    return turnTotal;

}


int computerTurn(int computerTotalScore){

    int dice;
    int tempScore=0;    // variable that checks computer's points
    int turnTotal=0;

    while(tempScore<20){

        dice= rand()%6+1;

        if(dice==1){

            cout << "Computer took 0 points " << endl;
            return 0;

        }
        else{

            turnTotal = turnTotal + dice;
            tempScore = tempScore + dice;

        }

    }

    cout << "Computer took " << turnTotal << " points " << endl;

    return turnTotal;

}
