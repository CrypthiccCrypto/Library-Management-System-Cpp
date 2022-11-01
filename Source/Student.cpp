#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../Header/Book.h"
#include "../Header/User.h"
#include "../Header/Book_Database.h"
#include "../Header/Student.h"

enum S_CODES{
    ISSUE_BOOK = 1,
    DISPLAY_BOOK,
    RETURN_BOOK,
    LOGOUT
};

Student::Student(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, BookDatabase *bdb) : User(ID, name, password, permission, isbns) {
    Student::bdb = bdb;
    max_books = 5;
    lim = 30;
    fine_rate = 2;
    USER_MENU = "1. Issue a book\n2. Display issued books\n3. Return a book\n4. Logout\n";
}

void Student::displayIssuedBooks() {
    if(isbns.size() == 0) {
        std::cout << "You have no books to issue." << std::endl;
        std::cout << "---------------------------------\n";
        return;
    }
    for(auto s : isbns) {
        Book* tmp = bdb -> searchBook(s, false);
        tmp -> displayBook();
    }
}

void Student::doActivity() {
    int ch = 0;
    do
    {
        std::cout << USER_MENU;
        std::cout << "---------------------------------\n";

        std::cin >> ch;
        if(ch == ISSUE_BOOK) {
            std::cout << "Enter the ISBN of the book you want to issue\n";
            std::string isbn;
            std::cin >> isbn;
            Book* tmp = bdb -> searchBook(isbn, false);
            if(tmp == nullptr) {
                std::cout << "Book not found\n";
            }
            else {
                this->issueBook(this->max_books, tmp);
            }
        }
        else if(ch == RETURN_BOOK) {
            std::cout << "Enter the ISBN of the book you want to return\n";
            std::string isbn;
            std::cin >> isbn;
            Book* tmp = bdb -> searchBook(isbn, false);
            if(tmp == nullptr) {
                std::cout << "Book not found\n";
            }
            else {
                this->returnBook(tmp);
            }
        }
        else if(ch == DISPLAY_BOOK) {
            this->displayIssuedBooks();
        }
        else if(ch == DISPLAY_BOOK) {
            displayIssuedBooks();
        }
    } while (ch != LOGOUT);
    std::cout << "---------------------------------\n";
}