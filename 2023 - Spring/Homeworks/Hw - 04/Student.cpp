#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

namespace PA4
{

//  constructor
Student::Student()
{
    name="";
    ID=0;
    arrC=nullptr;
    size=0;

}

//  constructor
Student::Student(string name,string surName,int ID)
{

    this-> name = name;
    this-> surName = surName;
    this-> ID   = ID;
    arrC = nullptr;
    size = 0;

}

//  destructor
Student::~Student()
{
    delete [] arrC;
}

//  setter for name
void Student::setName(string name)
{

    this->name = name;

}

//  getter for name
string Student::getName() const
{

    return name;

}

//  setter for surname
void Student::setSurName(string surName)
{

    this->surName = surName;

}

//  getter for surname
string Student::getSurName() const
{

    return surName;

}

//  setter for id
void Student::setID(int id)
{

    this->ID=id;

}

//  getter for id
int Student::getID() const
{

    return ID;

}

//  copy constructor
 Student::Student(const Student & other)
{

    if(other.size == 0)
    {
        name = "";
        surName = "";
        size = 0;
        arrC  = nullptr;

    }

    else{

        name = other.name;
        surName = other.surName;
        ID = other.ID;
        size = other.size;
        arrC  = new Course[size];

        for(int i=0;i<size;i++) arrC[i] = other.arrC[i]; 

    }

}   

//  assigment operator overloading
Student& Student::operator=(const Student & other)
{

    if(this == &other) return *this;

    delete [] arrC;

    name = other.name;
    surName = other.surName;
    ID = other.ID;
    size = other.size;
    arrC  = new Course[size];

    for(int i=0;i<size;i++) arrC[i] = other.arrC[i];

    return *this;
}    

//  cout overloading
ostream& operator<<(ostream & os,const Student& other)
{

    for(int i=0;i<other.size;i++) os << i+1 << " " << other.arrC[i].getCode() << " " << other.arrC[i].getName() << endl;

    return os;

}  

//  adds student to selected course
void Student::addCourseToStudent(string code,string courseName)
{

    Course* newArray = new Course[size+1];

    for(int i=0;i<size;i++) newArray[i] = arrC[i];

    newArray[size] = Course(code,courseName);

    delete [] arrC;

    arrC = newArray;

    size++;

}

//  drops course from student
void Student::dropCourseFromStudent(string code,string courseName)
{

    int index = -1;
    //  checking the given course and finding index
    for(int i=0;i<size;i++)
    {
        if(arrC[i].getCode() == code && arrC[i].getName() == courseName)
        {   
            index = i;
            break;
        }
    }

    if(index != -1)
    {

        Course* newArray = new Course[size-1];

        for(int i=0,j=0;i<size;i++){
            if(i!=index)
                newArray[j++]=arrC[i];
        }

        delete [] arrC;

        arrC = newArray;

        size--;

    }
}

//  getter for course size
int Student::getSize() const{
    return size;
}

}

