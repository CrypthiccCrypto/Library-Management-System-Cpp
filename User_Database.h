#pragma once
#include "User.h"
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
    void searchUser(User user);
    void displayUsers();

    void updateDatabase();
    User* verify_login(std::string name, std::string password);
};