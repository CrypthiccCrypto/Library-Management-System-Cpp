#pragma once
#include "Book.h"
#include <vector>

class User {
    protected:
    std::string name;
    int ID;
    std::string password;
    char permission;
    std::string USER_MENU;

    public:
    User(int ID, std::string name, std::string password, char permission);

    std::string getName();
    int getID();
    std::string getPassword();
    char getPermission();

    void setName(std::string name);
    void setID(int ID);
    void setPassword(std::string password);
    void setPermission(char permission);
    
    virtual void doActivity();
};