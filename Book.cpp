#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "Book_Database.h"

const char* BOOK_FORMAT_OUT = "%s,%s,%s,%s\n";

Book::Book(std::string title, std::string author, std::string ISBN, std::string publication) {
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->publication = publication;
}

std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getISBN() { return ISBN; }
std::string Book::getPublication() { return publication; }

// int main() {
//     Book b1 = {
//         "The C++ Programming Language",
//         "Bjarne Stroustrup",
//         "978-0-321-56384-2",
//         "Addison-Wesley Professional"
//     };

//     FILE* file;
//     file = fopen("book_db.dat", "w");
//     if (file == NULL) {
//         return 1;
//     }

//     fprintf(file, BOOK_FORMAT_OUT, b1.getTitle().c_str(), b1.getAuthor().c_str(), b1.getISBN().c_str(), b1.getPublication().c_str());
//     fclose(file);

//     string fname = "book_db.dat";
 
// 	vector<vector<string>> content;
// 	vector<string> row;
// 	string line, word;
 
// 	fstream fiile (fname, ios::in);
// 	if(fiile.is_open())
// 	{
// 		while(getline(fiile, line))
// 		{
// 			row.clear();
 
// 			stringstream str(line);
 
// 			while(getline(str, word, ','))
// 				row.push_back(word);
// 			content.push_back(row);
// 		}
// 	}
// 	else
// 		cout<<"Could not open the fiile\n";
 
// 	for(int i=0;i<content.size();i++)
// 	{
// 		Book tmp(content[i][0], content[i][1], content[i][2], content[i][3]);
//         cout << tmp.getAuthor() << " " << tmp.getISBN() << " " << tmp.getPublication() << " " << tmp.getTitle() << endl;
// 	}
 
// 	return 0;

//     return 0;
// }