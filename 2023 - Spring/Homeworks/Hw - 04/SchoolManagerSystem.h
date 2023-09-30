#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

//  Dynamic school management system class
namespace PA4{

    class SchoolManagementSystem{
        private:

        Course *arrCourse;  //  holds courses
        Student *arrStudent;    // holds students
        int courseIndex;    // holds number of courses
        int studentIndex;   // holds number of students

        public:

        SchoolManagementSystem();   // constructor
        ~SchoolManagementSystem();  // destructor

        void Menu();    //  menu functions
        void subMenu(int choice);
        void subStudentMenu();
        void subCourseMenu();

        void addStudent();  //  add-delete functions for students
        void deleteStudent(string name,string surname,int id);

        void addCourse();   //  add-delete functions for courses
        void deleteCourse(string code,string name);

        void listStudents() const;  //  lists students and courses
        void listCourses() const;

        // helper functions for finding the given object
        int findStudentIndex(string name,string surname,int id);
        int findCourseIndex(string code,string name);

    };
}

#endif