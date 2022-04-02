#pragma once
#include <string>
//#include "User_Database.h"

class Book {
    private:
    std::string title;
    std::string author;
    std::string ISBN;
    std::string publication;
    long long due_date;
    int issued_to;

    public:
    Book(std::string title, std::string author, std::string ISBN, std::string publication, long long due_date, int issued_to);
    std::string getTitle();
    std::string getAuthor();
    std::string getISBN();
    std::string getPublication();
    long long getDueDate();
    int getIssuedTo();

    void setDueDate(long long due_date);
    void setIssueTo(int issued_to);
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setPublication(std::string publication);

    void displayBook();
};