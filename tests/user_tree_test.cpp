#include <iostream>
#include "../include/app/user_tree.h"
#include "../include/app/user.h"

using namespace std;

int main() {
    UserTree userTree;
    
    try {
        User* user1 = new User("Alice", "password123", "city");
        User* user2 = new User("Bob", "password456", "city");
        User* user3 = new User("Charlie", "password789", "city");

        cout << "Inserting users..." << endl;
        userTree.insertUser(user1);
        userTree.insertUser(user2);
        userTree.insertUser(user3);
        cout << "Users inserted successfully!" << endl;

        cout << "Attempting to insert a duplicate user..." << endl;
        try {
            userTree.insertUser(user1);  // This should throw an exception
        } catch (const invalid_argument& e) {
            cout << "Caught exception: " << e.what() << endl;
        }

        // Check if a user exists
        cout << "Checking if user 'Alice' exists: " << userTree.containsUser("Alice") << endl; // Should print 1 (true)
        cout << "Checking if user 'David' exists: " << userTree.containsUser("David") << endl; // Should print 0 (false)

        // Find a user
        cout << "Finding user 'Bob'..." << endl;
        User* foundUser = userTree.find("Bob");
        if (foundUser) {
            cout << "Found user: " << foundUser->getUsername() << endl;
        } else {
            cout << "User 'Bob' not found!" << endl;
        }

        // Attempt to find a user that doesn't exist
        cout << "Finding user 'David'..." << endl;
        foundUser = userTree.find("David");
        if (foundUser) {
            cout << "Found user: " << foundUser->getUsername() << endl;
        } else {
            cout << "User 'David' not found!" << endl;
        }

        // Print users in the tree (in-order traversal)
        cout << "Printing all users in the tree:" << endl;
        userTree.printUsers();

        // Remove a user
        cout << "Removing user 'Charlie'..." << endl;
        userTree.removeUser("Charlie");
        cout << "User 'Charlie' removed successfully!" << endl;

        // Try to remove a user that doesn't exist
        cout << "Attempting to remove non-existent user 'David'..." << endl;
        try {
            userTree.removeUser("David");  // This should throw an exception
        } catch (const invalid_argument& e) {
            cout << "Caught exception: " << e.what() << endl;
        }

        // Final check of the users
        cout << "Printing remaining users in the tree:" << endl;
        userTree.printUsers();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}
