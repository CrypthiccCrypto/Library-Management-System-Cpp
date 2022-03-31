#pragma once
#include "User.h"
#include "Book.h"
#include "User_Database.h"

class Librarian : public User {
    private:
    UserDatabase *udb;
    BookDatabase *bdb;

    public:
    Librarian(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, UserDatabase *udb, BookDatabase *bdb);
    void doActivity();
};