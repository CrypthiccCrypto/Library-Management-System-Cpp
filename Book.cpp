#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Book.h"
#include "Book_Database.h"

const char* BOOK_FORMAT_OUT = "%s,%s,%s,%s\n";

Book::Book(std::string title, std::string author, std::string ISBN, std::string publication, long long issue_date) {
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->publication = publication;
    this->issue_date = issue_date; 
}

std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getISBN() { return ISBN; }
std::string Book::getPublication() { return publication; }
long long Book::getIssueDate() { return issue_date; }

void Book::setIssueDate(long long issue_date) { Book::issue_date = issue_date; }

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
    }
    std::cout << "---------------------------------\n";
}