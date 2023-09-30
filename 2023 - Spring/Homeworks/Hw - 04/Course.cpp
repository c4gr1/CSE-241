#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"

using namespace std;

namespace PA4
{

//  constructor
Course::Course()
{
    code = "";
    name = "";
    arrS  = nullptr;
    size = 0;
}

//  constructor
Course::Course(string code,string name)
{

    this-> code = code;
    this-> name = name;
    arrS = nullptr;
    size = 0;

}

//  destructor
Course::~Course()
{
    delete [] arrS;
}

//  setter for name
void Course::setName(string name)
{
    this->name = name;
}

//  getter for name
string Course::getName() const
{
    return name;
}

//  setter for code
void Course::setCode(string code)
{
    this->code = code;
}

//  getter for code
string Course::getCode() const
{
    return code;
}

//  copy constructor
Course::Course(const Course & other)
{

    if(other.size == 0)
    {
        name = "";
        code = "";
        size = 0;
        arrS  = nullptr;

    } 

    else{

        code = other.code;
        name = other.name;
        size = other.size;
        arrS  = new Student[size];

        for(int i=0;i<size;i++) arrS[i] = other.arrS[i]; 

    }

}

//  assigment operator overloading
Course& Course::operator=(const Course & other)
{

    if(this == &other) return *this;

    delete [] arrS;
 
    code = other.code;
    name = other.name;
    size = other.size;
    arrS  = new Student[size];

    for(int i=0;i<size;i++) arrS[i] = other.arrS[i];

    return *this;

}

//  cout overloading
ostream& operator<<(ostream & os,const Course& other)
{

    for(int i=0;i<other.size;i++) os << i+1 << " " << other.arrS[i].getName() << " " << other.arrS[i].getSurName() << " " << other.arrS[i].getID() << endl;

    return os;

}

//  adds student to selected course
void Course::addStudentToCourse(string name,string surname,int id)
{

    Student* newArray = new Student[size+1];

    for(int i=0;i<size;i++) newArray[i] = arrS[i];

    newArray[size] = Student(name,surname,id);

    delete [] arrS;

    arrS = newArray;

    size++;

}

//  drops course from student
void Course::dropStudentFromCourse(string name,string surname,int id)
{

    int index = -1;

    for(int i=0;i<size;i++)
    {
        if(arrS[i].getName() == name && arrS[i].getSurName() == surname && arrS[i].getID() == id)
        {   
            index = i;
            break;
        }
    }

    if(index != -1)
    {

        Student* newArray = new Student[size-1];

        for(int i=0,j=0;i<size;i++){
            if(i!=index)
                newArray[j++]=arrS[i];
        }

        delete [] arrS;

        arrS = newArray;

        size--;

    }
}

//  getter for student size
int Course::getSize() const{
    return size;
}
}