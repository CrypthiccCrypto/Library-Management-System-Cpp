#pragma once
#include "User.h"
#include <vector>

class UserDatabase {
    private:
    std::vector<User> users;

    public:
    UserDatabase(std::string filename);

    void addUser(User user);
    void updateUser(User user);
    void deleteUser(User user);
    void searchUser(User user);
    User* verify_login(std::string name, std::string password);
};