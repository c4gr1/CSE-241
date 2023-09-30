#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "dayofyearset.h"

using namespace std;
using namespace cagriYildiz;

void callByValueTest(DayofYearSet test);	// Function for testing class with callbyvalue method
void callByReferenceTest(DayofYearSet& test);  // Function for testing class with callbyvalue method
void saveText(string textname, const DayofYearSet& set); // Function for adding inputs to txt file

/*********************************************************************/

int main(){
    
     cout <<"\n----------------------------------------\n";
    
    /*DayOfYear Tests*/

    /*Default Constructor Tests*/
    
    cout << "DayofYear Default Constructor Test 1" << endl;
    DayofYearSet :: DayofYear defTest1;
    cout << endl << "Day:" << defTest1.getDay() << endl <<  "Month:" << defTest1.getMonth() << endl; /* Also testing getters*/

    cout << "\nDayofYear Default Constructor Test 2" << endl;
    DayofYearSet :: DayofYear defTest2;
    cout << endl << "Day:" << defTest2.getDay() << endl <<  "Month:" << defTest2.getMonth() << endl; /* Also testing getters*/
    
 	cout <<"\n----------------------------------------\n";

    cout << "DayofYear Default Constructor with Parameter Test 1" << endl;
    DayofYearSet :: DayofYear defTest3(20,11);
    cout << endl << "Day:" << defTest3.getDay() << endl <<  "Month:" << defTest3.getMonth() << endl; /* Also testing getters*/

    cout << "\nDayofYear Default Constructor  with Parameter Test 2" << endl;
    DayofYearSet :: DayofYear defTest4(12,12);
    cout << endl << "Day:" << defTest4.getDay() << endl <<  "Month:" << defTest4.getMonth() << endl; /* Also testing getters*/
    
    /*Setters Test*/

	cout <<"\n----------------------------------------\n";

    cout << "DayofYear SetAll Test1" << endl;
    DayofYearSet :: DayofYear setTest;
    setTest.setAll(2,12);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/


    cout << "\nDayofYear SetAll Test2" << endl;
    setTest.setAll(31,8);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/


 	cout <<"\n----------------------------------------\n";

    cout << "DayofYear SetDay Test1" << endl;
    setTest.setDay(1);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/


    cout << "\nDayofYear SetDay Test2" << endl;
    setTest.setDay(15);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/


 	cout <<"\n----------------------------------------\n";

    cout << "DayofYear SetMonth Test1" << endl;
    setTest.setMonth(3);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/

    cout << "\nDayofYear SetMonth Test2" << endl;
    setTest.setMonth(9);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/

 	cout <<"\n----------------------------------------\n";
	
	
	/*DayofYearSet Tests*/

    /*Default Constructor Test */
    
	cout <<"DayofYearSet Default Constructor Test 1" << endl;
    DayofYearSet testDefaultConstructors1;
    cout << endl << testDefaultConstructors1;
    
    cout << "\nDayofYearSet Default Constructor Test 2" << endl;
    DayofYearSet testDefaultConstructors2;
    cout << endl << testDefaultConstructors2 ;

 	cout <<"\n----------------------------------------\n";
 	
 	/*List Constructor Test  (without invalid dayofyears)*/
 	
	cout << "DayofYearSet List Constructor Test1" << endl;
    list<DayofYearSet :: DayofYear> lConstructor1 = {DayofYearSet :: DayofYear(5,7),DayofYearSet :: DayofYear(20,9),DayofYearSet :: DayofYear(11,11),DayofYearSet :: DayofYear(30,8)};	
	 DayofYearSet testListConstructors1(lConstructor1);
	 cout << endl << testListConstructors1 << endl;
 
	cout << "DayofYearSet List Constructor Test2" << endl;
    list<DayofYearSet :: DayofYear> lConstructor2 = {DayofYearSet :: DayofYear(1,1),DayofYearSet :: DayofYear(2,2),DayofYearSet :: DayofYear(3,3),DayofYearSet :: DayofYear(30,8)};	
	 DayofYearSet testListConstructors2(lConstructor2);
	 cout << endl << testListConstructors2 << endl;	 

	saveText("testListConstructors.txt",testListConstructors1 );	
	
	cout <<"\n----------------------------------------\n";
 	
    /*Overloading Operator== and Operator!= Test*/
 	
	cout << "DayofYearSet Overloading Operator== and Operator!= Tests" << endl;
    
    list<DayofYearSet :: DayofYear> lEq1 = {DayofYearSet :: DayofYear(5,7),DayofYearSet :: DayofYear(2,9),DayofYearSet :: DayofYear(11,11),DayofYearSet :: DayofYear(30,8)};
    list<DayofYearSet :: DayofYear> lEq2 = {DayofYearSet :: DayofYear(2,9),DayofYearSet :: DayofYear(30,8),DayofYearSet :: DayofYear(5,7),DayofYearSet :: DayofYear(11,11)};
    list<DayofYearSet :: DayofYear> lEq3 = {DayofYearSet :: DayofYear(17,4),DayofYearSet :: DayofYear(8,12)};
    
    DayofYearSet testEq1(lEq1);
    DayofYearSet testEq2(lEq2);
    DayofYearSet testEq3(lEq3);
   
    cout << "Operator== Test 1" << endl;
    if(testEq1 == testEq2) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "Operator== Test 2" << endl;
    if(testEq1 == testEq3) cout << "True" << endl;
    else cout << "False" << endl;

	cout <<"\n----------------------------------------\n";
  
    cout << "Operator!= Test 1" << endl;
    if(testEq1 != testEq2) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "Operator!= Test 2" << endl;
    if(testEq1 != testEq3) cout << "True" << endl;
    else cout << "False" << endl; 
	
	cout <<"\n----------------------------------------\n";
   
	 /*Add remove and size test*/   
   
    list<DayofYearSet :: DayofYear> lAddRemoveSize = {DayofYearSet :: DayofYear(14,2),DayofYearSet :: DayofYear(2,7),DayofYearSet :: DayofYear(9,2),DayofYearSet :: DayofYear(10,1),DayofYearSet :: DayofYear(30,3),DayofYearSet :: DayofYear(4,4)};
    
    DayofYearSet testAddRemoveSize(lAddRemoveSize);
	
	saveText("testAddRemoveSize.txt",testAddRemoveSize );
		
    cout << endl << "Add Function Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.add(DayofYearSet::DayofYear(13,9));
    cout << endl << "After:" << endl << testAddRemoveSize;

    cout << "Add Function Test 2 (Adding the element that is already in the set)" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.add(DayofYearSet::DayofYear(14,2));
    cout << endl << "After:" << endl << testAddRemoveSize;
	
	cout <<"\n----------------------------------------\n"; 
    
    cout << "Remove Function(no parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove();
    cout << endl << "After:" << endl << testAddRemoveSize;

    cout << "Remove Function(no parameter) Test 2" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove();
    cout << endl << "After:" << endl << testAddRemoveSize;

	cout <<"\n----------------------------------------\n"; 
	
    cout << "Remove Function(valid index parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(3);
    cout << endl << "After:" << endl << testAddRemoveSize;

    cout << "Remove Function(invalid index parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(8);
    cout << endl << "After:" << endl << testAddRemoveSize;	
	
	cout <<"\n----------------------------------------\n";
	
    cout << "Remove Function(valid DayofYear parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(DayofYearSet:: DayofYear(2,7));
    cout << endl << "After:" << endl << testAddRemoveSize;

    cout << "Remove Function(invalid DayofYear parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(DayofYearSet:: DayofYear(1,1));
    cout << endl << "After:" << endl << testAddRemoveSize;	
	 
	cout <<"\n----------------------------------------\n";

    cout << "Remove Function(empty set) Test" << endl;
    testAddRemoveSize.remove(); testAddRemoveSize.remove(); testAddRemoveSize.remove();
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove();
    cout << endl << "After:" << endl << testAddRemoveSize;	

	cout <<"\n----------------------------------------\n";
	
    cout << "Size Function Test 1" << endl;
    testAddRemoveSize.add(DayofYearSet:: DayofYear(1,1)); testAddRemoveSize.add(DayofYearSet:: DayofYear(3,5)); testAddRemoveSize.add(DayofYearSet:: DayofYear(22,11));
    cout << endl << "Set:" << endl << testAddRemoveSize;
    cout << "Size of test:" << endl << testAddRemoveSize.Size() << endl;

    cout << "Size Function (empty set) Test 2" << endl;
    testAddRemoveSize.remove(); testAddRemoveSize.remove(); testAddRemoveSize.remove();
    
    cout << "Size of test:" << testAddRemoveSize.Size() << endl	;

	cout <<"\n----------------------------------------\n";

	/*Set operation test */
	 	    
   	list<DayofYearSet ::DayofYear> a = {DayofYearSet::DayofYear(1,3),DayofYearSet::DayofYear(17,9)};
    list<DayofYearSet ::DayofYear> b = {DayofYearSet::DayofYear(14,1),DayofYearSet::DayofYear(17,9),DayofYearSet::DayofYear(1,3)};
    
    DayofYearSet testOperation1(a);
    DayofYearSet testOperation2(b);
    
    cout << "Union Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation2;

   cout << endl << "A + B:" << endl << testOperation1 + testOperation2;
   cout << endl << "B + A:" << endl << testOperation2 + testOperation1;

    cout << "Union (same set) Test 2" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation2;
    

    cout << endl << "A + B:" << endl << testOperation1 + testOperation1;
    cout << endl << "B + A:" << endl << testOperation1 + testOperation1;

	cout <<"\n----------------------------------------\n"; 
	
	cout << "Diffrence Test 1" << endl;
    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation2;

    cout << endl << "A - B:" << endl << testOperation1 - testOperation2;
    cout << endl << "B - A:" << endl << testOperation2 - testOperation1;

    cout << "Diffrence (same set) Test 2" << endl;
	
	cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation1;

    cout << endl << "A - B:" << endl << testOperation1 - testOperation1;
    cout << endl << "B - A:" << endl << testOperation1 - testOperation1;
  
  	cout <<"\n----------------------------------------\n";
  	
  	cout << "Intersection Test 1" << endl; 
    
    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation2;

    cout << endl << "A ^ B:" << endl << (testOperation1 ^ testOperation2);
    cout << endl << "B ^ A:" << endl << (testOperation2 ^ testOperation1);
    
    cout << "Intersection (same set) Test 2" << endl;

    cout << endl << "Set A :" << endl << (testOperation1);
    cout << endl << "Set B :" << endl << (testOperation1);

    cout << endl << "A ^ B:" << endl << (testOperation1 ^ testOperation1);
    cout << endl << "B ^ A:" << endl << (testOperation1 ^ testOperation1);
    
    cout <<"\n----------------------------------------\n";

    cout << "Complement Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "!A:" << endl << !testOperation1;
    
	saveText("!testOperation1.txt",!testOperation1 );

    cout << "Complement Test 2" << endl;

    cout << endl << "Set A :" << endl << testOperation1;

    cout << endl << "!(!A):" << endl << !(!testOperation1);

	cout << "Call by Vaule Set Test" << endl << endl;

    cout <<"\n----------------------------------------\n";

    cout << "Index Operator Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;

    cout << endl << "Second Element of A:" << testOperation1[1];

    cout << "Index Operator Test 2" << endl;

    cout << endl << "Set A :" << endl << testOperation1;

    cout << endl << "First Element of A " << testOperation1[0];

    cout <<"\n----------------------------------------\n";
	
	cout << "Call by Value Set Test" << endl << endl;
	
    list<DayofYearSet ::DayofYear> vCall = {DayofYearSet::DayofYear(1,3),DayofYearSet::DayofYear(17,9),DayofYearSet::DayofYear(23,3)};
    DayofYearSet testCall(vCall);

    cout << "Before Set is sent to the function:" << endl << testCall << endl;
    callByValueTest(testCall);
    cout << "After Set is sent to the function:" << endl << testCall << endl;

	 cout << "Call by Reference Set Test" << endl << endl;

    cout << "Before Set is sent to the function:" << endl << testCall << endl;
    callByReferenceTest(testCall);
    cout << "After Set is sent to the function:" << endl << testCall << endl;
    
}

/*********************************************************************/

void callByValueTest(DayofYearSet test){
    cout << "Adding element to set" <<  endl;
    test.add(DayofYearSet::DayofYear(1,1));
    cout << "Set in function:" << endl << test << endl;
}

/*********************************************************************/

void callByReferenceTest(DayofYearSet& test){
    cout << "Adding element to set" << endl;
    test.add(DayofYearSet::DayofYear(1,1));
    cout << "Set in function:" << endl << test << endl;
}
 
/*********************************************************************/ 
    
void saveText(string textname, const DayofYearSet& set){

    ofstream fout;

    fout.open(textname);

    fout << set;

    fout.close();

    return;

    
}   
    
 
