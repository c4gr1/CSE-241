#include <iostream>

using namespace std;

class HotDogStand{
public:

    HotDogStand(int a,int b);   // Constructor that initializes the class

    static int totalSoldNumber; // Variable for finding the total number

    int getID();    // Getters for id and sold number
    int getSold();

    void setID(int a);  // Setters for id and sold number
    void setSold(int b);

    int JustSold(); // Increments the number of solds number

private:

    int standIdNumber;
    int soldNumber;



};

int HotDogStand::totalSoldNumber=0;

HotDogStand::HotDogStand(int a,int b){

    setID(a);
    setSold(b);

}

void HotDogStand::setID(int a){

    standIdNumber=a;

}

void HotDogStand::setSold(int b){

    soldNumber=b;

}

int HotDogStand::getID(){


    return standIdNumber;


}

int HotDogStand::getSold(){

    return soldNumber;

}

int HotDogStand::JustSold(){

    cout << "stand " << standIdNumber << " JUST SOLD HOTDOG " << endl;

    soldNumber=soldNumber+1;

    return soldNumber;


}




int main(){


    HotDogStand stand1(1,0);
    HotDogStand stand2(2,0);
    HotDogStand stand3(3,0);

    cout << "stand1 id number : " << stand1.getID() << " has sold " << stand1.getSold() << endl;
    cout << "stand2 id number : " << stand2.getID() << " has sold " << stand2.getSold() << endl;
    cout << "stand3 id number : " << stand3.getID() << " has sold " << stand3.getSold() << endl;

    stand1.JustSold();
    HotDogStand::totalSoldNumber++;
    cout << "stand1 id number : " << stand1.getID() << " has sold " << stand1.getSold() << endl;
    cout << "stand2 id number : " << stand2.getID() << " has sold " << stand2.getSold() << endl;
    cout << "stand3 id number : " << stand3.getID() << " has sold " << stand3.getSold() << endl;

    stand1.JustSold();
    HotDogStand::totalSoldNumber++;
    cout << "stand1 id number : " << stand1.getID() << " has sold " << stand1.getSold() << endl;
    cout << "stand2 id number : " << stand2.getID() << " has sold " << stand2.getSold() << endl;
    cout << "stand3 id number : " << stand3.getID() << " has sold " << stand3.getSold() << endl;

    stand1.JustSold();
    HotDogStand::totalSoldNumber++;
    cout << "stand1 id number : " << stand1.getID() << " has sold " << stand1.getSold() << endl;
    cout << "stand2 id number : " << stand2.getID() << " has sold " << stand2.getSold() << endl;
    cout << "stand3 id number : " << stand3.getID() << " has sold " << stand3.getSold() << endl;

    stand2.JustSold();
    HotDogStand::totalSoldNumber++;
    cout << "stand1 id number : " << stand1.getID() << " has sold " << stand1.getSold() << endl;
    cout << "stand2 id number : " << stand2.getID() << " has sold " << stand2.getSold() << endl;
    cout << "stand3 id number : " << stand3.getID() << " has sold " << stand3.getSold() << endl;

    stand2.JustSold();
    HotDogStand::totalSoldNumber++;
    cout << "stand1 id number : " << stand1.getID() << " has sold " << stand1.getSold() << endl;
    cout << "stand2 id number : " << stand2.getID() << " has sold " << stand2.getSold() << endl;
    cout << "stand3 id number : " << stand3.getID() << " has sold " << stand3.getSold() << endl;

    stand3.JustSold();
    HotDogStand::totalSoldNumber++;
    cout << "stand1 id number : " << stand1.getID() << " has sold " << stand1.getSold() << endl;
    cout << "stand2 id number : " << stand2.getID() << " has sold " << stand2.getSold() << endl;
    cout << "stand3 id number : " << stand3.getID() << " has sold " << stand3.getSold() << endl;
    
    cout << "Total hot dog sold by all stands -> " << HotDogStand::totalSoldNumber << endl;



}