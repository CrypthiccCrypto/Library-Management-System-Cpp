#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "Book_Database.h"

const char* BOOK_FORMAT_OUT = "%s,%s,%s,%s\n";

Book::Book(std::string title, std::string author, std::string ISBN, std::string publication) {
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->publication = publication;
}

std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getISBN() { return ISBN; }
std::string Book::getPublication() { return publication; }