#include <iostream>
#include <string>
#include <cctype>
#include "password.h"

using namespace std;

//  unnamed namespace that checks the user password
namespace{

    string password;

    bool isValid()
    {
        if(password.length() >= 8)
        {

            for(int i=0; i<password.length(); i++)
                if(isalpha(password[i]))
                    return true;

        }

    return false;

    }
}

//  namespace for taking user password
namespace Authenticate{

    void inputPassword()
    {
        do{
            
            cout << "Enter your password (at least 8 character"
                 << " and at least one non-later " << endl;

            cin >> password;     

        }while(!isValid());

    }


    string getPassword(){ return password; }


}