#pragma once
#include "Book.h"
#include <vector>

class User {
    protected:
    std::string name;
    int ID;
    std::string password;
    char permission;
    std::string USER_MENU;
    std::vector<std::string> isbns;
    int max_books;

    public:
    User(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns);

    std::string getName();
    int getID();
    std::string getPassword();
    char getPermission();
    std::vector<std::string> getISBNS();

    void setName(std::string name);
    void setID(int ID);
    void setPassword(std::string password);
    void setPermission(char permission);

    virtual void doActivity();
};