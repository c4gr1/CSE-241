
//  1901042630 - Cagri Yildiz - PA1

#include <iostream>
#include <stdlib.h> //  Library for atoi() and rand() functions
#include <time.h>   //  Library for creating random number 
#include <math.h>   //  Library for pow() function
#include <ctype.h>  //  Library for isdigit() function

//  Function that creates random number and random number array for comparing
//  It takes array and returns a value that contains error code or true code
void SecretNumberCreator(int secretNumberArr[],int numberOfDigits);

//  Function that takes user input and makes it array to compare with secret number
//  It takes user input and array for user input and checks the input and returns the code for printing results or error              
int UserInputCreator(int userInput,int userInputArr[],int numberOfDigits);

//  Function that tries to find matches numbers in secret number
//  It takes user and random number arrays and compares them one by one and returns the number of matching digits      
int FirstCount(int userInputArr[],int secretNumberArr[],int numberOfDigits);

//  Function that tries to find unmatched numbers but exists in numbers
//  It takes user and random number arrays and checks the digits which is exist but  in different place and returns the number of this numbers    
int SecondCount(int userInputArr[],int secretNumberArr[],int numberOfDigits);   

using namespace std;

//  Main function for game mastermind
//  It takes 2 arguments which are argc and argv array
//  argc : holds the number of command line inputs
//  argv : holds the command line inputs  
int main(int argc,char **argv){

    //  This function for creating different random numbers in every program call
    srand(time(NULL));

    //  gameCounter holds the number of users guess
    int gameCounter=0;

    //  secretNumberArr will used for secret number's digits comparing 
    int secretNumberArr[10]={0};

    //  userInputArr will used for user's number digits comparing
    //  userInputCharArr will used for controlling the input if it is digit or not
    int userInputArr[10]={0};
    char userInputCharArr[10];

    //  userInput holds the number from atoi() function which holds in userInputCharArr
    //  breaker gonna delete
    int userInput=0;
    int breakerInput=0;

    //  firstCount holds the number of matching digits
    //  secondCount hold the number of existing number but in different places
    int firstCount=0;
    int secondCount=0;
    
    //  if-else blocks for 2 types of game
    //  The game can start with -r or -u command 
    if(argv[1][1]=='r'){
        
        //  argvChar for checking the number of digits
        char argvChar;

        //  assigning the command line input to argvChar 
        argvChar=argv[2][0];

        //  converting to int argvChar variable
        int argvInt = argvChar-'0';

        //  error control if variable less  or  equal than 0 
        if(argvInt<=0){

            cout << "E0" << endl;
            exit(0);

        } 

        SecretNumberCreator(secretNumberArr,argvInt);

        //  do-while loop for user guess
        do{

            //  taking the user's input
            cin >> userInputCharArr;

            // i for finding the number of digits of users input
            int i=0;

            //  while loop for finding the number of digits and error checking if input contains non-digit or starting with 0
            while(userInputCharArr[i]!='\0'){

                if(!isdigit(userInputCharArr[i])){

                    cout << "E2" << endl;
                    exit(0);            
                }

                if(userInputCharArr[0]=='0'){
                    cout << "E1" << endl;
                    exit(0);

                }

                i++;

            }

            // converting the user's input to int
            userInput=atoi(userInputCharArr);

            //  if function returns 0 it means input has more or less digits or starting with 0
            if(UserInputCreator(userInput,userInputArr,argvInt)==0){               
                cout << "E1" << endl;
                exit(0);
            }

            // if function return 2 it means input contains same digits
            else if(UserInputCreator(userInput,userInputArr,argvInt)==2){
                cout << "E0" << endl;
                exit(0);

            }

            //  if everything ok else condition will starts
            else{

                //  function returns the number of matching digits
                firstCount = FirstCount(userInputArr,secretNumberArr,argvInt) ;
                //  function return the number of existing number but in different place
                secondCount = SecondCount(userInputArr,secretNumberArr,argvInt) ;

                cout << firstCount << " "<< secondCount << endl;

                gameCounter++;

                //  conditions for terminating the game
                if(gameCounter>=100) cout << "FAILED" << endl;
                if(firstCount==argvInt) cout << "FOUND " << gameCounter << endl; 
            } 

        }while((gameCounter!=100)&&(firstCount!=argvInt));

    }

    //  if command line argument is u it has a secret number itself
    else if(argv[1][1]=='u'){

        //  digitCounter for number of digits
        //  digitCheck for checking the values if they are digits or not
        int digitsCounter=0;
        bool digitCheck=false;

        //  while loop for error checking and finding the number of digits
        while(argv[2][digitsCounter]!='\0'){
            
            //  if command line input contains non-digit value program terminates
            if(!isdigit(argv[2][digitsCounter])){

                    cout << "E2" << endl;
                    exit(0);            
            }

            // if command line input starts with 0 program terminates
            if(argv[2][digitsCounter]=='0'){
                    cout << "E1" << endl;
                    exit(0);

            }

            // argvChar holds command line inputs elements 
            char argvChar;

            argvChar=argv[2][digitsCounter];

            //  converting the char value to int value
            int argvInt = argvChar-'0';

            //  assinging the array
            secretNumberArr[digitsCounter]=argvInt;

            digitsCounter++;

        }

        //  for loop for controlling the command line input if it has same digits
        for(int i=0;i<digitsCounter;i++)
            for(int j=i+1;j<digitsCounter;j++){

                    if(secretNumberArr[i]==secretNumberArr[j])  { 
                        digitCheck=true;               
            }
        }

        //  if command line input has same digits program terminates
        if(digitCheck==true){
            
            cout << "E0" << endl;
            exit(0);

        }

        //  do-while loop for taking the user input and checking it and comparing with command line input
        do{

            cin >> userInputCharArr;

            // i holds the number of digits
            int i=0;

            // while loop for error checking
            while(userInputCharArr[i]!='\0'){
                
                //  if user input contains non-digit value program terminates
                if(!isdigit(userInputCharArr[i])){

                    cout << "E2" << endl;
                    exit(0);            
                }

                //  if user input start with 0 program terminates
                if(userInputCharArr[0]=='0'){

                    cout << "E1" << endl;
                    exit(0);

                }

                i++;

            }

            //  converting char input to int input
            userInput=atoi(userInputCharArr);            

            //  if function returns 0 user input has different size with command line input
            if(UserInputCreator(userInput,userInputArr,digitsCounter)==0)
            {   

                cout << "E1" << endl;
                exit(0);
            }

            //  if function return 0 user input has same values
            else if(UserInputCreator(userInput,userInputArr,digitsCounter)==2){
                cout << "E0" << endl;
                exit(0);

            }

            // if everything ok program continues
            else{

                //  holds the number of matching digits
                firstCount = FirstCount(userInputArr,secretNumberArr,digitsCounter) ;

                // hold the ezisting number
                secondCount = SecondCount(userInputArr,secretNumberArr,digitsCounter) ;

                cout << firstCount << " "<< secondCount << endl;

                gameCounter++;

                //  conditions for game end
                if(gameCounter>=100) cout << "FAILED" << endl;
                if(firstCount==digitsCounter) cout << "FOUND " << gameCounter << endl; 
            }

        }while((gameCounter!=100)&&(firstCount!=digitsCounter));        

    }

    else cout << "E0" <<endl; 

    return 0;

}

void SecretNumberCreator(int secretNumberArr[],int numberOfDigits){

    //  this variable will be used for secret number
    int secretNumber=0;

    //  this variable will be used for checking same elements
    bool isSame;

    //  for loop for creating random number which all digits are different
    for(int i=0;i<numberOfDigits;i++){

        do{

            isSame=false;

            //  condition for starting digits of number can not be 0
            if(i==0) secretNumberArr[i]=rand()%9+1;
            
            else{

                secretNumberArr[i]=rand()%10;

                for(int j=0;j<i;j++){

                    if(secretNumberArr[i]==secretNumberArr[j])  { 
                        isSame=true;
                        break;
                    }
                }

            }

        }while(isSame==true);

    }
}

//  This function returns the number which decides the error type
//  return 0 means user input digits and command line digits are not matching
//  return 1 means successful process
//  return 2 means input contains same value
int UserInputCreator(int userInput,int userInputArr[],int numberOfDigits){

    //  digits hold the number of digits of user input to compare with command line input
    int digit=0;

    //  isSame for checking the same values
    bool isSame=false;

    //  temporary variable for user input to find the number of digits
    int tempUserInput=userInput;

    //  while loop for finding number of digits
    while(tempUserInput!=0){

        tempUserInput=tempUserInput/10;

        digit++;

    }

    //  if number of digits doesnt matches with command line input program terminates after printing the error code
    if(digit!=numberOfDigits) return 0;

    //  else block for converting the user input to array elements
    else{

        for(int i=0;i<numberOfDigits;i++){

            int denominator=pow(10,numberOfDigits-i-1);

            userInputArr[i]=userInput/denominator;

            userInput=userInput%denominator;
            
        }

        //  user input can not be 0
        if(userInputArr[0]==0) return 0;

        //  checking the same values
        else {

            for(int i=0;i<numberOfDigits;i++)
                for(int j=i+1;j<numberOfDigits;j++){

                        if(userInputArr[i]==userInputArr[j])  { 
                            isSame=true;               
                }
            }

            if(isSame==true) return 2;  

            else return 1;
        }

    }   
     
}

//  Function that finds the number of mathing elements in given arrays  
int FirstCount(int userInputArr[],int secretNumberArr[],int numberOfDigits){

    int found=0;

    for(int i=0;i<numberOfDigits;i++) if(secretNumberArr[i]==userInputArr[i]) found++;

    return found;

}

//  Function that find the number of existing elements in arrays
int SecondCount(int userInputArr[],int secretNumberArr[],int numberOfDigits){

    int exist=0;

    for(int i=0;i<numberOfDigits;i++){
        for(int j=0;j<numberOfDigits;j++){

            if((userInputArr[i]!=secretNumberArr[i]) && (userInputArr[i]==secretNumberArr[j])) exist++; 
               
        }
    }

    return exist;

}
