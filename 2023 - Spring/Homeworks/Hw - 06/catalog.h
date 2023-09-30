#ifndef CATALOG_H
#define CATALOG_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Class that holds the information of catalogs from file

namespace CagriYildiz
{
    class Catalog{
        public:
        Catalog();  //default constructor

        void readFile(string filename); //reads file
        void readCommands(string filename); //reads command file

        void printVector() const; //prints the data.txt
        void printCommands() const;   // prints the command.txt
        string printType(); //prints the type
        int getEntryNumber(); // returns entry number

        void sortEntries(string command) const;   //sorts entries
        void searchEntries(string search,string place) const; // search given commands in entries
        void isDuplicate() const; //checks the entries if there are same entries
        void uniqieEntry() const; //checks the number of unique entries

        void executeCommands(); //function for testing program

        private:
        int entryNumber;
        string type;    //holds catalog type
        vector<vector<string>> entries; //holds the entries
        vector<vector<string>> commands;    //holds commands

    };
}
#endif