#pragma once
#include "Book.h"
#include <vector>

class BookDatabase {
    private:
    std::vector<Book> books;

    public:
    std::string fname;
    BookDatabase(std::string filename);

    void addBook(Book book);
    void updateBook(Book book);
    void deleteBook(std::string ISBN);
    Book* searchBook(std::string ISBN, bool listing);
    void checkAvailable(std::string name);

    void displayBooks();
    void displayIssuedBooks();
    void updateBookDatabase();
};