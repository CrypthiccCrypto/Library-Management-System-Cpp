#pragma once
#include "User.h"
#include "Book.h"
#include "Book_Database.h"

class Student : public User {
    private:
    BookDatabase *bdb;
    int max_books;

    public:
    Student(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, BookDatabase *bdb);
    void displayIssuedBooks();
    void doActivity();
};