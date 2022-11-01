#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "../Header/Book.h"
#include "../Header/User.h"

User::User(int ID, std::string name, std::string password, char permission, std::vector<std::string> isb) {
    this->name = name;
    this->ID = ID;
    this->password = password;
    this->permission = permission;

    for(auto isbn : isb) { isbns.push_back(isbn); }
}

std::string User::getName() { return User::name; }
int User::getID() { return User::ID; }
std::string User::getPassword() { return User::password; }
char User::getPermission() { return User::permission; }
std::vector<std::string>* User::getISBNS() { return &(User::isbns); }

void User::setName(std::string name) { User::name = name; }
void User::setID(int ID) { User::ID = ID; }
void User::setPassword(std::string password) { User::password = password; }
void User::setPermission(char permission) { User::permission = permission; }
void User::setISBNS(std::vector<std::string>* isbns) { User::isbns = *isbns; }

void User::issueBook(int max_books, Book *book) {
    if(book->getIssueDate() != -1) {
        std::cout << "Book is already issued." << std::endl;
        return;
    }
    else if(this -> permission != 'P' && User::isbns.size() >= max_books) {
            std::cout << "You have reached the maximum number of books you can issue." << std::endl;
            return;
    }
    else {
        User::isbns.push_back(book->getISBN());
        time_t t = time(0);
        book->setIssueDate(t);
        book->setIssueTo(this->ID);

        std::cout << "Book issued successfully" << std::endl;
    }
    std::cout << "---------------------------------\n";
}

void User::returnBook(Book *book) {
    if(book->getIssueDate() == -1 || book->getIssuedTo() != this->ID) {
        std::cout << "Book is not issued to you." << std::endl;
        return;
    }
    else {
        for(auto it = User::isbns.begin(); it != User::isbns.end(); it++) {
            if(*it == book->getISBN()) {
                User::isbns.erase(it);
                std::cout << "The fine to be paid is: " << this->calculateFees(lim, fine_rate, book->getIssueDate()) << "\n" << std::endl;
                book -> setIssueDate(-1);
                book -> setIssueTo(-1);
                break;
            }
        }

        std::cout << "Book returned successfully" << std::endl;
    }
    std::cout << "---------------------------------\n";
}

int User::calculateFees(int lim, int fine_rate, int ret_date) {
    int days = (time(0) - ret_date)/(24*60*60);
    int fine = 0;
    if(days > lim) {
        fine = (days - lim) * fine_rate;
    }
    
    return fine;
}

void User::doActivity() { return; }