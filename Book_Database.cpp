#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "Book_Database.h"

BookDatabase::BookDatabase(std::string fname) {
	std::vector<std::string> row;
	std::string line, word;
    std::fstream file (fname, std::ios::in);

	if(file.is_open())
	{
		while(std::getline(file, line))
		{
			row.clear();
			std::stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);

			Book tmp(row[0], row[1], row[2], row[3]);
            BookDatabase::books.push_back(tmp);
		}
	}
	else {
		std::cout << "Could not open the file\n";
        return;
    }

    file.close();
}

void BookDatabase::addBook(Book book) {
    for(Book b : BookDatabase::books) {
        if(b.getISBN() == book.getISBN()) {
            std::cout << "Book already exists\n";
            return;
        }
    }

    BookDatabase::books.push_back(book);
}

void BookDatabase::deleteBook(Book book) {
    for(auto it = BookDatabase::books.begin(); it != BookDatabase::books.end(); it++) {
        if(it->getISBN() == book.getISBN()) {
            BookDatabase::books.erase(it);
            return;
        }
    }   

    std::cout << "Book does not exist\n";
}

void BookDatabase::searchBook(Book book) {
    for(Book b : BookDatabase::books) {
        if(b.getISBN() == book.getISBN()) {
            std::cout << "Book found\n";
            return;
        }
    }

    std::cout << "Book not found\n";
}