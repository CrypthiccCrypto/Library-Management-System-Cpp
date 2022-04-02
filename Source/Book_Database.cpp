#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>
#include "../Header/Book.h"
#include "../Header/Book_Database.h"

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
            
            int to = -1;
            if(stoi(row[4]) != -1) { to = stoi(row[5]); }
			Book tmp(row[0], row[1], row[2], row[3], stoi(row[4]), to);
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

Book* BookDatabase::searchBook(std::string ISBN, bool listing) {
    for(Book &b : BookDatabase::books) {
        if(b.getISBN() == ISBN) {
            if(listing) std::cout << "Book found\n";
            return &b;
        }
    }

    if(listing) std::cout << "Book not found\n";
    return nullptr;
}

void BookDatabase::checkAvailable(std::string name) {
    for(Book &b : BookDatabase::books) {
        if(b.getTitle() == name && b.getDueDate() == -1) {
            std::cout << "Book available! ISBN of book is: " << b.getISBN() << std::endl;
            return;
        }
    }
    std::cout << "Sorry, the book is not available." << std::endl;
}

void BookDatabase::displayBooks() {
    for(Book b : BookDatabase::books) { b.displayBook(); }
}

void BookDatabase::displayIssuedBooks() {
    for(Book b : BookDatabase::books) {
        if(b.getDueDate() != -1) {
            b.displayBook();
        }
    }
}

void BookDatabase::updateBookDatabase() {
    std::ofstream outfile;
    outfile.open("tmp.dat", std::ios::trunc);

    for(Book &b : BookDatabase::books) {
        outfile << b.getTitle() << "," << b.getAuthor() << "," << b.getISBN() << "," << b.getPublication() << "," << b.getDueDate() << "," << b.getIssuedTo() << '\n';
    }

    outfile.close();

    remove(fname.c_str());
    int result = rename("tmp.dat", fname.c_str());
    if ( result != 0 )
        std::cout << "Error, could not update database.\n" << std::endl;
}