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
    curr_id = -1;
    UserDatabase::fname = fname;

	if(file.is_open())
	{
		while(std::getline(file, line))
		{
			row.clear();
			std::stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);

            curr_id = std::max(curr_id, std::stoi(row[0]));
            User tmp(std::stoi(row[0]), row[1], row[2], row[3][0]);
            UserDatabase::users.push_back(tmp);
		}
	}
	else {
		std::cout << "Could not open the file\n";
        return;
    }

    curr_id++;
    file.close();
}

void UserDatabase::addUser(User user) {
    for(User &u : UserDatabase::users) {
        if(u.getName() == user.getName()) {
            std::cout << "Username already in use\n";
            return;
        }
    }
    
    curr_id++;
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

void UserDatabase::displayUsers() {
    int counter = 1;
    for(User &u : UserDatabase::users) {
        std::cout << counter << ". ID: " << u.getID() << " Name: " << u.getName() << " Permission: " << u.getPermission() << std::endl;
        counter++;
    }
}

void UserDatabase::updateDatabase() {
    std::ofstream outfile;
    outfile.open("tmp.dat", std::ios::trunc);

    for(User &u : UserDatabase::users) {
        int id = u.getID();
        std::string name = u.getName();
        std::string password = u.getPassword();
        char permission = u.getPermission();
        outfile << u.getID() << "," << u.getName() << "," << u.getPassword() << "," << u.getPermission() << '\n';
    }

    outfile.close();

    remove(fname.c_str());
    int result = rename("tmp.dat", fname.c_str());
    if ( result != 0 )
        std::cout << "Error, could not update database.\n" << std::endl;
}
