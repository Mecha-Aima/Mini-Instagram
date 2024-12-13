#include "../../headers/app/friend_requests.h"
#include "../../headers/app/user.h"
using namespace std;

FriendRequest::FriendRequest(string sender, string receiver, string status)
{
    this->sender = sender;
    this->receiver = receiver;
    if (!setStatus(status))
    {
        this->status = "pending";
    }
}

bool FriendRequest::setStatus(std::string st)
{
    if (st == "pending" || st == "accepted" || st == "declined")
    {
        this->status = st;
        return true;
    }
    cout << "Invalid status" << endl;
    return false;
}

FriendRequests::FriendRequests() {}

void FriendRequests::deepCopy(const FriendRequests& other) {
    for (int i = 0; i < other.fr.getSize(); i++) {
        FriendRequest* originalRequest = other.fr[i];
        // Create a new FriendRequest with the same data
        FriendRequest* newRequest = new FriendRequest(
            originalRequest->sender, 
            originalRequest->receiver, 
            originalRequest->status
        );
        this->fr.enqueue(newRequest);
    }
}

FriendRequests::FriendRequests(const FriendRequests& other)
{
    this->deepCopy(other);
}

void FriendRequests::cleanup() {
    while (!fr.isEmpty()) {
        FriendRequest* request = fr.dequeue();
        delete request;
    }
}

FriendRequests::~FriendRequests() {
   this->cleanup();
}

FriendRequests& FriendRequests::operator=(const FriendRequests& other)
{
    if (this != &other) {
        cleanup();
        deepCopy(other);
    }
    return *this;
}

void FriendRequests::addRequest(FriendRequest *fr)
{
    if (fr->status == "pending" || fr->status == "accepted" || fr->status == "declined")
        this->fr.enqueue(fr);
    else
        delete fr;
}

void FriendRequests::processRequests()
{
    if (this->fr.isEmpty())
    {
        cout << "No friend requests to process" << endl;
        return;
    }
    while (!this->fr.isEmpty())
    {
        FriendRequest *request = this->fr.dequeue();
        if (request->status == "pending")
        {
            cout << "\nFriend request from " << request->sender << " to " << request->receiver << " is pending" << endl;
            int choice;
            cout << "1. Accept\n2. Decline\nEnter your choice: " << endl;
            cin >> choice;
            if (choice == 1)
            {
                request->setStatus("accepted");
                
            }
            else if (choice == 2)
            {
                request->setStatus("declined");
            }
            else
            {
                cout << "Request ignored" << endl;
            }

        }
        else if (request->status == "accepted")
        {
            cout << "Friend request from " << request->sender << " to " << request->receiver << " is accepted" << endl;
        }
        else if (request->status == "declined")
        {
            cout << "Friend request from " << request->sender << " to " << request->receiver << " is declined" << endl;
        }
        delete request;
    }
}

void FriendRequests::showRequests()
{
    if (this->fr.isEmpty())
    {
        cout << "No friend requests to display" << endl;
        return;
    }
    QueueNode<FriendRequest *> *current = fr.getFront();
    while (current != nullptr)
    {
        cout << *current->data << endl;
        current = current->next;
    }
}

ostream& operator<<(ostream& os, const FriendRequest& fr)
{
    os << "Sender: " << fr.sender << endl;
    os << "Receiver: " << fr.receiver << endl;
    os << "Status: " << fr.status << endl;
    cout << setw(50) << setfill('=') << "" << "\n" << setfill(' ');
    return os;
}

bool FriendRequests::isEmpty() const
{
    return this->fr.isEmpty();
}

FriendRequest *FriendRequests::getOldestRequest() const
{
    return this->fr.peek();
}

