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
#include "Librarian.h"

Librarian::Librarian(int ID, std::string name, std::string password, char permission, UserDatabase *udb) : User(ID, name, password, permission){
    Librarian::udb = udb;
    USER_MENU = 
    "What would you like to do?\n1. Add a new book\n2. Issue a book\n3. Delete a book\n4. Add a new user\n5. Update a user\n6. Delete user\n";
}

void Librarian::doActivity() {
    int ch = 0;
    do
    {
        std::cout << USER_MENU;

        std::cin >> ch;
        if(ch == 4) {
            std::cout << "Enter name, password and permission of the user respectively\n";
            std::string name;
            std::string password;
            char permission;

            getline(std::cin, name);
            getline(std::cin, name);
            getline(std::cin, password);
            permission = getchar();

            User tmp(udb -> curr_id, name, password, permission);
            udb -> addUser(tmp);
        }
        else if(ch == -1) {
            udb -> updateDatabase();
        }
    } while (ch != -1);
    
    std::cout << "Hello world!";
}