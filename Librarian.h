#pragma once
#include "User.h"
#include "Book.h"
#include "User_Database.h"

class Librarian : public User {
    private:
    UserDatabase *udb;

    public:
    Librarian(int ID, std::string name, std::string password, char permission, UserDatabase *udb);
    void doActivity();
};