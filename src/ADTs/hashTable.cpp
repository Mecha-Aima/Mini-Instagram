#include "../../headers/ADTs/hashTable.h"
#include <stdexcept>
#include <iostream>

using namespace std;

HashTable::HashTable(int capacity)
{
    if (capacity <= 0)
    {
        throw invalid_argument("Capacity must be greater than 0");
    }
    this->capacity = capacity;
    this->size = 0;
    table = new UserPair*[capacity];
    for (int i = 0; i < capacity; i++)
    {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
    delete[] table;
}

int HashTable::hashFunction(const std::string& key) const {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % capacity;
}

void HashTable::insert(const string& username, const string& password) {
    if (size >= capacity) {
        throw std::overflow_error("Hash table is full!");
    }

    // Check if username already exists
    if (this->search(username) != "")
    {
        cout << "Username already exists" << endl;
        return;
    }

    int index = hashFunction(username);
    int originalIndex = index;
    int probeCount = 0;

    while (true) {
        if (table[index] == nullptr || table[index]->isDeleted) {
            table[index] = new UserPair(username, password);
            size++;
            return;
        }

        if (!table[index]->isDeleted && table[index]->username == username) {
            table[index]->password = password;
            return;
        }
        index = (originalIndex + ++probeCount) % capacity;
        if (probeCount >= capacity) {
            throw std::overflow_error("Hash table is full!");
        }
    }
}

void HashTable::remove(const string& username) {
    int index = hashFunction(username);
    int originalIndex = index;
    int probeCount = 0;

    while (table[index] != nullptr) {
        if (!table[index]->isDeleted && table[index]->username == username) {
            table[index]->isDeleted = true;
            size--;
            return;
        }

        index = (originalIndex + ++probeCount) % capacity;

        if (probeCount >= capacity) {
            break;
        }
    }

    throw std::runtime_error("Username not found in the hash table.");
}

string HashTable::search(const string& username) const {
    int index = hashFunction(username);
    int originalIndex = index;
    int probeCount = 0;

    while (table[index] != nullptr) {
        if (!table[index]->isDeleted && table[index]->username == username) {
            return table[index]->password;
        }

        index = (originalIndex + ++probeCount) % capacity;

        if (probeCount >= capacity) {
            break;
        }
    }

    return "";
}

void HashTable::print() const {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr && !table[i]->isDeleted) {
            std::cout << "Index " << i << ": " 
                      << "Username: " << table[i]->username 
                      << ", Password: " << table[i]->password 
                      << std::endl;
        } else {
            std::cout << "Index " << i << ": [empty/deleted]" << std::endl;
        }
    }
}

int HashTable::getSize() const { 
    return size; 
}

void HashTable::update(const std::string& username, const std::string& oldPass, const std::string& newPass)
{
    int index = hashFunction(username);
    int originalIndex = index;
    int probeCount = 0;

    while (table[index] != nullptr)
    {
        if(table[index]->username == username && !table[index]->isDeleted)
        {
            if (table[index]->password == oldPass)
            {
                table[index]->password = newPass;
            }
            else
            {
                throw std::runtime_error("Old password is incorrect");
            }
        }
        index = (originalIndex + ++probeCount) % capacity;
        if (probeCount >= capacity)
        {
            break;
        }
    }

    if (probeCount >= capacity)
    {
        throw std::runtime_error("Username not found in the hash table.");
    }
}