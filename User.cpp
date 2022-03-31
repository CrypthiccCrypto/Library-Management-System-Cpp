#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "User.h"

User::User(int ID, std::string name, std::string password, char permission) {
    this->name = name;
    this->ID = ID;
    this->password = password;
    this->permission = permission;
}

std::string User::getName() { return User::name; }
int User::getID() { return User::ID; }
std::string User::getPassword() { return User::password; }
char User::getPermission() { return User::permission; }

void User::setName(std::string name) { User::name = name; }
void User::setID(int ID) { User::ID = ID; }
void User::setPassword(std::string password) { User::password = password; }
void User::setPermission(char permission) { User::permission = permission; }