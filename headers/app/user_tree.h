#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "../ADTs/AVLTree.h"
#include "../../src/ADTs/AVLTree.cpp"
#include "../app/user.h"

class UserTree : public AVLTree<User *> {
private:
    void insert(TreeVertex<User*>*& node, User* val);
public:
    UserTree();
    void insertUser(User *user);
    void removeUser(const std::string &username);
    void removeUser(User *userToRemove);
    bool containsUser(const std::string& username);
    User* find(const std::string& username);
    void printUsers() const;
};