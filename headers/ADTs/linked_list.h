#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class User;
class UserGraph;

template <typename T>
struct ListNode {
    T data;
    ListNode<T>* next;
    ListNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
    friend class User;
    friend class UserGraph;
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>& other);
    LinkedList<T>& operator=(const LinkedList<T>& other);
    T& operator[](int index);
    T& operator[](int index) const;
    void add(T data);
    void remove(T data);
    int getSize() const;
    bool isEmpty() const;
    void print() const;
    bool contains(T data) const;
    T get(int index) const;
    void removeAt(int index);
    void insertAt(int index, T data);
    void clear();

private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;
    ListNode<T>* getHead() const { return head; }
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    ListNode<T>* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

// Assignment operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this != &other) {
        this->clear();
        ListNode<T>* current = other.head;
        while (current != nullptr) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
T& LinkedList<T>::operator[](int index)
{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return *current;
}

template <typename T>
T& LinkedList<T>::operator[](int index) const
{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return *current;
}

template <typename T>
void LinkedList<T>::add(T data)
{
    ListNode<T>* newNode = new ListNode<T>(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template <typename T>
void LinkedList<T>::print() const {
    ListNode<T>* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
bool LinkedList<T>::contains(T data) const {
    ListNode<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
T LinkedList<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    ListNode<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    ListNode<T>* current = head;
    if (index == 0) {
        ListNode<T>* temp = current;
        head = current->next;
        delete temp;
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        ListNode<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    size--;
}

template <typename T>
void LinkedList<T>::insertAt(int index, T data) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }

    ListNode<T>* newNode = new ListNode<T>(data);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (index == size) {
            tail = newNode;
        }
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove(T data) {
    if (isEmpty()) {
        cout << "List is empty" << endl;
    }
    else
    {
        ListNode<T>* current = head;
        ListNode<T>* previous = nullptr;
        while (current != nullptr && current->data != data) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Element not found" << endl;
        }
        else {
            if (size == 1)
            {
                delete current;
                head = nullptr;
                tail = nullptr;
                return;
            }
            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            if (current == tail) {
                tail = previous;
            }
            delete current;
            size--;
        }
    }
}

template <typename T>
void LinkedList<T>::clear() {
    ListNode<T>* current = head;
    while (current != nullptr) {
        ListNode<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}
