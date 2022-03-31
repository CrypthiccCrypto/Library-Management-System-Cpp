#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "Book_Database.h"
#include "User.h"
#include "User_Database.h"

UserDatabase::UserDatabase(std::string fname) {
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

            User tmp(std::stoi(row[0]), row[1], row[2], row[3][0]);
            UserDatabase::users.push_back(tmp);
		}
	}
	else {
		std::cout << "Could not open the file\n";
        return;
    }

    file.close();
}

void UserDatabase::addUser(User user) {
    for(User &u : UserDatabase::users) {
        if(u.getName() == user.getName()) {
            std::cout << "Username already in use\n";
            return;
        }
    }

    UserDatabase::users.push_back(user);
}

void UserDatabase::deleteUser(User user) {
    for(auto it = UserDatabase::users.begin(); it != UserDatabase::users.end(); it++) {
        if(it->getID() == user.getID()) {
            UserDatabase::users.erase(it);
            return;
        }
    }   

    std::cout << "User does not exist\n";
}

void UserDatabase::searchUser(User user) {
    for(User &u : UserDatabase::users) {
        if(u.getID() == user.getID()) {
            std::cout << "Username: " << u.getName() << "\n";
            return;
        }
    }

    std::cout << "User not found\n";
}

User* UserDatabase::verify_login(std::string name, std::string password) {
    for(User &u : UserDatabase::users) {
        if(u.getName() == name && u.getPassword() == password) {
            return &u;
        }
    }

    return nullptr;
}
