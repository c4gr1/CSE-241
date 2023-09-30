#include <iostream>
#include <vector>

using namespace std;

int main(){

    //Vectors that holds the queue

    vector<int> queue {1,2,3,4,5,6};
    vector<int> queue2{1,2,3,4,5,6,7,8,9};

    int temp=0; // variable for current counting on queue

    int deleted;    // temp variable for deleted vector

    cout << "---- EXAMPLE 1 WITH 6 ELEMENTS ----" << endl << endl ;

    for(int i=0;i<queue.size();i++)  cout << queue[i] ; // printing the first queue

    cout << " Initial list of suitors, start counting from " << queue[0];

    cout << endl;

    // condition for finding the last element

    while(queue.size()>1){

        for(int i=0;i<2;i++){   //to continue to queue after 3 steps

           temp++;

           if(temp==queue.size()){  // for overlapping situation

                temp=0;

           }     

        }

        deleted=queue[temp];        

        queue.erase(queue.begin()+temp);    // deleting the unlucky person

        for(int i=0;i<queue.size();i++)  cout << queue[i] ;    

        cout << " suitor " << deleted << " was eliminated ! " << endl;

        if(temp==queue.size()){ // checking the condition after deleting person because vector size has changed

            temp=0;

        }

    }

    cout << "The lucky winner is " << queue[0] << endl;

//----------------------------------------------------------------------------------------    

    cout << "---- EXAMPLE 2 WITH 9 ELEMENTS ----" << endl << endl ;

    temp=0;

    for(int i=0;i<queue2.size();i++)  cout << queue2[i] ;

    cout << " Initial list of suitors, start counting from " << queue2[0];

    cout << endl;

    while(queue2.size()>1){

        for(int i=0;i<2;i++){

           temp++;

           if(temp==queue2.size()){

                temp=0;

           }     

        }

        deleted=queue2[temp];        

        queue2.erase(queue2.begin()+temp);

        for(int i=0;i<queue2.size();i++)  cout << queue2[i] ;    

        cout << " suitor " << deleted << " was eliminated ! " << endl;

        if(temp==queue2.size()){

            temp=0;

        }

    }

    cout << "The lucky winner is " << queue2[0] << endl;  
}