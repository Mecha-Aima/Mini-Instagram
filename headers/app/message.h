#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include <sstream>
#include <stdexcept>
#include "../ADTs/stack.h"
#include "../ADTs/queue.h"

class Messages;

class Message{
private:
    friend class Messages;
    std::string sender;
    std::string receiver;
    std::string content;
    std::string timestamp;
public:
    Message(std::string sender, std::string receiver,  const std::string& content);
    void editMessage( const std::string& content);
    std::string getSender() const;
    std::string getReceiver() const;
    std::string getContent() const;
    std::string getTimestamp() const;
    bool isEmpty() const { return this->sender.empty() || this->receiver.empty() || this->content.empty(); }

    friend ostream& operator<<(ostream& os, const Message& message);
};

class Messages{
private:
    Stack<Message> messages;
public:
    void sendMessage(std::string sender, std::string receiver, const std::string& content);
    void sendMessage(Message message);
    bool isEmpty() const;
    Message getLatestMessage() const;
    void printMessages() const;
    void clearMessages();
    StackNode<Message>* getTop() { return this->messages.getTop(); }
};

class realTimeMessages { private:
    Queue<Message> messages;
public:
    friend class Messages;
    void enqueueMessage(Message message);
    Message dequeueMessage();
    Message peekMessage();
    void printUnreadMessages();
    bool isEmpty() const;
};

