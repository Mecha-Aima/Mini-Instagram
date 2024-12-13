#include "../include/app/message.h"  
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    Messages chat;
    
    cout << "Sending messages between users..." << endl;
    chat.sendMessage("Alice", "Bob", "Hello Bob, how are you?");
    chat.sendMessage("Bob", "Alice", "Hi Alice, I'm good. How about you?");
    chat.sendMessage("Alice", "Charlie", "Hey Charlie, want to hang out?");
    chat.printMessages();

    cout << "\nLatest Message: " << endl;
    Message latest = chat.getLatestMessage();
    cout << latest;

    Messages emptyChat;
    cout << "\nChecking empty Messages..." << endl;
    if (emptyChat.isEmpty()) {
        cout << "No messages in the chat yet." << endl;
    } else {
        cout << "There are messages in the chat." << endl;
    }

    try {
        cout << "\nTrying to access latest message from empty chat..." << endl;
        Message emptyLatest = emptyChat.getLatestMessage();  
        cout << emptyLatest;
    } catch (const exception& e) {
        cout << "Error: Cannot retrieve message. " << e.what() << endl;
    }

    cout << "\nEditing a message..." << endl;
    latest.editMessage("Hi Charlie, want to join us for a game of chess?");
    cout << latest;  

    cout << "\nSending an empty message..." << endl;
    chat.sendMessage("Bob", "Charlie", "");  
    chat.printMessages();  

    string longMessage(1000, 'x');  
    cout << "\nSending a very long message..." << endl;
    chat.sendMessage("Charlie", "Alice", longMessage);  
    chat.printMessages();  

    cout << "\nClearing messages..." << endl;
    chat.clearMessages();
    if (chat.isEmpty()) {
        cout << "Chat is now empty." << endl;
    }

    return 0;
}
