#include "../../headers/ADTs/AVLTree.h"
using namespace std;

template <typename T>
AVLTree<T>::AVLTree(TreeVertex<T>* other) {
	root = nullptr;
	this->num_nodes = 0;
	if (other != nullptr)
	{
		copy_tree(this->root, other);
	}
}

template <typename T>
AVLTree<T>::~AVLTree()
{
	delete_tree(root);
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& other)
{
	root = nullptr;
	this->num_nodes = 0;
	if (other.root != nullptr)
	{
		copy_tree(this->root, other.root);
	}
}

template <typename T>
void AVLTree<T>::copy_tree(TreeVertex<T>*& node, TreeVertex<T>* other)
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
void AVLTree<T>::delete_tree(TreeVertex<T>* node)
{
	if (!node) return;
	delete_tree(node->left);
	delete_tree(node->right);
	delete node;
}

template <typename T>
void AVLTree<T>::inorder(TreeVertex<T>* node) const
{
	if (!node) return;
	inorder(node->left);
	cout << node->val << "\n";
	inorder(node->right);
}

template <typename T>
int AVLTree<T>::node_height(TreeVertex<T>* node) const
{
	if (!node) return -1;
	int left_height = node_height(node->left);
	int right_height = node_height(node->right);
	return max(left_height, right_height) + 1;
}

template <typename T>
int AVLTree<T>::balance_factor(TreeVertex<T>* node) const
{
	if (!node) return 0;
	return node_height(node->left) - node_height(node->right);
}

template <typename T>
void AVLTree<T>::insert(TreeVertex<T>*& node, T val)
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
	else
		return;

	updateHeight(node);
	int bf = balance_factor(node);
	if (bf > 1 && node->left)
	{
		if (val > node->left->val)
		{
			LR_rotate(node);
		}
		else
		{
			right_rotate(node);
		}
	}
	else if (bf < -1 && node->right)
	{
		if (val < node->right->val)
		{
			RL_rotate(node);
		}
		else
		{
			left_rotate(node);
		}
	}
}

template <typename T>
void AVLTree<T>::right_rotate(TreeVertex<T>*& curr)
{
	TreeVertex<T>* temp = curr->left;
	curr->left = temp->right;
	temp->right = curr;

	updateHeight(curr);
	updateHeight(temp);

	curr = temp;
}

template <typename T>
void AVLTree<T>::updateHeight(TreeVertex<T>* node) {
	if (node) {
		node->height = 1 + max(
			node->left ? node->left->height : -1,
			node->right ? node->right->height : -1
		);
	}
}

template <typename T>
void AVLTree<T>::left_rotate(TreeVertex<T>*& curr)
{
	TreeVertex<T>* temp = curr->right;
	curr->right = temp->left;
	temp->left = curr;

	updateHeight(curr);
	updateHeight(temp);

	curr = temp;
}

template <typename T>
void AVLTree<T>::LR_rotate(TreeVertex<T>*& curr)
{
	if (!curr || !curr->left || !curr->left->right) return;
	left_rotate(curr->left);
	right_rotate(curr);
}

template <typename T>
void AVLTree<T>::RL_rotate(TreeVertex<T>*& curr)
{
	if (!curr || !curr->right || !curr->right->left)
		return;
	right_rotate(curr->right);
	left_rotate(curr);
}

template <typename T>
TreeVertex<T>* AVLTree<T>::min_right(TreeVertex<T>* node)
{
	if (!node) return nullptr;
	while (node->left)
	{
		node = node->left;
	}
	return node;
}

template <typename T>
void AVLTree<T>::remove(TreeVertex<T>*& node, T key)
{
	if (!node)
		return;
	if (node->val == key)
	{
		if (!node->left && !node->right)
		{
			delete node;
			node = nullptr;
		}
		else if (!node->left)
		{
			TreeVertex<T>* temp = node;
			node = node->right;
			delete temp;
		}
		else if (!node->right)
		{
			TreeVertex<T>* temp = node;
			node = node->left;
			delete temp;
		}
		else
		{
			TreeVertex<T>* new_root = min_right(node->right);
			node->val = new_root->val;
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

	if (node == nullptr) return;
	updateHeight(node);

	int bf = (node->left ? node->left->height : -1) - (node->right ? node->right->height : -1);
	if (bf > 1 && node->left)
	{
		int bfleft = balance_factor(node->left);

		if (bfleft < 0)
		{
			LR_rotate(node);
		}
		else
		{
			right_rotate(node);
		}
	}
	else if (bf < -1 && node->right)
	{
		int bfright = balance_factor(node->right);

		if (bfright > 0)
		{
			RL_rotate(node);
		}
		else
		{
			left_rotate(node);
		}
	}
}

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
	TreeVertex<T>* curr = root;
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
