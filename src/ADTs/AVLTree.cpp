#include "../../headers/ADTs/AVLTree.h"
using namespace std;

// Constructor
template <typename T>
AVLTree<T>::AVLTree(TreeVertex<T>* other) {
    root = nullptr;
    this->num_nodes = 0;
    if (other != nullptr)
    {
        copy_tree(this->root, other);
    }
}

// Destructor
template <typename T>
AVLTree<T>::~AVLTree()
{
    delete_tree(root);
}

// Copy constructor
template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T> &other)
{
    root = nullptr;
    this->num_nodes = 0;
    if (other.root != nullptr)
    {
        copy_tree(this->root, other.root);
    }
}

template <typename T>
void AVLTree<T>::copy_tree(TreeVertex<T> *&node, TreeVertex<T> *other)
{
    if (other == nullptr)
    {
        node = nullptr;
        return;
    }
    node = new TreeVertex<T>(other->val);
    this->num_nodes++;
    if (other->left)
        copy_tree(node->left, other->left);
    if (other->right)
        copy_tree(node->right, other->right);
}

template <typename T>
void AVLTree<T>::delete_tree(TreeVertex<T> *node)
{
    if (!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <typename T>
void AVLTree<T>::inorder(TreeVertex<T> *node) const
{
    if (!node) return;
    inorder(node->left);
    cout << node->val << "\n";
    inorder(node->right);
}

template <typename T>
int AVLTree<T>::node_height(TreeVertex<T> *node) const
{
    if (!node) return -1;
    int left_height = node_height(node->left);
    int right_height = node_height(node->right);
    return max(left_height, right_height) + 1;
}

template <typename T>
int AVLTree<T>::balance_factor(TreeVertex<T> *node) const
{
    if (!node) return 0;
    return node_height(node->left) - node_height(node->right);
}

template <typename T>
void AVLTree<T>::insert(TreeVertex<T> *&node, T val) 
{
    if (!node)
    {
        node = new TreeVertex<T>(val);
        num_nodes++;
        return;
    }
    if (val < node->val)
        insert(node->left, val);
    else if (val > node->val)
        insert(node->right, val);
    
    // Update height
    updateHeight(node);
    // Check balance factor
    int bf = (node->left ? node->left->height : -1) - 
             (node->right ? node->right->height : -1);
    if (bf > 1  && node->left)
    {
        // LR Case
        if (val > node->left->val)
        {
            LR_rotate(node);
        }
        // LL Case
        else
        {
            right_rotate(node);
        }
    }
    else if (bf < -1 && node->right)
    {
        // RL Case
        if (val < node->right->val)
        {
            RL_rotate(node);
        }
        // RR Case
        else
        {
            left_rotate(node);
        }
    }
}

template <typename T>
void AVLTree<T>::right_rotate(TreeVertex<T> *&curr)
{
    TreeVertex<T> *temp = curr->left;
    curr->left = temp->right;
    temp->right = curr;

    updateHeight(curr);
    updateHeight(temp);

    curr = temp;
}

template <typename T>
void AVLTree<T>::updateHeight(TreeVertex<T> *node) {
    if (node) {
        node->height = 1 + max(
            node->left ? node->left->height : -1,
            node->right ? node->right->height : -1
        );
    }
}

template <typename T>
void AVLTree<T>::left_rotate(TreeVertex<T> *&curr)
{
    TreeVertex<T> *temp = curr->right;
    curr->right = temp->left;
    temp->left = curr;

    updateHeight(curr);
    updateHeight(temp);

    curr = temp;
}

template <typename T>
void AVLTree<T>::LR_rotate(TreeVertex<T> *& curr)
{
    if (!curr || !curr->left || !curr->left->right) return;
    // Left part
    TreeVertex<T> *t1 = curr->left;
    TreeVertex<T> *t2 = t1->right;
    t1->right = t2->left;
    t2->left = t1;
    curr->left = t2;
    // Right part
    curr->left = t2->right;
    t2->right = curr;

    updateHeight(t1);
    updateHeight(curr);
    updateHeight(t2);

    curr = t2;
}

template <typename T>
void AVLTree<T>::RL_rotate(TreeVertex<T> *&curr)
{
    if (!curr || !curr->right || !curr->right->left) return;
    // Right part
    TreeVertex<T> *t1 = curr->right;
    TreeVertex<T> *t2 = t1->left;
    t1->left = t2->right;
    t2->right = t1;
    curr->right = t2;
    // Left part
    curr->right = t2->left;
    t2->left = curr;

    updateHeight(t1);
    updateHeight(curr);
    updateHeight(t2);

    curr = t2;
}

template <typename T>
TreeVertex<T> *AVLTree<T>::min_right(TreeVertex<T> *node)
{
    if (!node) return nullptr;
    while (node->left)
    {
        node = node->left;
    }
    return node;
}

template <typename T>
void AVLTree<T>::remove(TreeVertex<T>* &node, T key)
{
    if (!node)
        return;
    if (node->val == key)
    {
        // Leaf node
        if (!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }
        // Only right child
        else if (!node->left)
        {
            TreeVertex<T> *temp = node;
            node = node->right;
            delete temp;
        }
        // Only left child
        else if (!node->right)
        {
            TreeVertex<T> *temp = node;
            node = node->left;
            delete temp;
        }
        // Both child nodes exist
        else
        {
            TreeVertex<T> *new_root = min_right(node->right);
            node->val = new_root->val;
            // Delete new node from right subtree
            remove(node->right, node->val);
        }
        num_nodes--;
    }
    else if (key < node->val)
    {
        remove(node->left, key);
    }
    else
    {
        remove(node->right, key);
    }

    if (node == nullptr) return; // Avoid null pointer dereference

    // Check for imbalance
    updateHeight(node);
    
    int bf = (node->left ? node->left->height : -1) - (node->right ? node->right->height : -1);
    // Height changed, check for imbalance
    if (bf > 1 && node->left)
    {
        int bfleft = (node->left->left ? node->left->left->height : -1) - 
        (node->left->right ? node->left->right->height : -1);

        if (bfleft < 0)
        {
            // LR Case
            LR_rotate(node);
        }
        else
        {
            // LL Case
            right_rotate(node);
        }
    }
    else if (bf < -1 && node->right)
    {
        int bfright = (node->right->left ? node->right->left->height : -1) - 
        (node->right->right ? node->right->right->height : -1);

        if (bfright > 0)
        {
            // RL Case
            RL_rotate(node);
        }
        else
        {
            // RR Case
            left_rotate(node);
        }
    }
}

// ------------------------PUBLIC FUNCTIONS---------------------------------------
template <typename T>
void AVLTree<T>::inorder() const
{
    inorder(root);
}

template <typename T>
void AVLTree<T>::insert(T value)
{
    insert(this->root, value);
}

template <typename T>
void AVLTree<T>::remove(T key)
{
    remove(this->root, key);
}

template <typename T>
int AVLTree<T>::tree_height() const
{
    return node_height(root);
}

template <typename T>
bool AVLTree<T>::contains(T key) const
{
    TreeVertex<T> *curr = root;
    while (curr)
    {
        if (curr->val == key) return true;
        else if (key < curr->val) curr = curr->left;
        else curr = curr->right;
    }
    return false;
}

template <typename T>
int AVLTree<T>::size() const
{
    return num_nodes;
}
