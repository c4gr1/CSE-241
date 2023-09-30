#include <iostream>
#include <cmath>

using namespace std;

// Class that holds the integer and finds its digits

class MyInteger{
public:

    //Constructors
    MyInteger();
    MyInteger(int number);

    //Getter-Setter
    int getNumber() const;
    void setNumber(int number);

    //Overloading of array operator
    int operator[](int digit);

private:

    int myInteger;

};

MyInteger::MyInteger(){

    myInteger=0;

}

MyInteger::MyInteger(int number){

    myInteger=number;

}

void MyInteger::setNumber(int number){

    myInteger=number;

}

int MyInteger::getNumber() const{

    return myInteger;

}

int MyInteger::operator[](int digit){

    int temp;

    //if index smaller than 0 it must be return -1

    if(digit<0){

        cout << "Illegal index value\n";
        return -1;

    }

    else{

        if(pow(10,digit)>myInteger) return -1;  // if index higger than number's digit count it must be return -1

        else{
        temp = (int) (myInteger/ pow(10,digit));
        return (temp%10);
        }
    }

}

int main(){


    MyInteger n1(4);
    MyInteger n2(41);
    MyInteger n3(418);
    MyInteger n4(4180);
    MyInteger n5(41800);

    cout << "number is : " << n1.getNumber() << endl;

    cout << n1[0] << endl;
    cout << n1[1] << endl;
    cout << n1[-1] << endl;

    cout << "number is : " << n2.getNumber() << endl;

    cout << n2[0] << " " << n2[1]  << endl;
    cout << n2[2] << endl;
    cout << n2[-1] << endl;

    cout << "number is : " << n3.getNumber() << endl;

    cout << n3[0] << " " << n3[1] << " " << n3[2] << endl;
    cout << n3[3] << endl;
    cout << n3[-1] << endl;

    cout << "number is : " << n4.getNumber() << endl;

    cout << n4[0] << " " << n4[1] << " " << n4[2] << " " << n4[3] << endl;
    cout << n4[4] << endl;
    cout << n4[-1] << endl;

    cout << "number is : " << n5.getNumber() << endl;

    cout << n5[0] << " " << n5[1] << " " << n5[2] << " " << n5[3] << " " << n5[4] << endl;
    cout << n5[5] << endl;
    cout << n5[-1] << endl;
    
}