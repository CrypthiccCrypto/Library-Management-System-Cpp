#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "../Header/Book.h"
#include "../Header/Book_Database.h"
#include "../Header/User.h"
#include "../Header/User_Database.h"
#include "../Header/Librarian.h"
#include "../Header/Student.h"
#include "../Header/Professor.h"

using namespace std;

const short IN_BACK = 8;
const short IN_RET = 13;
const string USER_DATABASE = "../Database/User_db.dat";
const string BOOK_DATABASE = "../Database/Book_db.dat";
const std::vector<std::string> empt;

UserDatabase udb(USER_DATABASE);
BookDatabase bdb(BOOK_DATABASE);
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
    getline(std::cin, username);
    getline(std::cin, username);

    cout << "Enter password\n";
    string password = passwordInput();

    cur = udb.verify_login(username, password);
    if(!cur) {
        cout << "The username or password is incorrect. Please try again.\n";
        return false;
    }
    else { return true; }
}

int main() {
    int ch = 0;
    do {
        std::cout << "Welcome to the Library Management System!\n";
        std::cout << "What would you like to do?\n1.Login\n2.Logout\n";
        std::cout << "---------------------------------\n";

        std::cin >> ch;
        if(ch == 1) {
            while(!login());

            cout << "Welcome " << cur -> getName() << ".\n";
            char p = cur -> getPermission();
            
            if(p == 'A') {
                Librarian lb(cur -> getID(), cur -> getName(), cur -> getPassword(), cur -> getPermission(), empt, &udb, &bdb);
                lb.setISBNS(cur -> getISBNS());
                lb.doActivity();
            }
            else if(p == 'S') {
                Student s(cur -> getID(), cur -> getName(), cur -> getPassword(), cur -> getPermission(), empt, &bdb);
                s.setISBNS(cur -> getISBNS());
                s.doActivity();
                cur -> setISBNS(s.getISBNS());
            }
            else if(p == 'P') {
                Professor p(cur -> getID(), cur -> getName(), cur -> getPassword(), cur -> getPermission(), empt, &bdb);
                p.setISBNS(cur -> getISBNS());
                p.doActivity();
                cur -> setISBNS(p.getISBNS());
            }
            else {
                cout << "Underfined permission" << endl;
            }
        }
    } while(ch != 2);

    udb.updateDatabase();
    bdb.updateBookDatabase();
    return 0;
}