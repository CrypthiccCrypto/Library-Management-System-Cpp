#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "Book_Database.h"
#include "User.h"
#include "User_Database.h"

using namespace std;
const short IN_BACK = 8;
const short IN_RET = 13;
UserDatabase udb("User_db.dat");
User* cur;

std::string passwordInput(char sp = '*')
{
    string passwd = "";
    char ch_ipt;
 
    while (true) {
        ch_ipt = getch();
        if (ch_ipt == IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN_BACK && passwd.length() != 0) {
            passwd.pop_back();
            cout << "\b \b";
 
            continue;
        }
        else if (ch_ipt == IN_BACK && passwd.length() == 0) { continue; }
 
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

bool login() {
    cout << "Enter username\n";
    string username;
    cin >> username;

    cout << "Enter password\n";
    string password = passwordInput();

    cur = udb.verify_login(username, password);
    if(!cur) {
        cout << "The username or password is incorrect. Please try again.\n";
        return false;
    }
    else {
        cout << "Hasta la vista mamma mia";
        return true;
    }
}

int main() {
    while(!login());

    return 0;
}