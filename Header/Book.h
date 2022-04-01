#pragma once
#include <string>
#include "User_Database.h"

class Book {
    private:
    std::string title;
    std::string author;
    std::string ISBN;
    std::string publication;
    long long issue_date;
    int issued_to;

    public:
    Book(std::string title, std::string author, std::string ISBN, std::string publication, long long issue_date, int issued_to);
    std::string getTitle();
    std::string getAuthor();
    std::string getISBN();
    std::string getPublication();
    long long getIssueDate();
    int getIssuedTo();

    void setIssueDate(long long issue_date);
    void setIssueTo(int issued_to);

    void displayBook();
};