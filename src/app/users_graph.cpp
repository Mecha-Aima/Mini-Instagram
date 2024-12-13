#include "../../headers/app/users_graph.h"
using namespace std;

UserGraph::UserGraph() {
    this->user_lookup = new HashTable(100); // max users
}

UserGraph::~UserGraph() {
    ListNode<User *> *current = this->users.getHead();
    while (current != nullptr)
    {
        User *user = current->data;
        current = current->next;
        delete user;
    }
    delete user_lookup;
    user_lookup = nullptr;
}

void UserGraph::addUser(User* user)
{
    if (this->user_tree.containsUser(user->username))
    {
        cout << "User already exists" << endl;
        delete user;
        return;
    }
    this->users.add(user);
    this->user_lookup->insert(user->username, user->password); // Add to lookup
    this->user_tree.insertUser(user); // Add to search tree
    this->add(user); // Add to graph
}

void UserGraph::addUser(string username, string password, string city)
{
    User *user = new User(username, password, city);
    if (user->isEmpty())
    {
        cout << "Username cannot be empty" << endl;
        delete user;
        return;
    }
    if (this->user_tree.containsUser(username))
    {
        cout << "User already exists" << endl;
        delete user;
        return;
    }
    this->users.add(user);
    this->user_lookup->insert(user->username, user->password); // Add to lookup
    this->user_tree.insertUser(user); // Add to search tree
    this->add(user); // Add to graph
}

void UserGraph::removeUser(string username)
{
    User *user = this->user_tree.find(username);
    if (user == nullptr)
    {
        cout << "User does not exist" << endl;
        return;
    }
    // Remove user from friends' lists
    Vertex<User *> *current = this->getVertex(user);
    AdjListNode<User *> *adj = current->head;
    while (adj)
    {
        adj->data->removeFriend(user);
        adj = adj->next;
    }
    // Remove user from followed list of other users
    current = this->head;
    while (current)
    {
        if (current->value == user || current->value->followed.contains(user))
        {
            current->value->followed.remove(user);
        }
        current = current->nextVertex;
    }
    this->remove(user);
    this->users.remove(user);
    this->user_lookup->remove(username);
    this->user_tree.removeUser(user);
    delete user;
}

void UserGraph::sendRequest(User *sender, User *receiver)
{
    if (sender == nullptr || receiver == nullptr)
    {
        cout << "Invalid user" << endl;
        return;
    }
    else if (sender == receiver)
    {
        cout << "You cannot send a friend request to yourself" << endl;
        return;
    }
    sender->sendFriendRequest(receiver);
}

void UserGraph::acceptRequest(User *sender, User *receiver)
{
    if (sender == nullptr || receiver == nullptr)
    {
        cout << "Invalid user" << endl;
        return;
    }
    FriendRequest *fr = receiver->getRequest(sender);
    if (fr)
    {
        fr->setStatus("accepted");
        sender->addFriend(receiver);
        receiver->addFriend(sender);
        this->addEdge(sender, receiver);
    }
    else
    {
        cout << "Friend request does not exist" << endl;
    }
}

void UserGraph::rejectRequest(User *sender, User *receiver)
{
    if (sender == nullptr || receiver == nullptr)
    {
        cout << "Invalid user" << endl;
        return;
    }
    FriendRequest *fr = receiver->getRequest(sender);
    if (fr)
    {
        fr->setStatus("declined");
        sender->receiveNotification(receiver, "declined your friend request.");
    }
    else
    {
        cout << "Friend request does not exist" << endl;
    }
}

User* UserGraph::searchUser(string username)
{
    return this->user_tree.find(username);
}

void UserGraph::sendMessage(User *sender, User *receiver, string content)
{
    if (sender == nullptr || receiver == nullptr || content == "")
    {
        cout << "Invalid user or message" << endl;
        return;
    }
    sender->sendMessage(content, receiver);
}

bool UserGraph::authenticateLogin(string username, string password)
{
    string actualPassword = this->user_lookup->search(username);
    if (actualPassword != "")
    {
        return actualPassword == password; // match password
    }
    return false; // incorrect username
}

void UserGraph::sendFollowRequest(User *sender, User *receiver)
{
    if (sender == nullptr || receiver == nullptr)
    {
        cout << "Invalid user" << endl;
        return;
    }
    else if (sender == receiver)
    {
        cout << "You cannot follow yourself" << endl;
        return;
    }
    sender->follow(receiver);
}