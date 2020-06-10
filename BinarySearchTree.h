#pragma once
#include<functional>

template<typename T>
class BinarySearchTree;

template<typename T>
class BinarySearchTreeNode
{
	friend class BinarySearchTree<T>;
private:
	BinarySearchTreeNode(const T& value, BinarySearchTreeNode<T>* right, BinarySearchTreeNode<T>* left, BinarySearchTreeNode<T>* parent) : value(value), key(std::hash<T>{}(value)), right(right), left(left), parent(parent) {}
	T value;
	size_t key;
	BinarySearchTreeNode<T>* right;
	BinarySearchTreeNode<T>* left;
	BinarySearchTreeNode<T>* parent;
};

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() : root(nullptr) {}
	void Add(T value);
	bool Find(const T& value);
private:
	BinarySearchTreeNode<T>* root;
};

template<typename T>
void BinarySearchTree<T>::Add(T value)
{
	if (root == nullptr)
		root = new BinarySearchTreeNode<T>(value, nullptr, nullptr, nullptr);
	else
	{
		BinarySearchTreeNode<T>* current = root;
		BinarySearchTreeNode<T>* current_parent = root->parent;
		size_t key = std::hash<T>{}(value);
		while (current != nullptr)
		{
			current_parent = current;
			if (key > current->key)
				current = current->right;
			else
				current = current->left;
		}
		if(key > current_parent->key)
			current_parent->right = new BinarySearchTreeNode<T>(value, nullptr, nullptr, current_parent);
		else
			current_parent->left = new BinarySearchTreeNode<T>(value, nullptr, nullptr, current_parent);
	}
}

template<typename T>
bool BinarySearchTree<T>::Find(const T& value)
{
	BinarySearchTreeNode<T>* current = root;
	size_t key = std::hash<T>{}(value);
	while (current != nullptr)
	{
		if (current->key == key)
			return true;
		else
		{
			if (key > current->key)
				current = current->right;
			else
				current = current->left;
		}
	}
	return false;
}
