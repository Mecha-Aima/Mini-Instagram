#include "../include/app/friend_requests.h"  
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    FriendRequests requestManager;

    
    cout << "Adding basic friend requests..." << endl;
    FriendRequest* req1 = new FriendRequest("Alice", "Bob", "pending");
    FriendRequest* req2 = new FriendRequest("Charlie", "David", "pending");
    FriendRequest* req3 = new FriendRequest("Eve", "Frank", "accepted");

    requestManager.addRequest(req1);
    requestManager.addRequest(req2);
    requestManager.addRequest(req3);

    cout << "\nDisplaying all friend requests:" << endl;
    requestManager.showRequests();  

    requestManager.processRequests();

    cout << "\nAdding a request with invalid status..." << endl;
    FriendRequest* invalidRequest = new FriendRequest("Grace", "Heidi", "unknown_status");  
    requestManager.addRequest(invalidRequest);
    cout << "Displaying invalid request:" << endl;
    cout << *invalidRequest;

    
    FriendRequests emptyManager;
    cout << "\nAttempting to process empty requests queue..." << endl;
    emptyManager.processRequests();

    
    cout << "\nReprocessing the same queue after all requests are handled..." << endl;
    requestManager.processRequests();  

    
    cout << "\nAdding a friend request with very long sender and receiver names..." << endl;
    FriendRequest* longNamesRequest = new FriendRequest(string(100, 'X'), string(100, 'Y'), "pending");
    requestManager.addRequest(longNamesRequest);
    requestManager.showRequests();

    delete req1;
    delete req2;
    delete req3;
    delete invalidRequest;
    delete longNamesRequest;
    return 0;
}
