#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "../Header/Book.h"
#include "../Header/Book_Database.h"
#include "../Header/User_Database.h"

const char* BOOK_FORMAT_OUT = "%s,%s,%s,%s\n";

Book::Book(std::string title, std::string author, std::string ISBN, std::string publication, long long issue_date, int issued_to) {
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->publication = publication;
    this->issue_date = issue_date;
    this->issued_to = issued_to;
}

std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getISBN() { return ISBN; }
std::string Book::getPublication() { return publication; }
long long Book::getIssueDate() { return issue_date; }
int Book::getIssuedTo() { return issued_to; }

void Book::setIssueDate(long long issue_date) { Book::issue_date = issue_date; }
void Book::setIssueTo(int issued_to) { Book::issued_to = issued_to; }

void Book::displayBook() {
    std::cout << "ISBN: " << this -> ISBN << "\n";
    std::cout << "Title: " << this -> title << "\n";
    std::cout << "Author: " << this -> author << "\n";
    std::cout << "Publisher: " << this -> publication << "\n";
    int ret_time = this -> issue_date;
    if(ret_time == -1) { std::cout << "Issued: Not Issued\n"; }
    else {
        time_t t = {ret_time};
        std::cout << "Issued: " << ctime(&t) << "\n";
        std::cout << "Issued to User ID: " << this -> issued_to << "\n";
    }
    std::cout << "---------------------------------\n";
}