#pragma once
#include <string>

class Book {
    private:
    std::string title;
    std::string author;
    std::string ISBN;
    std::string publication;
    long long issue_date;

    public:
    Book(std::string title, std::string author, std::string ISBN, std::string publication, long long issue_date);
    std::string getTitle();
    std::string getAuthor();
    std::string getISBN();
    std::string getPublication();
    long long getIssueDate();

    void setIssueDate(long long issue_date);

    void displayBook();
};