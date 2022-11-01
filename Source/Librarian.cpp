#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../Header/Book.h"
#include "../Header/Book_Database.h"
#include "../Header/User.h"
#include "../Header/User_Database.h"
#include "../Header/Librarian.h"

enum LIB_CODES{
    ISSUE_BOOK=1,
    ADD_BOOK,
    DELETE_BOOK,
    LIST_ALL_BOOK,
    LIST_I_BOOK,
    ADD_USER,
    UPDATE_USER,
    DELETE_USER,
    DISPLAY_USER,
    LOGOUT
};

Librarian::Librarian(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, UserDatabase *udb, BookDatabase *bdb) : User(ID, name, password, permission, isbns){
    Librarian::udb = udb;
    Librarian::bdb = bdb;
    max_books = 0;
    fine_rate = 0;
    lim = 0;
    USER_MENU = 
    "What would you like to do?\n1. Issue a book\n2. Add a new book\n3. Delete a book\n4. List all books\n5. List issuable books\n6. Add a new user\n7. Update a user\n8. Delete user\n9. Display all users\n10. Logout\n";
}

void Librarian::doActivity() {
    int ch = 0;
    do
    {
        std::cout << USER_MENU;
        std::cout << "---------------------------------\n";

        std::cin >> ch;
        if(ch == ADD_BOOK) {
            std:: cout << "Enter title, author, ISBN, and publication of the book respectively\n";
            std::string title;
            std::string author;
            std::string ISBN;
            std::string publication;

            getline(std::cin, title);
            getline(std::cin, title);
            getline(std::cin, author);
            getline(std::cin, ISBN);
            getline(std::cin, publication);

            Book tmp(title, author, ISBN, publication, -1, -1);
            bdb -> addBook(tmp);
        }
        else if(ch == LIST_ALL_BOOK) {
            bdb -> displayBooks();
        }
        else if(ch == DELETE_BOOK) {
            std::cout << "Enter the ISBN of the book to be deleted\n";
            std::string ISBN;
            getline(std::cin, ISBN);
            getline(std::cin, ISBN);
            bdb -> deleteBook(ISBN);
        }
        else if(ch == ADD_USER) {
            std::cout << "Enter name, password and permission of the user respectively\n";
            std::string name;
            std::string password;
            char permission;

            getline(std::cin, name);
            getline(std::cin, name);
            getline(std::cin, password);
            permission = getchar();

            std::vector<std::string> empt;
            User tmp(udb -> curr_id, name, password, permission, empt);
            udb -> addUser(tmp);
        }
        else if(ch == DELETE_USER) {
            std::cout << "Enter ID of the user you want to delete.\n";

            int id;
            std::cin >> id;
            if(id == this -> ID) {
                std::cout << "You cannot delete the current user.\n";
            }
            else {
                udb -> deleteUser(id);
                std::cout << "User deleted successfully.\n";
            }
        }
        else if(ch == DISPLAY_USER) {
            udb -> displayUsers();
        }
    } while (ch != LOGOUT);
    std::cout << "---------------------------------\n";
}