#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

struct UserPair {
    std::string username;
    std::string password;
    bool isDeleted;  
    
    UserPair() : isDeleted(false) {}
    UserPair(const std::string& user, const std::string& pass) 
        : username(user), password(pass), isDeleted(false) {}
};

class HashTable {
private:
    UserPair **table;  
    int size;
    int capacity;

public:
    HashTable(int capacity);
    ~HashTable();
    void insert(const std::string& username, const std::string& password);
    void remove(const std::string& username);
    void update(const std::string& username, const std::string& oldPass, const std::string& newPass);
    std::string search(const std::string& username) const;
    void print() const;
    int getSize() const;
    int hashFunction(const std::string& key) const;
};