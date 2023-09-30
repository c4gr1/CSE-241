#include <iostream>
#include <string>
#include "user.h"

using namespace std;

//  unnamed namespace that checks the usename
namespace{

    string username;

    bool isValid(){

        if(username.length() == 8)  return true;

    return false;

    }

}

//  namespace for taking user name
namespace Authenticate
{

    void inputUserName()
    {
        do{

            cout << "enter your username " 
                 << "(8 letters only)" << endl;

            cin >> username;

        }while(!isValid());

    }

    string getUserName() { return username; }

}