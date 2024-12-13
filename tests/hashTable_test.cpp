#include "../include/ADTs/hashTable.h"
using namespace std;

void testBasicInsertAndSearch() {
    cout << "\n--- Test 1: Basic Insertion and Search ---\n";
    try {
        HashTable ht(10);
        
        ht.insert("alice", "password123");
        
        string password = ht.search("alice");
        
        if (password == "password123") {
            cout << "Basic Insertion and Search: PASSED\n";
        } else {
            cout << "Basic Insertion and Search: FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Basic Insertion and Search: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testMultipleInsertionsAndSearches() {
    cout << "\n--- Test 2: Multiple Insertions and Searches ---\n";
    try {
        HashTable ht(10);
        
        // Insert multiple users
        ht.insert("alice", "pass1");
        ht.insert("bob", "pass2");
        ht.insert("charlie", "pass3");
        
        // Search for multiple users
        bool allFound = true;
        allFound &= (ht.search("alice") == "pass1");
        allFound &= (ht.search("bob") == "pass2");
        allFound &= (ht.search("charlie") == "pass3");
        
        if (allFound) {
            cout << "Multiple Insertions and Searches: PASSED\n";
        } else {
            cout << "Multiple Insertions and Searches: FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Multiple Insertions and Searches: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testCollisionHandling() {
    cout << "\n--- Test 3: Collision Handling ---\n";
    try {
        // Use a small capacity to force collisions
        HashTable ht(5);
        
        // These usernames should trigger collisions based on hash function
        ht.insert("alice", "pass1");
        ht.insert("bob", "pass2");
        ht.insert("charlie", "pass3");
        
        bool allFound = true;
        allFound &= (ht.search("alice") == "pass1");
        allFound &= (ht.search("bob") == "pass2");
        allFound &= (ht.search("charlie") == "pass3");
        
        if (allFound) {
            cout << "Collision Handling: PASSED\n";
        } else {
            cout << "Collision Handling: FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Collision Handling: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testRemoval() {
    cout << "\n--- Test 4: Removal Operation ---\n";
    try {
        HashTable ht(10);
        
        ht.insert("alice", "pass1");
        ht.insert("bob", "pass2");
        
        // Remove a user
        ht.remove("alice");
        
        // Search for removed user should return empty string
        string removedPassword = ht.search("alice");
        
        // Search for non-removed user should still work
        string bobPassword = ht.search("bob");
        
        if (removedPassword.empty() && bobPassword == "pass2") {
            cout << "Removal Operation: PASSED\n";
        } else {
            cout << "Removal Operation: FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Removal Operation: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testUpdatingEntry() {
    cout << "\n--- Test 5: Updating Existing Entry ---\n";
    try {
        HashTable ht(10);
        
        ht.insert("alice", "oldpass");
        ht.insert("alice", "newpass");
        
        string password = ht.search("alice");
        
        if (password == "newpass") {
            cout << "Updating Existing Entry: PASSED\n";
        } else {
            cout << "Updating Existing Entry: FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Updating Existing Entry: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testSizeTracking() {
    cout << "\n--- Test 6: Size Tracking ---\n";
    try {
        HashTable ht(10);
        
        ht.insert("alice", "pass1");
        ht.insert("bob", "pass2");
        ht.insert("charlie", "pass3");
        
        if (ht.getSize() == 3) {
            cout << "Size Tracking (Insertion): PASSED\n";
        } else {
            cout << "Size Tracking (Insertion): FAILED\n";
        }
        
        ht.remove("bob");
        
        if (ht.getSize() == 2) {
            cout << "Size Tracking (Removal): PASSED\n";
        } else {
            cout << "Size Tracking (Removal): FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Size Tracking: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

// Test 7: Table Overflow
void testTableOverflow() {
    cout << "\n--- Test 7: Table Overflow ---\n";
    try {
        // Create a very small hash table
        HashTable ht(3);
        
        ht.insert("user1", "pass1");
        ht.insert("user2", "pass2");
        ht.insert("user3", "pass3");
        
        // This should throw an overflow exception
        try {
            ht.insert("user4", "pass4");
            cout << "Table Overflow: FAILED (No exception thrown)\n";
        } catch (const overflow_error& e) {
            cout << "Table Overflow: PASSED\n";
        }
    } catch (const exception& e) {
        cout << "Table Overflow Test Setup: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testRemovalOfNonExistentEntry() {
    cout << "\n--- Test 8: Removal of Non-Existent Entry ---\n";
    try {
        HashTable ht(10);
        
        // Try to remove a non-existent user
        try {
            ht.remove("nonexistent");
            cout << "Removal of Non-Existent Entry: FAILED (No exception thrown)\n";
        } catch (const runtime_error& e) {
            cout << "Removal of Non-Existent Entry: PASSED\n";
        }
    } catch (const exception& e) {
        cout << "Removal of Non-Existent Entry Test: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testSearchForNonExistentEntry() {
    cout << "\n--- Test 9: Search for Non-Existent Entry ---\n";
    try {
        HashTable ht(10);
        
        string password = ht.search("nonexistent");
        
        if (password.empty()) {
            cout << "Search for Non-Existent Entry: PASSED\n";
        } else {
            cout << "Search for Non-Existent Entry: FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Search for Non-Existent Entry: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

void testMultipleRemovalsAndInsertions() {
    cout << "\n--- Test 10: Multiple Removals and Insertions ---\n";
    try {
        HashTable ht(10);
        
        ht.insert("alice", "pass1");
        ht.insert("bob", "pass2");
        ht.insert("charlie", "pass3");
        
        ht.remove("bob");
        
        ht.insert("david", "pass4");
        
        bool allCorrect = true;
        allCorrect &= (ht.search("alice") == "pass1");
        allCorrect &= (ht.search("bob").empty());
        allCorrect &= (ht.search("charlie") == "pass3");
        allCorrect &= (ht.search("david") == "pass4");
        
        if (allCorrect) {
            cout << "Multiple Removals and Insertions: PASSED\n";
        } else {
            cout << "Multiple Removals and Insertions: FAILED\n";
        }
    } catch (const exception& e) {
        cout << "Multiple Removals and Insertions: FAILED\n";
        cout << "Exception: " << e.what() << endl;
    }
}

int main()
{
    testBasicInsertAndSearch();
    testMultipleInsertionsAndSearches();
    testCollisionHandling();
    testRemoval();
    testUpdatingEntry();
    testSizeTracking();
    testTableOverflow();
    testRemovalOfNonExistentEntry();
    testSearchForNonExistentEntry();
    testMultipleRemovalsAndInsertions();

    return 0;
}