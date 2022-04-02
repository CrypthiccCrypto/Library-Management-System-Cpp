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

Book::Book(std::string title, std::string author, std::string ISBN, std::string publication, long long due_date, int issued_to) {
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->publication = publication;
    this->due_date = due_date;
    this->issued_to = issued_to;
}

std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getISBN() { return ISBN; }
std::string Book::getPublication() { return publication; }
long long Book::getDueDate() { return due_date; }
int Book::getIssuedTo() { return issued_to; }

void Book::setDueDate(long long due_date) { Book::due_date = due_date; }
void Book::setIssueTo(int issued_to) { Book::issued_to = issued_to; }
void Book::setTitle(std::string title) { Book::title = title; }
void Book::setAuthor(std::string author) { Book::author = author; }
void Book::setPublication(std::string publication) { Book::publication = publication; }

void Book::displayBook() {
    std::cout << "ISBN: " << this -> ISBN << "\n";
    std::cout << "Title: " << this -> title << "\n";
    std::cout << "Author: " << this -> author << "\n";
    std::cout << "Publisher: " << this -> publication << "\n";
    int ret_time = this -> due_date;
    if(ret_time == -1) { std::cout << "Due on: Not Issued\n"; }
    else {
        time_t t = {ret_time};
        std::cout << "Due on: " << ctime(&t);
        std::cout << "Issued to User ID: " << this -> issued_to << "\n";
    }
    std::cout << "---------------------------------\n";
}