#pragma once
#include "User.h"
#include "Book.h"
#include <vector>

class UserDatabase {
    private:
    std::vector<User> users;

    public:
    int curr_id;
    std::string fname;
    UserDatabase(std::string filename);

    void addUser(User user);
    void updateUser(User user);
    void deleteUser(int id);
    User* searchUser(int id);
    void displayUsers();

    void updateDatabase();
    User* verify_login(std::string name, std::string password);
};