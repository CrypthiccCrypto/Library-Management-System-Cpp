#pragma once
#include "Book.h"
#include <vector>

class BookDatabase {
    private:
    std::vector<Book> books;

    public:
    BookDatabase(std::string filename);
    //~BookDatabase();

    void addBook(Book book);
    void updateBook(Book book);
    void deleteBook(Book book);
    void searchBook(Book book);
};