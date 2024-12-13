#include "../../headers/app/admin.h"
using namespace std;

AdminUser::AdminUser(string username, string password, string city, UserGraph& graph) : User(username, password, city), user_graph(graph) {}

void AdminUser::addNewUser(string username, string password, string city)
{
    if (username == this->username)
    {
        cout << "New username cannot be the same as the admin username" << endl;
        return;
    }

    this->user_graph.addUser(username, password, city);
}

void AdminUser::removeUser(string username)
{
    this->user_graph.removeUser(username);
}

void AdminUser::updateUser(string username, string newPassword, string newCity)
{
    User *user = this->user_graph.searchUser(username);
    if (user == nullptr)
    {
        cout << "User does not exist" << endl;
        return;
    }

    this->user_graph.user_lookup->update(user->username, user->password, newPassword);
    user->password = newPassword;
    user->city = newCity;
}

void AdminUser::listUsers() const
{
    this->user_graph.user_tree.printUsers();
}

void AdminUser::viewUser(string username) const
{
    User *user = this->user_graph.searchUser(username);
    if (user == nullptr)
    {
        cout << "User does not exist" << endl;
        return;
    }
    cout << "\n---------------------USER INFO---------------------" << endl;
    cout << "Username: " << user->username << endl;
    cout << "Password: " << user->password << endl;
    cout << "City: " << user->city << endl;
    cout << setw(50) << setfill('-') << "" << "\n" << setfill(' ');
    cout << "POSTS" << endl;
    user->posts.print();
    cout << setw(50) << setfill('-') << "" << "\n" << setfill(' ');
    cout << "FOLLOWERS" << endl;
    user->listFollowers();
    cout << setw(50) << setfill('-') << "" << "\n" << setfill(' ');
    cout << "FRIENDS" << endl;
    user->listFriends();
    cout << setw(50) << setfill('-') << "" << "\n" << setfill(' ');
}

void AdminUser::removeFriend(string username, string friendUsername)
{
    User *u1 = this->user_graph.searchUser(username);
    User *u2 = this->user_graph.searchUser(friendUsername);
    if (u1 == nullptr || u2 == nullptr)
    {
        cout << "User does not exist" << endl;
        return;
    }
    u1->removeFriend(u2);
    u2->removeFriend(u1);
    user_graph.removeEdge(u1, u2);
}

void AdminUser::resetPassword(string username, string oldPassword, string newPassword)
{
    if (user_graph.authenticateLogin(username, oldPassword))
    {
        User *user = user_graph.searchUser(username);
        user->password = newPassword;
        user_graph.user_lookup->update(user->username, oldPassword, user->password);
        cout << "Password reset successfully" << endl;
    }
    else
    {
        cout << "Incorrect password" << endl;
    }
}

void AdminUser::broadCastMessage(const string& content)
{
    if (content == "")
    {
        cout << "Message cannot be empty" << endl;
        return;
    }
    Vertex<User *> *current = this->user_graph.head;
    while (current != nullptr)
    {
        sendMessage(content, current->value);
        current = current->nextVertex;
    }
}
