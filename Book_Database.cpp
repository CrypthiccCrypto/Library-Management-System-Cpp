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
    BookDatabase::fname = fname;

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

void BookDatabase::deleteBook(std::string ISBN) {
    for(auto it = BookDatabase::books.begin(); it != BookDatabase::books.end(); it++) {
        if(it->getISBN() == ISBN) {
            std::cout << "Book removed successfully.\n";
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

void BookDatabase::displayBooks() {
    for(Book b : BookDatabase::books) {
        std::cout << "ISBN: " << b.getISBN() << "\n";
        std::cout << "Title: " << b.getTitle() << "\n";
        std::cout << "Author: " << b.getAuthor() << "\n";
        std::cout << "Publisher: " << b.getPublication() << "\n";
        std::cout << "---------------------------------\n";
    }
}

void BookDatabase::updateBookDatabase() {
    std::ofstream outfile;
    outfile.open("tmp.dat", std::ios::trunc);

    for(Book &b : BookDatabase::books) {
        outfile << b.getTitle() << "," << b.getAuthor() << "," << b.getISBN() << "," << b.getPublication() << '\n';
    }

    outfile.close();

    remove(fname.c_str());
    int result = rename("tmp.dat", fname.c_str());
    if ( result != 0 )
        std::cout << "Error, could not update database.\n" << std::endl;
}