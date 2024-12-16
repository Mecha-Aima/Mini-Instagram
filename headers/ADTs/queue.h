#pragma once
#include <iostream>
#include <queue>
using namespace std;

class User;

template <typename T>
struct QueueNode {
    T data;
    QueueNode<T>* next;
    QueueNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue {
    friend class User;
private:
    QueueNode<T>* front;
    QueueNode<T>* back;
    int size;
public:
    Queue();
    ~Queue();
    Queue(const Queue<T>& other);
    void enqueue(T data);
    T dequeue();
    T peek() const;
    bool isEmpty() const;
    int getSize() const;
    void print() const;
    void clear();
    QueueNode<T>* getFront() const;

    Queue<T>& operator=(const Queue& other);
    T& operator[](int index);
    T& operator[](int index) const;
};

template <typename T>
Queue<T>::Queue() {
    front = nullptr;
    back = nullptr;
    size = 0;
}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
    front = nullptr;
    back = nullptr;
    size = 0;
    QueueNode<T>* current = other.front;
    while (current != nullptr) {
        enqueue(current->data);
        current = current->next;
    }

}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        this->clear();
        QueueNode<T>* current = other.front;
        while (current != nullptr) {
            this->enqueue(current->data);
            current = current->next;
        }
        size = other.size;
    }
    return *this;
}

template <typename T>
T& Queue<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    QueueNode<T>* current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
T& Queue<T>::operator[](int index) const{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    QueueNode<T>* current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void Queue<T>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
    size = 0;
    front = nullptr;
    back = nullptr;
}

template <typename T>
void Queue<T>::enqueue(T data) {
    QueueNode<T>* newNode = new QueueNode<T>(data);
    if (isEmpty()){
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
    size++;
}

template <typename T>
void Queue<T>::print() const {
    QueueNode<T>* current = front;
    while (current != nullptr) {
        cout << current->data << "\n";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    T data = front->data;
    QueueNode<T>* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        back = nullptr;
    }
    size--;
    return data;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
int Queue<T>::getSize() const {
    return size;
}

template <typename T>
QueueNode<T>* Queue<T>::getFront() const { return front; }