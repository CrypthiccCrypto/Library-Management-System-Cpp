#pragma once
#include <vector>
#include "Book.h"

class User {
    protected:
    std::string name;
    std::string password;
    std::string USER_MENU;
    std::vector<std::string> isbns;
    int max_books;
    int fine_rate;
    int ID;
    char permission;

    public:
    User(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns);

    std::string getName();
    int getID();
    std::string getPassword();
    char getPermission();
    std::vector<std::string>* getISBNS();

    void setName(std::string name);
    void setID(int ID);
    void setPassword(std::string password);
    void setPermission(char permission);
    void setISBNS(std::vector<std::string>* isbns);
    
    void issueBook(int max_books, Book* book);
    void removeBook(Book* book);
    void returnBook(Book* book);
    int calculateFees(int due_date);

    virtual void doActivity();
};