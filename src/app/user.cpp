#include "../../headers/app/user.h"
using namespace std;

Post::Post(string owner, const string& content)
{
    this->owner = owner;
    this->content = content;
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << ctime(&currentTime);
    this->timestamp = ss.str();

    timestamp.erase(timestamp.find_last_not_of(" \n\r\t") + 1);
}

ostream& operator<<(ostream& os, const Post& post)
{
    os << "Owner: " << post.owner << endl;
    os << "Posted on: " << post.timestamp << endl;
    os << "Content:\n" << post.content << endl;
    os << setw(50) << setfill('-') << "\n" << setfill(' ');
    return os;
}

User::User(string username, string password, string city)
{
    this->setUsername(username);
    this->setPassword(password);
    this->setCity(city);
    updateLastLogin();
}

bool User::isEmpty() const { return this->username == "" || this->password == ""; }

void User::updateLastLogin()
{
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << ctime(&currentTime);
    this->last_login = ss.str();
    last_login.erase(last_login.find_last_not_of(" \n\r\t") + 1);
}

User::~User() { 
    this->posts.clear();
    this->followed.clear();
    this->friends.clear();
}

User::User(const User& other)
{
    this->username = other.username;
    this->password = other.password;
    this->city = other.city;
    this->last_login = other.last_login;
    this->posts = other.posts;

    // Deep copy of followed list
    ListNode<User*> *current = other.followed.getHead();
    while (current)
    {
        this->followed.add(current->data);
        current = current->next;
    }

    this->friendRequests = other.friendRequests;

    current = other.friends.getHead();
    while (current)
    {
        this->friends.add(current->data);
        current = current->next;
    }
}

User& User::operator=(const User& other)
{
    this->username = other.username;
    this->password = other.password;
    this->city = other.city;
    this->last_login = other.last_login;
    this->posts = other.posts;

    return *this;
}

string User::getUsername() const { return this->username; }
string User::getCity() const { return this->city; }
string User::getLastLogin() const { return this->last_login; }
Stack<Post> User::getPosts() const { return this->posts; }
Stack<Post> User::getFollowedPosts() const { return this->followed_posts; }

void User::setUsername(string username)
{
    // should contain letters and numbers only and have at least length of 5
    bool isValid = true;
    for (int i = 0; i < username.length(); i++)
    {
        if (!isalpha(username[i]) && !isdigit(username[i]))
            isValid = false;
    }
    if (username.length() < 3 || !isValid)
    {
        cout << "Invalid username: " << username << endl;
        this->username = "";
        return;
    }
    this->username = username;
    
}
void User::setPassword(string password)
{
    // should be of length 8 and have uppercase and lowercase letters, numbers, and special characters
    bool containsUppercase = false;
    bool containsLowercase = false;
    bool containsNumbers = false;
    bool containsSpecial = false;
    for (int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
            containsUppercase = true;
        else if (islower(password[i]))
            containsLowercase = true;
        else if (isdigit(password[i]))
            containsNumbers = true;
        else if (ispunct(password[i]) || password[i] == '_' || password[i] == '#' || password[i] == '$' || password[i] == '@')
            containsSpecial = true;
    }
    if (password.length() < 8 || !containsUppercase || !containsLowercase || !containsNumbers || !containsSpecial)
    {
        cout << "Invalid password: " << password << endl;
        this->password = "";
        return;
    }
    this->password = password;
}
void User::setCity(string city)
{
    // Should only contain letters
    for (int i = 0; i < city.length(); i++)
    {
        if (!isalpha(city[i]) && !isspace(city[i]))
        {
            cout << "Invalid city: " << city << endl;
            this->city = "";
            return;
        }
    }
    this->city = city;
}

bool User::operator<(const User& other) const
{
    return this->username < other.username;
}

void User::addPost(const string& content)
{
    Post post(this->username, content);
    this->posts.push(post);
}

void User::newsFeed() 
{
    cout << "\nYOUR NEWS FEED" << endl;
    cout << setw(50) << setfill('=') << "" << "\n" << setfill(' ');
    if (this->posts.isEmpty() && this->followed_posts.isEmpty())
    {
        cout << "No posts yet" << endl;
    }
    if (!posts.isEmpty())
        posts.print();
    if (!followed_posts.isEmpty())
        followed_posts.print();
    cout << endl;
}

void User::refreshFeed()
{
    this->followed_posts.clear();
    ListNode<User*> *current = followed.getHead();
    while (current)
    {
        User *user = current->data;
        Stack<Post> fPosts = user->getPosts();
        while (!fPosts.isEmpty())
        {
            this->followed_posts.push(fPosts.pop());
        }
        current = current->next;
    }
}

void User::listFollowers() const
{
    ListNode<User*> *current = followed.getHead();
    while (current != nullptr)
    {
        cout << current->data->getUsername() << endl;
        current = current->next;
    }
}

void User::listFriends() const
{
    ListNode<User*> *current = friends.getHead();
    while (current != nullptr)
    {
        cout << current->data->getUsername() << endl;
        current = current->next;
    }
}

ostream& operator<<(ostream& os, const User& user)
{
    os << "Username: " << user.username << endl;
    os << "City: " << user.city << endl;
    os << "Last login: " << user.last_login << endl;
    return os;
}

Messages& User::getMessages()
{
    return this->messages;
}

void User::addRequest(FriendRequest *fr)
{
    if (fr->status == "pending" || fr->status == "accepted" || fr->status == "declined")
        this->friendRequests.addRequest(fr);
}

void User::processRequests()
{
    this->friendRequests.processRequests();
}

void User::showRequests()
{
    this->friendRequests.showRequests();
}

void User::addFriend(User *user)
{
    if (user != nullptr && !this->friends.contains(user))
    {
        this->friends.add(user);
        this->receiveNotification(user, " is now your friend.");
    }
}

void User::removeFriend(User *user)
{
    if (user != nullptr && this->friends.contains(user)) 
        this->friends.remove(user);
}

 void User::removeFollowedUser(User *user)
{
    if (user != nullptr && this->followed.contains(user))
    {
        this->followed.remove(user);
        this->refreshFeed();
    }
}

void User::sendFriendRequest(User *receiver)
{
    if (receiver == nullptr)
    {
        cout << "Invalid receiver" << endl;
        return;
    }
    FriendRequest *fr = new FriendRequest(this->username, receiver->username, "pending");
    receiver->addRequest(fr);
    receiver->receiveNotification(this, "sent you a friend request.");
}

void User::sendMessage(const string &content, User *receiver)
{
    if (receiver == nullptr || receiver == this)
    {
        cout << "Invalid receiver" << endl;
        return;
    }
    Message message(this->username, receiver->username, content);
    
    receiver->unreadMessages.enqueueMessage(message);
    receiver->receiveNotification(this, "sent you a message.");
    
    this->messages.sendMessage(message);
}

void User::openInbox()
{
    if (this->unreadMessages.isEmpty())
    {
        cout << "Inbox is empty" << endl;
        return;
    }
    cout << "INBOX" << endl;
    cout << setw(50) << setfill('=') << "" << "\n" << setfill(' ');
    while (!this->unreadMessages.isEmpty())
    {
        Message message = this->unreadMessages.dequeueMessage();
        cout << message << endl;
        cout << setw(50) << setfill('-') << "" << "\n" << setfill(' ');
        this->messages.sendMessage(message);
    }   
}

Message User::peekInbox()
{
    if (this->unreadMessages.isEmpty())
    {
        cout << "Inbox is empty" << endl;
        return Message("", "", "");
    }
    return this->unreadMessages.peekMessage();
}

FriendRequest* User::getRequest(User *user)
{
    QueueNode<FriendRequest*> *current = this->friendRequests.fr.getFront();
    QueueNode<FriendRequest*> *previous = nullptr;
    while (current != nullptr)
    {
        if (user->getUsername() == current->data->sender)
        {
            if (previous == nullptr)
            {
                return this->friendRequests.fr.dequeue();
            }
            else
            {
                previous->next = current->next;
                return current->data;
            }
        }
        current = current->next;
    }
    return nullptr;
}

void User::follow(User *user)
{
    if (user == nullptr)
    {
        cout << "Invalid user" << endl;
        return;
    }
    this->followed.add(user);
    Stack<Post> fPosts = user->getPosts();
    while (!fPosts.isEmpty())
    {
        this->followed_posts.push(fPosts.pop());
    }
    user->receiveNotification(this, " started following you.");
}

void User::receiveNotification(User *receiver, const string& content)
{
    string notification = receiver->getUsername() + " " + content;
    this->notifications.enqueue(notification);
}

Queue<string> User::getNotifications() const
{
    return this->notifications;
}