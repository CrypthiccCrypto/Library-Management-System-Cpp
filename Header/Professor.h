#pragma once
#include "User.h"
#include "Book.h"
#include "Book_Database.h"

class Professor : public User {
    private:
    BookDatabase *bdb;

    public:
    Professor(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, BookDatabase *bdb);
    void displayIssuedBooks();
    void doActivity();
};