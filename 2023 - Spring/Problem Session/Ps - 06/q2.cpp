#include <iostream>
#include "password.h"
#include "user.h"

using namespace std;
using namespace Authenticate;


//  main function to test namespace files
int main(){

    inputUserName();
    inputPassword();

    cout << "your username is " << getUserName()
         << " and your password is " << getPassword()
         << endl;

    cout << "enter a character to exit."  << endl;

    char wait;

    cin >> wait;

    return 0;     

}