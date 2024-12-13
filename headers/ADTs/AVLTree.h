#pragma once
#include <iostream>

template <typename T>
struct TreeVertex{
    T val;
    int height;
    TreeVertex* left;
    TreeVertex* right;
    TreeVertex(T v): val(v), height(0), left(nullptr), right(nullptr) {}
}; 

template <typename T>
class AVLTree{
public:
    AVLTree() : root(nullptr) {}
    AVLTree(const AVLTree<T> &other);
    // Constructor that takes a root node and the size of the tree
    AVLTree(TreeVertex<T>* other);
    virtual ~AVLTree();
    void insert(T);
    void remove(T);
    void inorder() const;
    int tree_height() const;
    bool isEmpty() const { return root == nullptr; }
    int size() const;
    bool contains(T) const;

protected:
    TreeVertex<T>* root;
    int num_nodes;
    int balance_factor(TreeVertex<T> *) const;
    int node_height(TreeVertex<T> *) const;

    void insert(TreeVertex<T> *&, T);
    void remove(TreeVertex<T>*&, T);
    void delete_tree(TreeVertex<T> *);
    void copy_tree(TreeVertex<T> *&, TreeVertex<T> *);
    // Display
    void inorder(TreeVertex<T> *) const;
    // Rotations
    void right_rotate(TreeVertex<T> *&);
    void left_rotate(TreeVertex<T> *&);
    void LR_rotate(TreeVertex<T> *&);
    void RL_rotate(TreeVertex<T> *&);
    // Remove function helper
    TreeVertex<T> *min_right(TreeVertex<T> *node);

    void updateHeight(TreeVertex<T> *node);

};