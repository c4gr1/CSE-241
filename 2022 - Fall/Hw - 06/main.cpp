#include <iostream>

#include "pfarray.h"
#include "pfarray.cpp"

#include <string>
#include <algorithm>

using namespace cagriYildiz;
using namespace std;

void print(int i){
    cout << i << endl;
}

int main(){
   
    PFArray<int> a(3);
    PFArray<string> b(4);

    cout << "\nORIGINAL PFARRAY FUNCTIONS TESTS \n";

    cout << "\nADD ELEMENT FUNCTION TEST 1\n";

    a.addElement(1);
    a.addElement(2);
    a.addElement(3);

    int index;
    int count = a.getNumberUsed();
    for(index = 0 ;index < count;index++)
        cout << a[index] << " ";
    cout << endl;

    cout << "\nGET CAPACITY FUNCTION TEST 1\n";

    cout << "Capacity of array is " << a.getCapacity() << endl;

    cout << "\nGET NUMBER USED FUNCTION TEST 1\n";

    cout << "Get number used is " << count << endl;

    cout << "\nFULL FUNCTION TEST 1\n" ;

    int boolx = a.full();

    cout << "Return value of FULL function is " << boolx << endl;
 
    cout << "\nADD ELEMENT FUNCTION TEST 2\n";

    b.addElement("GEBZE");
    b.addElement("TECHNICAL");
    b.addElement("UNIVERSITY");

    int index2;
    int count2 = b.getNumberUsed();
    for(index2 = 0 ;index2 < count2;index2++)
        cout << b[index2] << " ";
    cout << endl;

    cout << "\nGET CAPACITY FUNCTION TEST 2\n";

    cout << "Capacity of array is " << b.getCapacity() << endl;
    
    cout << "\nGET NUMBER USED FUNCTION TEST 2\n";

    cout << "Get number used is " << count2 << endl;

    cout << "\nFULL FUNCTION TEST 2\n" ;

    int boolx2 = b.full();

    cout << "Return value of FULL function is " << boolx2 << endl;

}
