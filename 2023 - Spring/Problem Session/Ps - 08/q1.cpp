#include <iostream>
#include <vector>
#include <string>
#include "set.h"
#include "set.cpp"

using namespace std;

int main()
{

    Set<int> s1;
    Set<string> s2;
    int* intArray = NULL;
    string* stringArray = NULL;

    int i;

    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.add(4);
    s1.add(5);

    intArray = s1.getArray();

    cout << "Set one has " << s1.getSize() << " items. Here they are: " << endl;
    for(i=0;i<s1.getSize();i++)
    {
        cout << intArray[i] << endl;
    }
    if(intArray != NULL) delete[] intArray; 

    s2.add("cagri");
    s2.add("yildiz");
    s2.add("gebze");
    s2.add("technical");
    s2.add("university");

    stringArray = s2.getArray();

    cout << "Set two has " << s2.getSize() << " items. Here they are: " << endl;
    for(i=0;i<s2.getSize();i++)
    {
        cout << stringArray[i] << endl;
    }
    if(stringArray != NULL) delete[] stringArray;

    return 0;    

}