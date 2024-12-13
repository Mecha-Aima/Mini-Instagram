#include <iostream>
#include "../include/app/user.h"
#include "../include/app/users_graph.h"

using namespace std;

void testAddUser(UserGraph &graph) {
    cout << "\n==== Test: Add Users ====\n";
    try {
        graph.addUser("Alice", "Alice123%", "New York");
        graph.addUser("Bob", "Bobby_123", "Los Angeles");
        graph.addUser("Charlie", "Charlie@123", "Chicago");

        // Edge case: Adding duplicate user
        graph.addUser("Alice", "dUplicate_123", "Miami");
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Test login functionality
void testLogin(UserGraph &graph) {
    cout << "\n==== Test: User Login ====\n";
    try {
        // Valid login
        bool success = graph.authenticateLogin("Alice", "Alice123%");
        cout << "Login Alice (valid): " << (success ? "Success" : "Failed") << endl;

        // Invalid login (wrong password)
        success = graph.authenticateLogin("Alice", "wrongpass");
        cout << "Login Alice (invalid): " << (success ? "Success" : "Failed") << endl;

        // Non-existent user
        success = graph.authenticateLogin("NonExistent", "noUser");
        cout << "Login NonExistent: " << (success ? "Success" : "Failed") << endl;
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Test friend requests functionality
void testFriendRequests(UserGraph &graph) {
    cout << "\n==== Test: Friend Requests ====\n";
    try {
        User *alice = graph.searchUser("Alice");
        User *bob = graph.searchUser("Bob");

        // Sending friend request
        graph.sendRequest(alice, bob);
        cout << "Sent friend request from Alice to Bob.\n";

        // Accepting friend request
        graph.acceptRequest(alice, bob);
        cout << "Bob accepted Alice's friend request.\n";
        cout << "Bob's Friends: \n";
        bob->listFriends();

        // Edge case: Sending request to non-existent user
        try {
            User *nonExistent = graph.searchUser("FakeUser");
            graph.sendRequest(alice, nonExistent);
        } catch (const std::exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Test messaging functionality
void testMessages(UserGraph &graph) {
    cout << "\n==== Test: Messaging System ====\n";
    try {
        User *alice = graph.searchUser("Alice");
        User *bob = graph.searchUser("Bob");

        // Sending a message from Alice to Bob
        graph.sendMessage(alice, bob, "Hello, Bob!");
        cout << "Alice sent a message to Bob.\n";

        // Bob views the inbox
        cout << "Bob's Inbox: \n";
        bob->openInbox();

        // Edge case: Sending message to non-existent user
        try {
            User *nonExistent = graph.searchUser("FakeUser");
            graph.sendMessage(alice, nonExistent, "Hello, ghost!");
        } catch (const std::exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Test post management system
void testPostManagement(UserGraph &graph) {
    cout << "\n==== Test: Post Management ====\n";
    try {
        User *alice = graph.searchUser("Alice");

        // Alice adds a post
        alice->addPost("This is Alice's first post!");
        alice->addPost("Alice's second post.");

        // Alice's newsfeed
        cout << "Alice's Newsfeed:\n";
        alice->newsFeed();

        // Edge case: No posts yet for a new user
        User *charlie = graph.searchUser("Charlie");
        cout << "Charlie's Newsfeed:\n";
        charlie->newsFeed();  // Should show nothing
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void testRemovingUser(UserGraph &graph) {
    cout << "\n==== Test: Removing User ====\n";
    User *alice = graph.searchUser("Alice");
    User *bob = graph.searchUser("Bob");
    User *charlie = graph.searchUser("Charlie");

    alice->addFriend(bob);
    alice->addFriend(charlie);
    cout << "ALice's Friends: \n";
    alice->listFriends();

    bob->follow(charlie);
    bob->follow(alice);
    graph.removeUser("Charlie");

    cout << "Alice's Friends after removing Charlie: \n";
    alice->listFriends();
    cout << "Bob's Followers: \n";
    bob->listFollowers();

}

int main() {
    UserGraph userGraph;

    // Test adding and logging in users
    testAddUser(userGraph);
    testLogin(userGraph);

    // Test friend request features
    testFriendRequests(userGraph);

    // Test messaging system
    testMessages(userGraph);

    // Test post management
    testPostManagement(userGraph);

    cout << "\n\n";
    testRemovingUser(userGraph);

    return 0;
}
