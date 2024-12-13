#include "../../headers/ADTs/graph.h"
using namespace std;

template <typename T>
Graph<T>::Graph()
{
    head = nullptr;
    size = 0;
}

template <typename T>
Graph<T>::~Graph()
{
    clear();
}

template <typename T>
void Graph<T>::add(T data)
{
    Vertex<T> *newVertex = new Vertex<T>(data);
    newVertex->nextVertex = head;
    head = newVertex;
    size++;
}

template <typename T>
Graph<T>::Graph(const Graph<T>& other) : head(nullptr), size(0) {
    Vertex<T> *otherCurrent = other.head;
    while (otherCurrent) {
        add(otherCurrent->value);
        otherCurrent = otherCurrent->nextVertex;
    }

    otherCurrent = other.head;
    while (otherCurrent) {
        AdjListNode<T> *adj = otherCurrent->head;
        while (adj) {
            if (!hasEdge(otherCurrent->value, adj->data)) {
                addEdge(otherCurrent->value, adj->data);
            }
            adj = adj->next;
        }
        otherCurrent = otherCurrent->nextVertex;
    }
}

template <typename T>
Graph<T>& Graph<T>::operator=(const Graph<T>& other) {
    if (this != &other) {
        clear();
        
        Vertex<T> *otherCurrent = other.head;
        
        while (otherCurrent) {
            add(otherCurrent->value);
            otherCurrent = otherCurrent->nextVertex;
        }
        
        otherCurrent = other.head;
        while (otherCurrent) {
            AdjListNode<T> *adj = otherCurrent->head;
            while (adj) {
                if (!hasEdge(otherCurrent->value, adj->data)) {
                    addEdge(otherCurrent->value, adj->data);
                }
                adj = adj->next;
            }
            otherCurrent = otherCurrent->nextVertex;
        }
        
        return *this;
    }
    return *this;
}

template <typename T>
void Graph<T>::clear()
{
    Vertex<T> *currVertex = head;
    while (currVertex)
    {
        AdjListNode<T> *neighbor = currVertex->head;
        while (neighbor)
        {
            AdjListNode<T> *tempAdj = neighbor;
            neighbor = neighbor->next;
            delete tempAdj;
        }
        Vertex<T> *tempVertex = currVertex;
        currVertex = currVertex->nextVertex;
        delete tempVertex;  
        head = nullptr;
        size = 0;
    }
}

template <typename T>
bool Graph<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
int Graph<T>::getSize() const
{
    return size;
}

template <typename T>
void Graph<T>::print() const
{
    Vertex<T> *current = head;
    while (current)
    {
        cout << current->value << " -> ";
        AdjListNode<T> *neighbor = current->head;
        while (neighbor)
        {
            cout << neighbor->data << ", ";
            neighbor = neighbor->next;
        }
        cout << endl;
        current = current->nextVertex;
    }
}

template <typename T>
bool Graph<T>::addEdge(T u, T v)
{
    if (u == v) {
        throw std::invalid_argument("Self-loops are not allowed");
    }
    if(hasEdge(u, v)) {
        return false;
    }
    if (!contains(u))
    {
        this->add(u);
    }
    if (!contains(v))
    {
        this->add(v);
    }

    Vertex<T> *current = head;
    while (current)
    {
        if (current->value == u)
        {
            AdjListNode<T> *newNode = new AdjListNode<T>(v);
            newNode->next = current->head;
            current->head = newNode;
        }

        if (current->value == v)
        {
            AdjListNode<T> *newNode = new AdjListNode<T>(u);
            newNode->next = current->head;
            current->head = newNode;
        }

        current = current->nextVertex;
    }

    return true;
}

template <typename T>
void Graph<T>::remove(T data)
{
    if (head == nullptr) {
        throw std::runtime_error("Cannot remove from an empty graph");
    }

    bool found = false;
    Vertex<T> *current = head;
    Vertex<T> *previous = nullptr;
    while (current)
    {
        if (current->value == data)
        {
            found = true;
                AdjListNode<T> *adj = current->head;
            while (adj) {
                Vertex<T> *neighbor = getVertex(adj->data);
                if (neighbor) {
                    removeEdge(current->value, adj->data);
                }
                adj = adj->next;
            }

                        if (previous == nullptr) {
                head = current->nextVertex;
            } else {
                previous->nextVertex = current->nextVertex;
            }

            delete current;
            size--;
            break;
        }
        previous = current;
        current = current->nextVertex;
    }

    if (!found) {
        throw std::runtime_error("Vertex not found in the graph");
    }
}

template <typename T>
void Graph<T>::removeEdge(T u, T v)
{
    if (head == nullptr)
    {
        throw std::runtime_error("Cannot remove edge from an empty graph");
    }
    else if (!contains(u) || !contains(v))
    {
        throw std::runtime_error("Cannot remove edge from a vertex that does not exist");
    }
    else if (!hasEdge(u, v))
    {
        throw std::runtime_error("Cannot remove edge that does not exist");
    }
    else
    {
        
        Vertex<T> *vertexU = getVertex(u);
        if (vertexU)
        {
            AdjListNode<T> *adj = vertexU->head;
            AdjListNode<T> *prev = nullptr;

            while (adj)
            {
                if (adj->data == v)
                {
                    if (prev)
                        prev->next = adj->next;
                    else
                        vertexU->head = adj->next;

                    delete adj;
                    break;
                }
                prev = adj;
                adj = adj->next;
            }
        }

        
        Vertex<T> *vertexV = getVertex(v);
        if (vertexV)
        {
            AdjListNode<T> *adj = vertexV->head;
            AdjListNode<T> *prev = nullptr;

            while (adj)
            {
                if (adj->data == u)
                {
                    if (prev)
                        prev->next = adj->next;
                    else
                        vertexV->head = adj->next;

                    delete adj;
                    break;
                }
                prev = adj;
                adj = adj->next;
            }
        }
    }
}

template <typename T>
bool Graph<T>::contains(T data) const
{
    Vertex<T> *current = head;
    while (current)
    {
        if (current->value == data)
            return true;
        current = current->nextVertex;
    }
    return false;
}

template <typename T>
bool Graph<T>::hasEdge(T u, T v) const
{
    Vertex<T> *current = getVertex(u);
    if (current)
    {
        AdjListNode<T> *adj = current->head;
        while (adj)
        {
            if (adj->data == v)
                return true;
            adj = adj->next;
        }
    }
    return false;
}

template <typename T>
Vertex<T> *Graph<T>::getVertex(T data) const
{
    Vertex<T> *current = head;
    while (current)
    {
        if (current->value == data)
            return current;
        current = current->nextVertex;
    }
    return nullptr;
}

template <typename T>
void Graph<T>::depthFirstTraversal() const
{
    bool *visited = new bool[size]{false};
    Vertex<T> *current = head;
    while (current)
    {
        DFTraversalHelper(current, visited);
        current = current->nextVertex;
    }
    cout << "\n";
    delete[] visited;
}

template <typename T>
void Graph<T>::DFTraversalHelper(Vertex<T> *v, bool visited[]) const
{
    try {
        int index = getVertexIndex(v->value);
        if (visited[index])
        {
            return;
        }
        visited[index] = true;
        cout << v->value << " ";
        AdjListNode<T> *adj = v->head;
        while (adj)
        {
            if (!visited[getVertexIndex(adj->data)])
                DFTraversalHelper(getVertex(adj->data), visited);
            adj = adj->next;
        }
    }
    catch (const std::exception& e) {
        delete[] visited;
    }
}

template <typename T>
void Graph<T>::breadthFirstTraversal() const
{
    bool *visited = new bool[size]{false};  
    Queue<Vertex<T> *> q;

    Vertex<T> *currentVertex = head;
    int currentIndex = getVertexIndex(currentVertex->value);
    while (currentVertex)
    {
        if (!visited[currentIndex])
        {
            q.enqueue(currentVertex);
            visited[currentIndex] = true;
            while (!q.isEmpty())
            {
                Vertex<T> *current = q.peek();
                q.dequeue();
                std::cout << current->value << " ";
                AdjListNode<T> *adj = current->head;
                while (adj)
                {
                    int adjIndex = getVertexIndex(adj->data);
                    if (!visited[adjIndex])
                    {
                        q.enqueue(getVertex(adj->data));  
                        visited[adjIndex] = true;         
                    }
                    adj = adj->next;
                }
            }
        }
        currentVertex = currentVertex->nextVertex;  
    }
    delete[] visited;
}


template <typename T>
int Graph<T>::getVertexIndex(T data) const
{
    Vertex<T>* current = head;
    int index = 0;

    while (current)
    {
        if (current->value == data)
        {
            return index;
        }
        current = current->nextVertex;
        index++;
    }
    return -1;
}

template <typename T>
Vertex<T>* Graph<T>::depthFirstSearch(T data) const
{
    bool *visited = new bool[size];
    Vertex<T>* current = head;
    while (current) {
        Vertex<T>* result = DFSHelper(current, visited);
        if (result)
        {
            delete[] visited;
            return result;
        }
        current = current->nextVertex;
    }
    delete[] visited;
    return nullptr;
}

template <typename T>
Vertex<T>* Graph<T>::DFSHelper(Vertex<T>* v, bool visited[]) const
{
    try{
        int index = getVertexIndex(v->value);
        if (visited[index]) {
            return nullptr;
        }
        visited[index] = true;

        if (v->value == data) {
            return v;
        }

        AdjListNode<T>* adj = v->head;
        while (adj) {
            Vertex<T>* result = DFSHelper(getVertex(adj->data), visited);
            if (result) {
                return result;
            }
            adj = adj->next;
        }
        return nullptr;
    } catch (const std::exception& e) {
        delete[] visited;
    }
}

template <typename T>
Vertex<T>* Graph<T>::breadthFirstSearch(T data) const
{
    bool* visited = new bool[size];
    Queue<Vertex<T>*> q;
    Vertex<T>* current = head;
    int currentIndex = getVertexIndex(current->value);
    while (current)
    {
        if (!visited[currentIndex])
        {
            q.enqueue(current);
            visited[currentIndex] = true;
            while (!q.isEmpty())
            {
                Vertex<T> *current = q.peek();
                q.dequeue();
                if (current->value == data)
                {
                    delete[] visited;
                    return current;
                }
                AdjListNode<T> *adj = current->head;
                while (adj)
                {
                    int adjIndex = getVertexIndex(adj->data);
                    if (!visited[adjIndex])
                    {
                        q.enqueue(getVertex(adj->data));  
                        visited[adjIndex] = true;         
                    }
                    adj = adj->next;
                }
            }
        }
        current = current->nextVertex;  
    }

    delete[] visited;
    return nullptr;
}