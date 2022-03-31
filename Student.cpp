#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "User.h"
#include "Book_Database.h"
#include "Student.h"

Student::Student(int ID, std::string name, std::string password, char permission, std::vector<std::string> isbns, BookDatabase *bdb) : User(ID, name, password, permission, isbns) {
    Student::bdb = bdb;
    max_books = 5;
}

void Student::displayIssuedBooks() {
    for(auto s : isbns) {
        Book* tmp = bdb -> searchBook(s, false);
        tmp -> displayBook();
    }
}

void Student::doActivity() {
    return;
}