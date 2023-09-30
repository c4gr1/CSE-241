#include <iostream>
#include <string>

using namespace std;

//  Student class which includes student name-number of class -classes name

class Student{
public:

    //  Default Constructor
    Student() : name("No Name"),numClasses(0),classList(nullptr){}

    //  Intialization Constructor
    Student(string Name,int NumClasses) : name(Name),numClasses(NumClasses),classList(new string[NumClasses]){}

    //  Setters for private class members

    void setName(string Name){name=Name;}
    void setNumClasses(int Num){

        delete[] classList;
        numClasses=Num;
        classList = new string[numClasses]; 

    }

    //  Copy Constructor
    Student(const Student& other){

        name=other.name;
        numClasses=other.numClasses;
        classList = new string[numClasses];

        for(int i=0;i<numClasses;i++)   classList[i]=other.classList[i];  


    }

    //  Assigment Operator for big three
    Student& operator=(const Student& other){

        if(this != &other){

            delete[] classList;
            name= other.name;
            numClasses=other.numClasses;

            classList = new string[numClasses];

            for(int i=0;i<numClasses;i++)   classList[i]=other.classList[i];

        }


    return *this;

    }

    //  Function that resets the students class

    void ResetClasses(){

        numClasses = 0;

        delete [] classList;

        classList = nullptr ;

    }

    //  Function for taking data

    void InputData(){

        cout << "Student Name : ";
        getline(cin,name);

        cout << "number of class : ";
        cin >> numClasses;
        cin.ignore();

        classList = new string[numClasses];

        for(int i=0;i<numClasses;i++){
            cout << "class " << i + 1 << ":";
            getline(cin,classList[i]);

        }


    }

    //  Function for printing the data

    void OutputData(){

        cout << "Student Name : " << name << endl;
        cout << "Number of class : " << numClasses << endl;

        cout << "Classes : " << endl;

        for(int i=0;i<numClasses;i++) cout << classList[i] << endl;

    }

    //  Getters for private class members

    string getName() const{return name;}
    int getNumClasses() const{return numClasses;}
    string* getClassList() const{return classList;}

    ~Student(){

        delete[] classList;

    }

private:

    string name;
    int numClasses;
    string *classList;

};




int main(){

    Student s1, s2;

    s1.InputData();
    // Input data for student 1
    cout << "Student 1's data:" << endl;
    s1.OutputData();    // Output data for student 1

    cout << endl;
    s2 = s1;
    cout << "Student 2's data after assignment from student 1:" << endl;
    s2.OutputData();

    // Should output same data as for student 1
    s1.ResetClasses();
    cout << "Student 1's data after reset:" << endl;
    s1.OutputData();
    // Should have no classes

    cout << "Student 2's data, should still have original classes:" << endl;
    s2.OutputData();
    // Should still have original classes

    cout << endl;
    return 0;
    
}