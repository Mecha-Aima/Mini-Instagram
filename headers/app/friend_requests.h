#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "../ADTs/queue.h"

class FriendRequest {
public:
    std::string sender;
    std::string receiver;
    std::string status;
    FriendRequest(std::string sender, std::string receiver, std::string status);
    bool setStatus(std::string st);

    friend ostream& operator<<(std::ostream& os, const FriendRequest& fr);
    bool operator==(const FriendRequest& request);
};

class FriendRequests {
public:
    Queue<FriendRequest *> fr;
    FriendRequests();
    ~FriendRequests();
    FriendRequests(const FriendRequests& other);
    FriendRequests& operator=(const FriendRequests& other);
    bool alreadyAdded(FriendRequest* fr) const;
    void addRequest(FriendRequest *fr);
    void processRequests();
    void showRequests();
    bool isEmpty() const;
    FriendRequest *getOldestRequest() const;
private:
    void cleanup();
    void deepCopy(const FriendRequests& other);
};