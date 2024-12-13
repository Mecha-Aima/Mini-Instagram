#include "../../headers/app/message.h"
using namespace std;

Message::Message(std::string sender, std::string receiver,  const std::string& content) {
    this->sender = sender;
    this->receiver = receiver;
    if (content == "")
        this->content = "No content";
    else
        this->content = content;
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << ctime(&currentTime);
    this->timestamp = ss.str();

    timestamp.erase(timestamp.find_last_not_of(" \n\r\t") + 1);
}

void Message::editMessage( const std::string& content)
{
    this->content = content;
}

string Message::getSender() const { return this->sender; }
string Message::getReceiver() const { return this->receiver; }
string Message::getContent() const { return this->content; }
string Message::getTimestamp() const { return this->timestamp; }

ostream& operator<<(ostream& os, const Message& message) 
{
    os << "Sender: " << message.sender << endl;
    os << "Receiver: " << message.receiver << endl;
    os << "Content: " << message.content << endl;
    os << "Sent: " << message.timestamp << endl;
    return os;
}

void Messages::sendMessage(string sender, string receiver,  const std::string& content)
{
    Message message(sender, receiver, content);
    this->messages.push(message);
}

void Messages::sendMessage(Message message)
{
    this->messages.push(message);
}

bool Messages::isEmpty() const
{
    return this->messages.isEmpty();
}

Message Messages::getLatestMessage() const
{
    try
    {
        return this->messages.peek();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return Message("", "", "");
    }    
}

void Messages::printMessages() const
{
    this->messages.print();
}

void Messages::clearMessages()
{
    this->messages.clear();
}

void realTimeMessages::enqueueMessage(Message message)
{
    this->messages.enqueue(message);
}

void realTimeMessages::printUnreadMessages()
{
    if (this->messages.isEmpty())
    {
        cout << "No new messages in your inbox!" << endl;
        return;
    }
    cout << "UNREAD MESSAGES: " << endl;
    cout << setw(50) << setfill('=') << "" << "\n" << setfill(' ');
    this->messages.print();
}

bool realTimeMessages::isEmpty() const
{
    return this->messages.isEmpty();
}

Message realTimeMessages::dequeueMessage()
{
    try{
        return this->messages.dequeue();
    }   
    catch (const std::exception&)
    {
        cout << "No new messages in your inbox!" << endl;
    }
    return Message("", "", "");
}

Message realTimeMessages::peekMessage()
{
    try{
        return this->messages.peek();
    }   
    catch (const std::exception&)
    {
        cout << "No new messages in your inbox!" << endl;
    }
    return Message("", "", "");
}
