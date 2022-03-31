#pragma once
#include <string>

class Book {
    private:
    std::string title;
    std::string author;
    std::string ISBN;
    std::string publication;

    public:
    Book(std::string title, std::string author, std::string ISBN, std::string publication);
    std::string getTitle();
    std::string getAuthor();
    std::string getISBN();
    std::string getPublication();
};