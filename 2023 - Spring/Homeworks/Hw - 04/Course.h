#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

// dynamic course class
namespace PA4{

    class Student;

    class Course{
        private:

        string name;
        string code;
        Student *arrS;  // holds courses's students
        int size;

        public:

        Course();   // constructor
        Course(string name,string code);    // constructor   
        Course(const Course & other);   // copy constructor
        ~Course();  // destructor

        //  setters-getters
        void setName(string name); 
        string getName() const;

        void setCode(string code);
        string getCode() const;

        int getSize() const;

        //  helper functions
        void addStudentToCourse(string name,string surname,int id);
        void dropStudentFromCourse(string name,string surname,int id);

        //  operator overloading
        Course & operator=(const Course & other);
        friend ostream& operator<<(ostream & os,const Course& other);

    };
}

#endif