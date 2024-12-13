#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "../ADTs/graph.h"
#include "../../src/ADTs/graph.cpp"
#include "../app/user_tree.h"
#include "../app/user.h"
#include "../ADTs/hashTable.h"

class AdminUser;

class UserGraph: public Graph<User *> {
    friend class AdminUser;
private:
    UserTree user_tree;
    HashTable *user_lookup;
    LinkedList<User *> users;
public:
    UserGraph();
    ~UserGraph();
    // Users
    void addUser(string username, string password, string city);
    void addUser(User* user);
    void removeUser(string username);
    User* searchUser(string username);
    bool authenticateLogin(string username, string password);
    // Friend Requests
    void sendRequest(User *sender, User *receiver);
    void acceptRequest(User *sender, User *receiver);
    void rejectRequest(User *sender, User *receiver);
    void sendFollowRequest(User *sender, User *receiver);
    Vertex<User*>* getFirstUser();
    // Messages
    void sendMessage(User *sender, User *receiver, string content);
};