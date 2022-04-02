#pragma once
#include "User.h"
#include "Book.h"
#include "Book_Database.h"

class Student : public User {
    private:
    BookDatabase *bdb;
    int Fine_amount;    

    public:
    Student(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, BookDatabase *bdb);
    void displayIssuedBooks();
    int Calculate_fine(int due_date);
    void Clear_fine_amount(int payment);
    void doActivity();
};