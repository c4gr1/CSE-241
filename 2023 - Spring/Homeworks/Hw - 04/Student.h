#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

//  dynamic student class
namespace PA4{

    class Course;

    class Student{
        private:

        string name;
        string surName;
        int ID;
        Course *arrC;   //  holds student's courses
        int size;

        public:

        Student();  //  constuctor
        Student(string name,string surName,int ID); // constructor
        Student(const Student & other); // copy constructor
        ~Student(); // destructor

        //getters-setters
        void setName(string name); 
        string getName() const;

        void setSurName(string surName); 
        string getSurName() const;

        void setID(int id);
        int getID() const;

        int getSize() const;

        //  helpers functions
        void addCourseToStudent(string code,string courseName);
        void dropCourseFromStudent(string code,string courseName);

        //  operator overloading
        Student& operator =(const Student& other);
        friend ostream& operator<<(ostream & os,const Student& other);


    };
}

#endif