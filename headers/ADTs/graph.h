#pragma once
#include <iostream>
#include <stdexcept>
#include "../../headers/ADTs/queue.h"

template <typename T>
struct AdjListNode {
    T data;
    AdjListNode<T> *next;
    AdjListNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
struct Vertex {
    T value;
    AdjListNode<T> *head;
    Vertex<T> *nextVertex;
    Vertex(T data) : value(data), head(nullptr), nextVertex(nullptr) {}
};

template <typename T>
class Graph{
protected:
    // As adjacency list
    Vertex<T> *head;
    int size;

    void DFTraversalHelper(Vertex<T> *v, bool visited[]) const;
    Vertex<T> *getVertex(T data) const;
    int getVertexIndex(T data) const;
public:
    Graph();
    virtual ~Graph();
    Graph(const Graph<T>& other);
    Graph<T>& operator=(const Graph<T>& other);
    void add(T data);
    bool addEdge(T u, T v);
    void remove(T data);
    void removeEdge(T u, T v);
    int getSize() const;
    bool isEmpty() const;
    void print() const;
    bool contains(T data) const;
    void clear();
    bool hasEdge(T u, T v) const; 
    
    // graph traversals
    void depthFirstTraversal() const;
    void breadthFirstTraversal() const;
    Vertex<T>* depthFirstSearch(T data) const;
    Vertex<T>* DFSHelper(Vertex<T> *v, bool visited[]) const;
    Vertex<T>* breadthFirstSearch(T data) const;

};