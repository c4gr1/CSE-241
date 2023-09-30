#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 20;

//Function that reverse the given array

void reverseArray(int arr[],int first,int last)
{
    while (first < last) // loop for compare and changing the last and first element until it arrives middle of array
    {
        int temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
        first++;
        last--;
    }
}

int main(){

    // variables for char number input and their integer sample

    char charFirstNumber[MAX_LENGTH+1];
    int intFirstNumber[MAX_LENGTH];

    char charSecondNumber[MAX_LENGTH+1];
    int intSecondNumber[MAX_LENGTH];

    // variable for summation of 2 numbers

    int sumOfFirstandSecond[MAX_LENGTH];

    // taking inputs
    
    cout << "enter first number : ";
    cin >> charFirstNumber ;
    cout << "enter second number : ";
    cin >> charSecondNumber;

    // finding the arrays lenght 

    int lenghtOfFirst = strlen(charFirstNumber);
    int lenghtOfSecond = strlen(charSecondNumber);
    int lenghtOfSum=0;

    // Changing the char array to int array the given numbers

    for(int i=0;i<lenghtOfFirst;i++){
        
        intFirstNumber[i]=charFirstNumber[lenghtOfFirst-1-i] - '0';

    }

    for(int i=0;i<lenghtOfSecond;i++){
        
        intSecondNumber[i]=charSecondNumber[lenghtOfSecond-1-i] - '0';

    }

    // variable for finding the digits number of summation and every digits carry

    int carry = 0;
    int i = 0;

    //we sum the 2 numbers until finds the less one

    while (i < lenghtOfFirst || i < lenghtOfSecond) {
        int sum = carry;
            if (i < lenghtOfFirst) {
             sum += intFirstNumber[i];
            } 
            if (i < lenghtOfSecond) {
            sum += intSecondNumber[i];
            }  
            sumOfFirstandSecond[i] = sum % 10; 
            carry = sum / 10;
            i++;
        } 

     if (carry) {   // if we have a carry we adds it
        sumOfFirstandSecond[i] = carry;
        lenghtOfSum = i + 1;    // carry means extra digits
        }  
    else {
        lenghtOfSum = i;
    }                             

    if(lenghtOfSum > MAX_LENGTH) cout << "integer overflow";    // error condition

    else{

        reverseArray(sumOfFirstandSecond,0,lenghtOfSum-1); // true position for array we reversed them before

        for(int i=0;i<lenghtOfSum;i++){

            cout << sumOfFirstandSecond[i];

        }
    }
    return 0;

}