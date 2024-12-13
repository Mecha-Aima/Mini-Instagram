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
    Stack<Post> getFollowedPosts() const;
    void updateLastLogin();
    void addFriend(User *user);
    void removeFriend(User *user);
    void removeFollowedUser(User *user);
    ListNode<User*>* listFollowed() const;
    ListNode<User*>* listFriends() const;

    User& operator=(const User& other);
    bool operator<(const User& other) const;
        void addPost(const string &content);
    void follow(User* user);
    void newsFeed();
    void refreshFeed();
        Messages& getMessages();
    void sendMessage(const string& content, User *receiver);
    void openInbox();     Message peekInbox();
        void addRequest(FriendRequest *fr);
    void sendFriendRequest(User* user);
    void processRequests();
    void showRequests();
    FriendRequest* getRequest(User *user);
        void receiveNotification(User *receiver, const string& content);
    Queue<string> getNotifications() const;

    friend ostream& operator<<(ostream& os, const User& user);
};