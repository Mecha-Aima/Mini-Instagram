#include "../../include/ADTs/linked_list.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
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
            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
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
