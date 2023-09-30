#include <iostream>
#include <vector>

using namespace std;

// Class Vector2D holds the coordinates of 2D vector

class Vector2D{
public:

    Vector2D(); //  Initial Constructor
    Vector2D(int a,int b);  //  Constructor

    void setVector(int x,int y);

    friend int operator*(const Vector2D& v1,const Vector2D& v2);    // operator overloading of *

    int getX() const;
    int getY() const;

private:

    int x;
    int y;

};

Vector2D::Vector2D(){

    x=0;
    y=0;

}

Vector2D::Vector2D(int a,int b){

    x=a;
    y=b;

}

void Vector2D::setVector(int a,int b){

    x=a;
    y=b;

}

int Vector2D::getX() const{

    return x;

}

int Vector2D::getY() const{

    return y;

}

int operator *(const Vector2D& v1,const Vector2D& v2){

    // variables for formula forx for x1*x2 and fory for y1*y2
    int forX;   
    int forY;

    int dotProduct; // variable for sum of forx and fory

    forX=v1.getX()*v2.getX();
    forY=v1.getY()*v2.getY();

    dotProduct=forX+forY;

    return dotProduct;

}


int main()
{

    Vector2D v1(1,2), v2(3,4), v3(5,6), v4(7,8);

    cout << "(" << v1.getX() << "," << v1.getY() << ") * (" << v2.getX()
         << "." << v2.getY() << ") = " << v1*v2 << endl;

    cout << "(" << v2.getX() << "," << v2.getY() << ") * (" << v3.getX()
         << "." << v3.getY() << ") = " << v2*v3 << endl;
         
    cout << "(" << v3.getX() << "," << v3.getY() << ") * (" << v4.getX()
         << "." << v4.getY() << ") = " << v3*v4 << endl;

    return 0;

}