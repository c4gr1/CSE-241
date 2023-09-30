#include <iostream>
#include "catalog.h"
//#include "catalog.cpp"

using namespace std;

using namespace CagriYildiz;

int main()
{

    ofstream outputFile("output.txt");
    streambuf* coutBuffer = cout.rdbuf();
    cout.rdbuf(outputFile.rdbuf());

    Catalog test;

    test.executeCommands(); // Testing the program

    cout.rdbuf(coutBuffer);
    outputFile.close();

//    In case of testting the indivudual functions of catalog class 
/*  
    Catalog test1;

    test1.readFile("data.txt");
    test1.readCommands("commands.txt");
    cout << "Type is " << test1.printType() << endl ;
    test1.printVector();
    test1.sortEntries("title");
    test1.searchEntries("Graphics Gems V","title");

    cout << "\n----------------------\n\n";

    Catalog test2;

    test2.readFile("data2.txt");
    cout << "Type is " << test2.printType() << endl ;
    test2.printVector();
    test2.sortEntries("year");
    test2.searchEntries("Joe Satriani","artists");

    cout << "\n----------------------\n\n";

    Catalog test3;

    test3.readFile("data3.txt");
    cout << "Type is " << test3.printType() << endl ;
    test3.printVector();
    test3.sortEntries("starring");
    test3.searchEntries("Jude Law, Nicole Kidman, Renee Zellweger","starring");

    cout << "\n----------------------\n\n";

    test1.printCommands();
*/

}
