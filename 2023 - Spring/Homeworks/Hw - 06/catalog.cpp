
#include "catalog.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

namespace CagriYildiz
{

//Default Constructor
Catalog::Catalog(){}

//reads data file
void Catalog::readFile(string filename)
{
    //try-catch block for file existing control
    try
    {
    
    ifstream file(filename);    //to read inputs from file 
    
    if(!file)
        throw runtime_error("file can not found !");

    string line;    //  variable for lines

    getline(file,line); //  getting the catalog type

    type = line;

    while(getline(file,line))   //  until end of file
    {   
        vector<string> vect;    //  temp vector for entry
        istringstream iss(line);    //  for reading input
        string r1,r2,r3,r4,r5,space;    //  temp variables for file inputs

        //getting inputs
        getline(iss,space,'\"');
        getline(iss,r1,'\"');
        getline(iss,space,'\"');
        getline(iss,r2,'\"');
        getline(iss,space,'\"');
        getline(iss,r3,'\"');
        getline(iss,space,'\"');
        getline(iss,r4,'\"');
        getline(iss,space,'\"');
        getline(iss,r5,'\"');

        //assigning the inputs to vector
        vect.push_back(r1);
        vect.push_back(r2);
        vect.push_back(r3);
        vect.push_back(r4);
        vect.push_back(r5);

        entries.push_back(vect);

    }

    file.close();

    }
    catch(const std::exception& e)
    {
        std::cerr << "File error : " << e.what() << '\n';
    }


}

//read command file
void Catalog::readCommands(string filename)
{

    //try-catch block for file existing control
    try
    {
    
    ifstream file(filename);    //to read inputs from file 
    
    if(!file)
        throw runtime_error("file can not found !");

    string line;    //  variable for lines

    while(getline(file,line))   //  until end of file
    {

        vector<string> vect;    //  temp file for lines
        istringstream iss(line);    //  necessery for dividing line
        string r1,r2,r3,r4,space;   //  temp variables for inputs

        getline(iss,r1,' ');
        getline(iss,space,'\"');
        getline(iss,r2,'\"');
        getline(iss,space,' ');
        getline(iss,r3,' ');
        getline(iss,space,'\"');
        getline(iss,r4,'\"');

        vect.push_back(r1);
        vect.push_back(r2);
        vect.push_back(r3);
        vect.push_back(r4);

        commands.push_back(vect);   //  assigning the vector for inputs

    }

    file.close();

    }
    catch(const std::exception& e)
    {
        std::cerr << "File Error : " << e.what() << '\n';
    }

}

//prints vector
void Catalog::printVector() const
{

    //for loop for printing vector 
    for(int i=0;i<entries.size();i++)
    {
        if(type=="book")
        {

        cout << "\"" << entries[i][0] << "\" " << "\"" << entries[i][1] << "\" " << "\"" 
                     << entries[i][2] << "\" " << "\"" << entries[i][3] << "\"" << endl;   

        }
        if(type=="music")
        {   
        cout << "\"" << entries[i][0] << "\" " << "\"" << entries[i][1] << "\" " << "\"" 
                     << entries[i][2] << "\" " << "\"" << entries[i][3] << "\"" << endl; 
        }
        if(type=="movie")
        {   
        cout << "\"" << entries[i][0] << "\" " << "\"" << entries[i][1] << "\" " << "\"" 
                     << entries[i][2] << "\" " << "\"" << entries[i][3] << "\""  << "\" "  
                     << entries[i][4] << "\"" << endl;
        }
    }
}  

//prints commands
void Catalog::printCommands() const
{

// for loop for printing commands
    for(int i=0;i<commands.size();i++)
    {
        for(int j=0;j<commands[i].size();j++)
        {
            cout << commands[i][j] << "---";
        }

        cout << endl;

    }


}

//prints catalog type
string Catalog::printType()
{
    return type;
}

//returns entry count
int Catalog::getEntryNumber()
{
    return entries.size();
}

//sorts entries
void Catalog::sortEntries(string command) const
{
    vector<string> sortedVector;    //vector for sorting

    //if -else blocks for sort type
    for(int i=0;i<entries.size();i++)
    {
            if(command == "title")
            {
                sortedVector.push_back(entries[i][0]);
            }
    
            else if((command == "authors") || (command == "artists") || (command=="directors"))
            {
                sortedVector.push_back(entries[i][1]);
            }

            else if(command == "year")
            {
                sortedVector.push_back(entries[i][2]);
            }
    
            else if(command == "tags" || command == "genre" )
            {
                sortedVector.push_back(entries[i][3]);
            }

            else if(command == "starring")
            {
                sortedVector.push_back(entries[i][4]);
            }

            else
            {
                //  Exception for errors
                cout << "Exception : command is wrong" << endl;
                break;
            }

    }

    sort(sortedVector.begin(),sortedVector.end());  //  sorting the vector
    
    //for loop for the finding the real location of sorted vector 
        for(int i=0;i<sortedVector.size();i++)
        {
            for(int j=0;j<sortedVector.size();j++)
            {
                //if-else blocks for sort type
                if(command == "title")
                {
                    if(sortedVector[i] == entries[j][0])    //comparing the vectors
                    {
                        if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }
                        else 
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }
                    }   
                }
                 //if-else blocks for sort type       
                if(command == "authors" || command == "artists" || command == "directors")
                {
                    if(sortedVector[i]==entries[j][1])  //comparing the vectors
                    {
                        if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                        
                        else
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }                        
                    }               
                }
                //if-else blocks for sort type
                if(command == "year")
                {
                    if(sortedVector[i]==entries[j][2])  //comparing the vectors
                    {
                        if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                         
                        else 
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }
                    }  
                }
                 //if-else blocks for sort type       
                if(command == "tags" || command == "genre" )
                {
                    if(sortedVector[i]==entries[j][3])  //comparing the vectors
                    {
                        if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                         
                        else 
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }
                    }  
                }
                //if-else blocks for sort type
                if(command == "starring")
                {
                    if(sortedVector[i]==entries[j][4])  //comparing the vectors
                       {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        } 
                }
                
            }
                
        }
}

//seachs the given command in the entries
void Catalog::searchEntries(string search,string place) const
{

    bool flag = false;  //  variable for holding situation

//for loop for searching the given commands
        for(int j=0;j<entries.size();j++)
        {
            // if else blocks for commands
            if(place == "title")
            {
                if(search == entries[j][0]) //  searching the entries
                {
                    flag=true;

                    if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                     
                    else                    
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }                   
                }
            }

            // if else blocks for commands

            if(place == "authors" || place == "artists" || place =="directors")
            {    
                if(search == entries[j][1]) //  searching the entries
                {
                    flag=true;

                    if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                    
                    else
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }                                         
                    
                }
            }

            // if else blocks for commands

            if(place == "year")
            {
                if(search == entries[j][2]) //  searching the entries
                {
                    flag=true;

                    if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                    
                    else                     
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }                    
                }
            }

            // if else blocks for commands
   
            if(place == "tags" || place == "genre" )
            {
                if(search == entries[j][3]) //  searching the entries
                {
                    flag=true;

                    if(type == "movie")  
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                    
                    else                     
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\"" << endl;  
                        }                   
                }               
            }

            // if else blocks for commands

            if(place =="starring")
            {
                if(search == entries[j][4]) //  searching the entries
                {
                    flag=true;

                    if(type == "movie")
                        {
                            cout << "\"" << entries[j][0] << "\" " << "\"" << entries[j][1] << "\" " << "\"" 
                                         << entries[j][2] << "\" " << "\"" << entries[j][3] << "\""  << "\" "  
                                         << entries[j][4] << "\"" << endl;                            
                        }                   
                    
                }
            }
        }

        // exception for errors
        if(flag==false) 
        {
            cout << "Exception : command is wrong" << endl;  
        }

}

//checks the duplicate entries
void Catalog::isDuplicate() const
{

//for loop finding dublicate situation
    for(int i=0;i<entries.size()-1;i++)
    {
        for(int j=i+1;j<entries.size();j++)
        {
            if(entries[i][0]==entries[j][0])    //checking the dublication
            {
                cout << "Exception : duplicate entry" << endl;
                        
                if(type == "movie")
                {
                    cout << "\"" << entries[i][0] << "\" " << "\"" << entries[i][1] << "\" " << "\"" 
                                 << entries[i][2] << "\" " << "\"" << entries[i][3] << "\""  << "\" "  
                                 << entries[i][4] << "\"" << endl;                            
                }
                else 
                {
                    cout << "\"" << entries[i][0] << "\" " << "\"" << entries[i][1] << "\" " << "\"" 
                                 << entries[i][2] << "\" " << "\"" << entries[i][3] << "\"" << endl;  
                }                
            }
        }
    }
}

//counts the unique entries
void Catalog::uniqieEntry() const
{

//for loop for finding missing field
    for(int i=0;i<entries.size();i++)
    {
        for(int j=0;j<entries[i].size();j++)
        {
            if(entries[i][j] == " ")    //checking the missing field
            {
                cout << "Exception : missing field" << endl;

                if(type == "movie")
                {
                    cout << "\"" << entries[i][0] << "\" " << "\"" << entries[i][1] << "\" " << "\"" 
                                 << entries[i][2] << "\" " << "\"" << entries[i][3] << "\""  << "\" "  
                                 << entries[i][4] << "\"" << endl;                            
                }
                else 
                {
                    cout << "\"" << entries[i][0] << "\" " << "\"" << entries[i][1] << "\" " << "\"" 
                                 << entries[i][2] << "\" " << "\"" << entries[i][3] << "\"" << endl;  
                } 
            }
        }
    }
}

//test the program with command
void Catalog::executeCommands()
{


    readFile("data.txt");  //reading file
    readCommands("commands.txt");   //reading commands

        cout << "Catalog Read: " << type << endl;

        uniqieEntry();  //checking missing field
        isDuplicate();  //checking the dublicate situation

        cout << getEntryNumber() << " unique entries " << endl;

        for(int i=0;i<commands.size();i++)
        {
           if(commands[i][0]== "search")    //if command is search
            {
                cout << "search \"" << commands[i][1] << "\" in \"" << commands[i][3] << "\"" << endl; 
                searchEntries(commands[i][1],commands[i][3]);           
                       
            }

            else if(commands[i][0]== "sort")    //if command is sort
            {
                cout << "sort \"" << commands[i][1] << "\"" << endl;
                sortEntries(commands[i][1]);
            }

            else    //  wrong command situation
            {
                cout << "Exception: command is wrong" << endl;
                cout << commands[i][0] << " \"" << commands[i][1] << "\" " << commands[i][2] << " \"" <<  commands[i][3] << "\"" << endl;

            }
        }
}

}