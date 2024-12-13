#include <iostream>
#include <stdexcept>
#include "../include/app/user.h"

using namespace std;

// Helper function to test user creation and related attributes
void testUserCreation() {
    cout << "===== Test User Creation =====" << endl;

    try {
        User user1("user1", "pass*worD123", "CityA");
        User user2("user2", "passwordA246", "CityB");

        cout << user1 << endl;
        cout << user2 << endl;

        user1.updateLastLogin();
        cout << "Updated last login for user1: " << user1.getLastLogin() << endl;
        
        User emptyUser("", "", "");
        cout << "Is emptyUser empty? " << (emptyUser.isEmpty() ? "Yes" : "No") << endl;

        cout << "===== User Creation Tests Passed =====\n" << endl;
    } catch (const exception &e) {
        cout << "Test failed: " << e.what() << endl;
    }
}

// Helper function to test adding posts
void testPosts() {
    cout << "===== Test Posts =====" << endl;

    try {
        User user("user1", "passw^orD123", "CityA");

        // Test adding posts
        user.addPost("First post from user1!");
        user.addPost("Second post from user1!");
        user.addPost("Third post from user1!");

        // Test news feed
        cout << "News feed for user1:" << endl;
        user.newsFeed();

        cout << "===== Post Tests Passed =====\n" << endl;
    } catch (const exception &e) {
        cout << "Test failed: " << e.what() << endl;
    }
}

// Helper function to test followers and friends
void testFollowersAndFriends() {
    cout << "===== Test Followers and Friends =====" << endl;

    try {
        User user1("user1", "paSsword#123", "CityA");
        User user2("user2", "pAssword_246", "CityB");
        User user3("user3", "Password369.", "CityC");

        // Test followers
        user1.follow(&user2);
        user1.follow(&user3);

        cout << "User1 follows:" << endl;
        user1.listFollowers();

        // Test friends
        user1.addFriend(&user2);
        user1.addFriend(&user3);

        cout << "Friends of user1:" << endl;
        user1.listFriends();

        // Test removing a friend
        user1.removeFriend(&user2);
        cout << "Friends of user1 after removing user2:" << endl;
        user1.listFriends();

        cout << "===== Followers and Friends Tests Passed =====\n" << endl;
    } catch (const exception &e) {
        cout << "Test failed: " << e.what() << endl;
    }
}

// Helper function to test friend requests
void testFriendRequests() {
    cout << "===== Test Friend Requests =====" << endl;

    try {
        User user1("user1", "paSsword#123", "CityA");
        User user2("user2", "pAssword_246", "CityB");

        // Send friend request
        user1.sendFriendRequest(&user2);

        // Show requests for user2
        cout << "Friend requests for user2:" << endl;
        user2.showRequests();

        // Process requests for user2
        user2.processRequests();

        // Show updated friends list
        cout << "Friends of user2 after processing requests:" << endl;
        user2.listFriends();

        cout << "===== Friend Requests Tests Passed =====\n" << endl;
    } catch (const exception &e) {
        cout << "Test failed: " << e.what() << endl;
    }
}

// Helper function to test messaging
void testMessaging() {
    cout << "===== Test Messaging =====" << endl;

    try {
        User user1("user1", "paSsword#123", "CityA");
        User user2("user2", "pAssword_246", "CityB");

        // Send messages
        user1.sendMessage("Hello, user2!", &user2);
        user1.sendMessage("How are you?", &user2);

        // Open inbox for user2
        cout << "Inbox for user2:" << endl;
        user2.openInbox();

        // Peek inbox for user2
        cout << "Peeking inbox for user2:" << endl;
        Message message = user2.peekInbox();
        if (!message.isEmpty()) {
            cout << message << endl;
        }

        cout << "===== Messaging Tests Passed =====\n" << endl;
    } catch (const exception &e) {
        cout << "Test failed: " << e.what() << endl;
    }
}

// Helper function to test following and news feed
void testFollowingAndNewsFeed() {
    cout << "===== Test Following and News Feed =====" << endl;

    try {
        User user1("user1", "paSsword#123", "CityA");
        User user2("user2", "pAssword_246", "CityB");

        // Add posts for user2
        user2.addPost("First post from user2!");
        user2.addPost("Second post from user2!");

        // User1 follows user2
        user1.follow(&user2);
        user1.addPost("First post from user1!");

        // Refresh news feed for user1
        cout << "News feed for user1 after following user2:" << endl;
        user1.newsFeed();

        cout << "===== Following and News Feed Tests Passed =====\n" << endl;
    } catch (const exception &e) {
        cout << "Test failed: " << e.what() << endl;
    }
}

void testNotifications() {
    cout << "===== Test Notifications =====" << endl;

    try {
        User user1("user1", "paSsword#123", "CityA");
        User user2("user2", "pAssword_246", "CityB");
        User user3("user3", "Password369.", "CityC");


        // User1 follows user2
        user1.follow(&user2);
        user2.follow(&user3);

        // User1 sends a message to user2
        user1.sendMessage("Hello, user2!", &user2);

        // User3 sends request to user2
        user3.sendFriendRequest(&user2);

        // View notifications of all users
        cout << "Notifications for all users:" << endl;
        user1.showNotifications();
        user2.showNotifications();
        user3.showNotifications();

    }
    catch (const exception &e) {

    }
}

int main() {
    // Run all test cases
    testUserCreation();
    testPosts();
    testFollowersAndFriends();
    testFriendRequests();
    testMessaging();
    testFollowingAndNewsFeed();
    testNotifications();

    return 0;
}