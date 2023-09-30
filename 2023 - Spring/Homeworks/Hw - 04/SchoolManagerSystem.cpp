#include <iostream>
#include "SchoolManagerSystem.h"

using namespace std;

namespace PA4
{

//  constructor
SchoolManagementSystem::SchoolManagementSystem()
{

    arrCourse  = nullptr;
    arrStudent = nullptr;
    studentIndex = 0;
    courseIndex  = 0;

}

//  menu function
void SchoolManagementSystem::Menu()
{

    int menuChoice=0;

    do
    {

    cout << "Main_menu" << endl;
    cout << "0 exit" << endl;
    cout << "1 student" << endl;
    cout << "2 course" << endl;
    cout << "3 list_all_students" << endl;
    cout << "4 list_all_courses" << endl;

    cout << ">> ";
    cin  >> menuChoice;

    if(menuChoice == 1 || menuChoice == 2 || menuChoice == 3 || menuChoice == 4)
    subMenu(menuChoice);
    
    }while(menuChoice!=0);

}

//  subMenu for options
void SchoolManagementSystem::subMenu(int choice)
{

    int subMenuChoice = 0;

    do
    {
        
        switch(choice){

            case 1:

                cout << "0 up" << endl; 
                cout << "1 add_student" << endl;
                cout << "2 select_student" << endl;

                cout << ">> ";
                cin  >> subMenuChoice;

                if(subMenuChoice==1) addStudent();
                if(subMenuChoice==2) subStudentMenu();
                break;

            case 2:

                cout << "0 up" << endl; 
                cout << "1 add_course" << endl;
                cout << "2 select_course" << endl;    

                cout << ">> ";
                cin  >> subMenuChoice;

                if(subMenuChoice==1) addCourse();
                if(subMenuChoice==2) subCourseMenu();

                break;

            case 3:

                listStudents();
                break;                    

            case 4:

                listCourses();
                break;

            default:

                break;   
        
        }

    } while (subMenuChoice!=0);
}

// subMenu for option 1
void SchoolManagementSystem::subStudentMenu(){

    int choice = 0;
    string name,surname;
    int id;
    int add=0;
    int drop=0;
    int i=0;
 
    cout << ">> ";
    cin >> name >> surname >> id;

    do
    {

        cout << "0 up" << endl; 
        cout << "1 delete_student" << endl;
        cout << "2 add_selected_student_to_a_course" << endl;
        cout << "3 drop_selected_student_from_a_course" << endl;

        cout << ">> ";
        cin  >> choice;

        
        switch(choice){

            case 1:
                deleteStudent(name,surname,id);
                break;

            case 2:
                
                do{
                    cout << "0 Up" << endl;
                    listCourses();
                    cout << ">> ";
                    cin  >> add;
                    if(add!=0)
                    {   
                        i = findStudentIndex(name,surname,id);
                        arrStudent[i].addCourseToStudent(arrCourse[add-1].getCode(),arrCourse[add-1].getName());
                        arrCourse[add-1].addStudentToCourse(name,surname,id);
                    }
                }while(add!=0);

                break;

            case 3:

                do{
                    cout << "0 Up" << endl;
                    i = findStudentIndex(name,surname,id);
                    cout << arrStudent[i];
                    cout << ">> ";
                    cin  >> drop;
                    if(drop!=0)
                    {   
                        arrStudent[i].dropCourseFromStudent(arrCourse[drop-1].getCode(),arrCourse[drop-1].getName());
                        arrCourse[drop-1].dropStudentFromCourse(name,surname,id);
                    }

                }while(drop!=0);

                break;                    

            default:

                break;   
        
        }

    } while (choice!=0);


}

//  subMenu for option 2
void SchoolManagementSystem::subCourseMenu(){

    int choice = 0;
    string code,name;
    int i =0;

    cout << ">> ";
    cin >> code >> name;

    do
    {

        cout << "0 up" << endl; 
        cout << "1 delete_course" << endl;
        cout << "2 list_students_registered_to_the_selected_course" << endl;

        cout << ">> ";
        cin  >> choice;

        
        switch(choice){

            case 1:
                deleteCourse(code,name);
                break;

            case 2:
                i = findCourseIndex(code,name);
                cout << arrCourse[i];
                break;                  

            default:

                break;   
        
        }

    } while (choice!=0);


}

//  adds Student dynamically
void SchoolManagementSystem::addStudent()
{

    string name;
    string surName;
    int id;

    cout << ">> ";
    cin >> name >> surName >> id;
    
    Student* newArray = new Student[studentIndex+1];

    for(int i=0;i<studentIndex;i++) newArray[i] =  arrStudent[i];

    newArray[studentIndex] = Student(name,surName,id);

    delete [] arrStudent;

    arrStudent = newArray;

    studentIndex++;

}

//  deletes Student dynamically
void SchoolManagementSystem::deleteStudent(string name,string surname,int id){

    int index = -1;

    //  checking the given students and finding its index
    for(int i=0;i<studentIndex;i++)
    {
        if(arrStudent[i].getName() == name && arrStudent[i].getSurName() == surname && arrStudent[i].getID() == id)
        {
            index = i;
            break;
        }
    }

    //  creting new array before deleting
    if(index != -1)
    {

        Student* newArray = new Student[studentIndex-1];

        for(int i=0,j=0;i<studentIndex;i++){
            if(i!=index)   
                newArray[j++]=arrStudent[i];
        }

    delete [] arrStudent;

    arrStudent = newArray;

    studentIndex--;

    }
}

//  adds Course dynamically
void SchoolManagementSystem::addCourse()
{

    string code;
    string name;

    cout << ">> ";
    cin >> code >> name;

    Course* newArray = new Course[courseIndex+1];

    for(int i=0;i<courseIndex;i++) newArray[i]=arrCourse[i];

    newArray[courseIndex] = Course(code,name);

    delete [] arrCourse;

    arrCourse = newArray;

    courseIndex++;

}

//  deletes Courses dynamically
void SchoolManagementSystem::deleteCourse(string code,string name)
{
    int index = -1;

    //  checking the given courses and finding index
    for(int i=0;i<courseIndex;i++)
    {
        if(arrCourse[i].getCode() == code && arrCourse[i].getName() == name)
        {
            index = i;
            break;
        }
    }

    if(index != -1)
    {

        Course* newArray = new Course[courseIndex-1];

        for(int i=0,j=0;i<courseIndex;i++){
            if(i!=index)   
                newArray[j++]=arrCourse[i];
        }

    delete [] arrCourse;

    arrCourse = newArray;

    courseIndex--;

    }
}

//  lists all students
void SchoolManagementSystem::listStudents() const
{

    for(int i=0;i<studentIndex;i++) cout << i+1 << " " << arrStudent[i].getName() << " " << arrStudent[i].getSurName() << " " << arrStudent[i].getID() << endl;

}

//  list all courses
void SchoolManagementSystem::listCourses() const
{

    for(int i=0;i<courseIndex;i++) cout << i+1 << " " << arrCourse[i].getCode() << " " << arrCourse[i].getName() << endl;

}

// destructor
SchoolManagementSystem::~SchoolManagementSystem()
{
    delete [] arrStudent;
    delete [] arrCourse;

}

//  finds the index of given student
int SchoolManagementSystem::findStudentIndex(string name,string surname,int id){

    int index = 0;

    for(int i=0;i<studentIndex;i++)
    {

        if(arrStudent[i].getName()==name && arrStudent[i].getSurName()==surname && arrStudent[i].getID()==id)
        {
            index = i;
            break;
        }

    }

    return index;

}

//  finds the index of given course
int SchoolManagementSystem::findCourseIndex(string code,string name){

    int index = 0;

    for(int i=0;i<courseIndex;i++)
    {

        if(arrCourse[i].getCode()==code && arrCourse[i].getName()==name)
        {
            index = i;
            break;
        }

    }

    return index;

}

}
