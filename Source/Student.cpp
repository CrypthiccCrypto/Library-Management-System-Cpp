#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "../Header/Book.h"
#include "../Header/User.h"
#include "../Header/Book_Database.h"
#include "../Header/Student.h"

enum S_CODES{
    ISSUE_BOOK = 1,
    DISPLAY_BOOK,
    DISPLAY_ALL_BOOKS,
    SEARCH_BOOK,
    RETURN_BOOK,
    CHECK_AMOUNT_DUE,
    LOGOUT
};

Student::Student(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, BookDatabase *bdb) : User(ID, name, password, permission, isbns) {
    Student::bdb = bdb;
    max_books = 5;
    fine_rate = 2;
    USER_MENU = "1. Issue a book\n2. Display issued books\n3. Display all books\n4. Search for a book\n5. Return a book\n6. Check outstanding amount\n7. Logout\n";
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

int Student::Calculate_fine(int due_date) {
    int days = (time(0) - due_date)/(24*60*60);
    int fine = 0;

    if(days > 0) {
        fine = days * (this -> fine_rate);
    }
    
    return fine;
}

void Student::Clear_fine_amount(int payment) {
    if(payment > Fine_amount) {
        std::cout << "Please do not pay more than the outstanding amount.\n";
    }
    else {
        std::cout << "A payment of " << payment << " has been made.\n";
        Fine_amount -= payment;
        std::cout << "Current outstanding amount is " << Fine_amount <<"\n";
    }
}

void Student::doActivity() {
    int ch = 0;
    do
    {
        std::cout << "---------------------------------\n";
        std::cout << USER_MENU;

        std::cin >> ch;

        std::cout << "---------------------------------\n";
        if(ch == ISSUE_BOOK) {
            std::cout << "Enter the ISBN of the book you want to issue\n";
            std::string isbn;
            getline(std::cin, isbn);
            getline(std::cin, isbn);
            Book* tmp = bdb -> searchBook(isbn, false);
            if(tmp == nullptr) {
                std::cout << "Book not found\n";
            }
            else {
                this->issueBook(this->max_books, tmp);
            }
        }
        else if(ch == DISPLAY_BOOK) {
            this->displayIssuedBooks();
        }
        else if(ch == DISPLAY_ALL_BOOKS) {
            bdb -> displayBooks();
        }
        else if(ch == SEARCH_BOOK) {
            std::cout << "Enter the title of the book you want to search\n";
            std::string title;
            getline(std::cin, title);
            getline(std::cin, title);
            bdb -> checkAvailable(title);
        }
        else if(ch == RETURN_BOOK) {
            std::cout << "Enter the ISBN of the book you want to return\n";
            std::string isbn;
            getline(std::cin, isbn);
            getline(std::cin, isbn);
            Book* tmp = bdb -> searchBook(isbn, false);
            if(tmp == nullptr) {
                std::cout << "Book not found\n";
            }
            else {
                int due_date = tmp -> getDueDate();
                this->returnBook(tmp);
                this->Clear_fine_amount(this->Calculate_fine(due_date));
            }
        }
        else if(ch == CHECK_AMOUNT_DUE) {
            this -> Fine_amount = 0;
            for(auto isbn : isbns) {
                Book* tmp = bdb -> searchBook(isbn, false);
                int due_date = tmp -> getDueDate();
                this->Fine_amount += this->Calculate_fine(due_date);
            }

            std::cout << "Your current outstanding amount is :" << this -> Fine_amount << std::endl;
        }
    } while (ch != LOGOUT);
    std::cout << "---------------------------------\n";
}