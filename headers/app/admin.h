#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>
#include "users_graph.h"
#include "user.h"
using namespace std;

class AdminUser : public User {
    private:
    UserGraph& user_graph; public:
    AdminUser(string username, string password, string city, UserGraph& graph);
    void addNewUser(string username, string password, string city);
    void removeUser(string username);
    void updateUser(string username, string newPassword, string newCity);
    void listUsers() const;
    void viewUser(string username) const;
    void removeFriend(string username, string friendUsername);
    void resetPassword(string username,string oldPassword, string newPassword);
    void broadCastMessage(const string &content);

};