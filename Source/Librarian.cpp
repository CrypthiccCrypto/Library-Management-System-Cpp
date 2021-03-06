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
    ADD_BOOK=1,
    DELETE_BOOK,
    LIST_ALL_BOOK,
    LIST_I_BOOK,
    ADD_USER,
    UPDATE_USER,
    DELETE_USER,
    DISPLAY_USER,
    CHECK_ISSUED_BY_USER,
    UPDATE_BOOK,
    LOGOUT
};

Librarian::Librarian(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, UserDatabase *udb, BookDatabase *bdb) : User(ID, name, password, permission, isbns){
    Librarian::udb = udb;
    Librarian::bdb = bdb;
    max_books = 0;
    USER_MENU = 
    "What would you like to do?\n1. Add a new book\n2. Delete a book\n3. List all books\n4. List issued books\n5. Add a new user\n6. Update a user\n7. Delete user\n8. Display all users\n9. Check books issued by a user\n10. Update book\n11. Logout\n";
}

void Librarian::doActivity() {
    int ch = 0;
    do
    {
        std::cout << "---------------------------------\n";
        std::cout << USER_MENU;
        std::cout << "---------------------------------\n";
        
        int ch;
        std::string input;
        getline(std::cin, input);
        try { ch = stoi(input); }
        catch(...) {
            std::cout << "Invalid input.\n";
            ch = -1;
        }

        std::cout << "---------------------------------\n";
        if(ch == ADD_BOOK) {
            std:: cout << "Enter title, author, ISBN, and publication of the book, in separate lines, respectively\n";
            std::string title;
            std::string author;
            std::string ISBN;
            std::string publication;

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
        else if(ch == LIST_I_BOOK) {
            bdb -> displayIssuedBooks();
        }
        else if(ch == DELETE_BOOK) {
            std::cout << "Enter the ISBN of the book to be deleted\n";
            std::string ISBN;
            getline(std::cin, ISBN);
            Book* tmp = bdb -> searchBook(ISBN, false);
            if(tmp != nullptr) {
                int id = tmp -> getIssuedTo();
                if(id != -1) {
                    User* t = udb -> searchUser(id);
                    t -> removeBook(tmp);
                }
            }
            bdb -> deleteBook(ISBN);
        }
        else if(ch == ADD_USER) {
            std::cout << "Enter name, password and permission of the user, in separate lines, respectively\n";
            std::string name;
            std::string password;
            std::string permission;

            getline(std::cin, name);
            getline(std::cin, password);
            getline(std::cin, permission);

            std::vector<std::string> empt;
            User tmp(udb -> curr_id, name, password, permission[0], empt);
            udb -> addUser(tmp);
        }
        else if(ch == DELETE_USER) {
            std::cout << "Enter ID of the user you want to delete.\n";

            int id;
            std::string input;
            getline(std::cin, input);
            try { id = stoi(input); }
            catch(...) {
                std::cout << "Invalid input.\n";
                continue;
            }

            if(id == this -> ID) {
                std::cout << "You cannot delete the current user.\n";
            }
            else {
                User* tmp = udb -> searchUser(id);
                if(tmp != nullptr) {
                    std::vector<std::string> *t = tmp -> getISBNS();
                    for(auto isbn : *t) {
                        Book *b = bdb -> searchBook(isbn, false);
                        b -> setIssueTo(-1);
                        b -> setDueDate(-1);
                    }

                    udb -> deleteUser(id);
                    std::cout << "User deleted successfully.\n";
                }
            }
        }
        else if(ch == UPDATE_USER) {
            std::cout << "Enter ID of the user you want to update.\n";

            int id;
            std::string input;
            getline(std::cin, input);
            try { id = stoi(input); }
            catch(...) {
                std::cout << "Invalid input.\n";
                continue;
            }

            if(id == this -> ID) {
                std::cout << "You cannot update the current user.\n";
            }
            else {
                User* tmp = udb -> searchUser(id);
                if(tmp != nullptr) {
                    std::cout << "Enter name, password and permission of the user, in separate lines, respectively\n";
                    std::string name;
                    std::string password;
                    std::string permission;

                    getline(std::cin, name);
                    getline(std::cin, password);
                    getline(std::cin, permission);

                    tmp -> setName(name);
                    tmp -> setPassword(password);
                    tmp -> setPermission(permission[0]);

                    std::cout << "User has been updated successfully.\n";
                }
                else {
                    std::cout << "User not found.\n";
                }
            }
        }
        else if(ch == DISPLAY_USER) {
            udb -> displayUsers();
        }
        else if(ch == CHECK_ISSUED_BY_USER) {
            std::cout << "Enter ID of the user you want to check.\n";

            int id;
            std::string input;
            getline(std::cin, input);
            try { id = stoi(input); }
            catch(...) {
                std::cout << "Invalid input.\n";
                continue;
            }

            User* tmp = udb -> searchUser(id);
            if(tmp != nullptr) {
                std::vector<std::string> *t = tmp -> getISBNS();
                for(auto isbn : *t) {
                    Book *b = bdb -> searchBook(isbn, false);
                    b -> displayBook();
                }
            }
            else {
                std::cout << "User ID does not exist.\n"; 
            }
        }
        else if(ch == UPDATE_BOOK) {
            std::cout << "Enter ISBN of the book you want to update.\n";

            std::string ISBN;
            getline(std::cin, ISBN);
            Book* tmp = bdb -> searchBook(ISBN, false);
            if(tmp != nullptr) {
                std::cout << "Enter title, author and publication of the book, in separate lines, respectively\n";
                std::string title;
                std::string author;
                std::string publication;

                getline(std::cin, title);
                getline(std::cin, author);
                getline(std::cin, publication);

                tmp -> setTitle(title);
                tmp -> setAuthor(author);
                tmp -> setPublication(publication);

                std::cout << "Book updated successfully.\n";
            }
            else {
                std::cout << "Book not found.\n";
            }
        }
        else if(ch == LOGOUT) { break; }
    } while (true);
}