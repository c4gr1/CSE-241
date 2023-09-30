#include <iostream>

using namespace std;

int main(){

    int numberOfDivisions=0;

    for(int i=3;i<=100;i++){    // outer loop for task (between 3 and 100)
         for(int j=1;j<=i;j++){ // inner loop for checking the number of divisions 
            
            if(i%j==0) numberOfDivisions++;
        
         }

        if(numberOfDivisions==2) cout << i << " " ;

        numberOfDivisions=0; 
    }

}