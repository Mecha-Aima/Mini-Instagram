#include <iostream>
#include <string>
#include "../include/app/admin.h"

using namespace std;

// Helper function to test various scenarios
void testAdminUser(AdminUser &admin, UserGraph &graph) {
    cout << "===== Admin User Testing =====" << endl;

    try {
        // Test Case 1: Add New Users
        cout << "\n====== Test 1: Add New Users ======" << endl;
        admin.addNewUser("username1", "paSsword_123", "CityA");
        admin.addNewUser("username2", "pAssword_246", "CityB");
        admin.addNewUser("username3", "Password369.", "CityC");
        admin.addNewUser("username1", "My_pass452", "CityD"); // Duplicate username
        admin.addNewUser(admin.getUsername(), "password5", "CityE"); // Admin's username

        // Test Case 2: List Users
        cout << "\n====== Test 2: List Users ======" << endl;
        admin.listUsers();

        // Test Case 3: View User Information
        cout << "\n====== Test 3: View User Information ======" << endl;
        admin.viewUser("username1");
        admin.viewUser("nonexistent_user"); // Non-existent user

        // Test Case 4: Update User
        cout << "\n====== Test 4: Update User ======" << endl;
        admin.updateUser("username1", "newPassword1#", "NewCityA");
        admin.updateUser("nonexistent_user", "newPassword@X", "NewCityX"); // Non-existent user
        admin.viewUser("username1"); // Verify changes

        // Test Case 5: Remove User
        cout << "\n====== Test 5: Remove User ======" << endl;
        admin.removeUser("username2");
        admin.removeUser("nonexistent_user"); // Non-existent user
        admin.listUsers();

        // Test Case 6: Remove Friend
        cout << "\n====== Test 6: Remove Friend ======" << endl;
        // Adding some friends first
        graph.sendRequest(graph.searchUser("username1"), graph.searchUser("username3"));
        graph.acceptRequest(graph.searchUser("username1"), graph.searchUser("username3"));
        cout << "Before removing friendship:" << endl;
        admin.viewUser("username1");
        admin.viewUser("username3");
        admin.removeFriend("username1", "username3");
        admin.removeFriend("username1", "nonexistent_user"); // Non-existent friend
        cout << "After removing friendship:" << endl;
        admin.viewUser("username1");
        admin.viewUser("username3");

        // Test Case 7: Reset Password
        cout << "\n====== Test 7: Reset Password ======" << endl;
        admin.resetPassword("username1", "wrongPassword", "newPassword2"); // Incorrect old password
        admin.resetPassword("username1", "newPassword1#", "newPassword2_correct");  // Correct reset
        admin.resetPassword("nonexistent_user", "anyPassword", "newPasswordX"); // Non-existent user

        // Test Case 8: Broadcast Message
        cout << "\n======= Test 8: Broadcast Message ====== " << endl;
        admin.broadCastMessage("Hello, all users!");
        cout << "User 1's inbox: " << endl;
        User* user1 = graph.searchUser("username1");
        user1->openInbox();
        cout << "User 3's inbox: " << endl;
        User* user3 = graph.searchUser("username3");
        user3->openInbox();
        admin.broadCastMessage(""); // Empty message

        cout << "\n===== Testing Completed =====" << endl;
    } catch (const exception &e) {
        cout << "An exception occurred: " << e.what() << endl;
    }
}

int main() {
    // Initialize the user graph
    UserGraph userGraph;

    // Create an AdminUser instance
    AdminUser admin("adminUser123", "adminPass_456", "AdminCity", userGraph);

    // Test the AdminUser functionality
    testAdminUser(admin, userGraph);

    return 0;
}