#include "../../include/ADTs/stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack() {
    top = nullptr;
    size = 0;
}

template <typename T>
Stack<T>::~Stack() {
    this->clear();
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
    top = nullptr;
    Stack<T> tempStack;

    StackNode<T>* current = other.top;
    while (current != nullptr) {
        tempStack.push(current->data);
        current = current->next;
    }

    while (!tempStack.isEmpty()) {
        this->push(tempStack.peek());
        tempStack.pop();
    }

    size = other.size;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        this->clear();
        StackNode<T>* current = other.top;
        while (current != nullptr) {
            this->push(current->data);
            current = current->next;
        }
        size = other.size;
    }
    return *this;
}

template<typename T>
void Stack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
    size = 0;
    top = nullptr;
}

template <typename T>
void Stack<T>::push(T data) {
    StackNode<T>* newNode = new StackNode<T>(data);
    newNode->next = top;
    top = newNode;
    size++;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw runtime_error("Cannot pop an empty stack");
    }

    T data = top->data;
    StackNode<T>* temp = top;
    top = top->next;
    delete temp;
    size--;
    return data;
}

template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw runtime_error("Cannot peek at an empty stack");
    }
    return top->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
int Stack<T>::getSize() const {
    int size = 0;
    StackNode<T>* current = top;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

template <typename T>
void Stack<T>::print() const {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    StackNode<T>* current = top;
    while (current != nullptr) {
        cout << current->data << "\n";
        current = current->next;
    }
    cout << endl;
}



