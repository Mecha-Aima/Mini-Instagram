#include "../../headers/app/user_tree.h"
using namespace std;

UserTree::UserTree() {}

void UserTree::insertUser(User *user)
{   
    if (!user || user->isEmpty())
    {
        throw invalid_argument("Username cannot be empty");
    }
    else if (this->find(user->getUsername()) != nullptr) {
        throw std::invalid_argument("User already exists");
    }
    this->insert(user);
}

void UserTree::removeUser(User *userToRemove)
{
    if (!userToRemove) {
        throw std::invalid_argument("User does not exist");
    }
    this->remove(userToRemove);
}

void UserTree::removeUser(const string& username)
{
    User* userToRemove = this->find(username);
    if (!userToRemove) {
        throw std::invalid_argument("User does not exist");
    }
    this->remove(userToRemove);
}

void inorderPrint(TreeVertex<User *> *node)
{
    if (!node) return;
    inorderPrint(node->left);
    cout << *(node->val) << "\n";
    inorderPrint(node->right);
}

void UserTree::printUsers() const
{
    if (this->isEmpty())
    {
        cout << "User tree is empty" << endl;
        return;
    }
    inorderPrint(root);
}

User* UserTree::find(const string& username)
{
    if (username == "")
    {
        throw invalid_argument("Username cannot be empty");
    }
    TreeVertex<User *>* current = this->root;
    while (current != nullptr)
    {
        if (current->val->getUsername() == username)
        {
            return current->val;
        }
        else if (username < current->val->getUsername())
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return nullptr;
}

bool UserTree::containsUser(const string& username)
{
    return this->find(username) != nullptr;
}