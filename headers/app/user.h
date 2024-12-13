#pragma once
#include <string>
#include <chrono>
#include <ctime>  
#include <sstream>  
#include <iomanip>
#include <stdexcept>
#include "../../headers/ADTs/linked_list.h"
#include "message.h"
#include "friend_requests.h"

class UserGraph;
class AdminUser;

class Post {
public:
    string owner;
    string content;
    string timestamp;
    Post(string owner, const string& content);
    friend ostream& operator<<(ostream& os, const Post& post);
};

class User {
    friend class UserGraph;
    friend class AdminUser;
protected:
    string username;
    string password;
    string city;
    string last_login;
    Stack<Post> posts;

    LinkedList<User*> followed;
    Stack<Post> followed_posts;

    Messages messages;
    realTimeMessages unreadMessages;
    FriendRequests friendRequests;
    LinkedList<User *> friends;

    Queue<string> notifications;

public:
    User(string username, string password, string city);
    virtual ~User();
    User(const User& other);
    bool isEmpty() const;
    void setUsername(string username);
    void setPassword(string password);
    void setCity(string city);
    string getUsername() const;
    string getCity() const;
    string getLastLogin() const;
    Stack<Post> getPosts() const;
    void updateLastLogin();
    void addFriend(User *user);
    void removeFriend(User *user);
    void removeFollowedUser(User *user);
    void listFollowers() const;
    void listFriends() const;

    User& operator=(const User& other);
    bool operator<(const User& other) const;
    // Posts
    void addPost(const string &content);
    void follow(User* user);
    void newsFeed();
    void refreshFeed();
    // Messaging
    Messages& getMessages();
    void sendMessage(const string& content, User *receiver);
    void openInbox(); // view unread messages
    Message peekInbox();
    // Friend requests
    void addRequest(FriendRequest *fr);
    void sendFriendRequest(User* user);
    void processRequests();
    void showRequests();
    FriendRequest* getRequest(User *user);
    // Notifications
    void receiveNotification(User *receiver, const string& content);
    void showNotifications() const;

    friend ostream& operator<<(ostream& os, const User& user);
};