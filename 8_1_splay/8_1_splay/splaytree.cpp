#include <iostream>
#include <string>
#include "splaytree.h"

using namespace std;

struct TreeElement
{
	TreeElement *leftChild;
	TreeElement *rightChild;
	TreeElement *parent;
	int key;
	string value;
};

struct SplayTree
{
	TreeElement *root;
};

struct TwoTrees
{
	TreeElement *node1;
	TreeElement *node2;
};

SplayTree* createSplay()
{
	return new SplayTree{ nullptr };
}

void deleteTree(TreeElement *&root)
{
	if (!root)
	{
		return;
	}
	deleteTree(root->leftChild);
	deleteTree(root->rightChild);
	delete root;
	root = nullptr;
}

void deleteTree(SplayTree *&tree)
{
	deleteTree(tree->root);
	delete tree;
	tree = nullptr;
}

void setParent(TreeElement *child, TreeElement *parent)
{
	if (child)
	{
		child->parent = parent;
	}
}

void rotate(TreeElement *child, TreeElement *parent)
{
	TreeElement *grandparent = nullptr;
	if (parent->parent)
	{
		if (parent->parent->leftChild == parent)
		{
			parent->parent->leftChild = child;
		}
		else
		{
			parent->parent->rightChild = child;
		}
		grandparent = parent->parent;
	}
	if (parent->leftChild == child)
	{
		parent->leftChild = child->rightChild;
		child->rightChild = parent;
	}
	else
	{
		parent->rightChild = child->leftChild;
		child->leftChild = parent;
	}
	//update child
	if (child->leftChild)
	{
		child->leftChild->parent = child;
	}
	if (child->rightChild)
	{
		child->rightChild->parent = child;
	}
	//update parent
	if (parent->leftChild)
	{
		parent->leftChild->parent = parent;
	}
	if (parent->rightChild)
	{
		parent->rightChild->parent = parent;
	}
	child->parent = grandparent;
}

void splay(TreeElement *node)
{
	while (node->parent)
	{
		if (!node->parent->parent)
		{
			rotate(node, node->parent);
			return;
		}
		if ((node->parent->leftChild == node) == (node->parent->parent->leftChild == node->parent))
		{
			rotate(node->parent, node->parent->parent);
			rotate(node, node->parent);
		}
		else
		{
			rotate(node, node->parent);
			rotate(node, node->parent->parent);
		}
	}
}

TreeElement* findNode(TreeElement *root, int key)
{
	if (!root)
	{
		return nullptr;
	}
	if (root->key == key)
	{
		return root;
	}
	if (root->key < key)
	{
		return findNode(root->rightChild, key);
	}
	return findNode(root->leftChild, key);
}

TreeElement* findNearestNode(TreeElement *root, int key)
{
	if (!root)
	{
		return nullptr;
	}
	if (root->key == key)
	{
		splay(root);
		return root;
	}
	if (root->key < key && root->rightChild)
	{
		return findNearestNode(root->rightChild, key);
	}
	if (root->key > key && root->leftChild)
	{
		return findNearestNode(root->leftChild, key);
	}
	splay(root);
	return root;
}

TwoTrees split(SplayTree *tree, int key)
{
	TreeElement *root = tree->root;
	if (!root)
	{
		return{ nullptr, nullptr };
	}
	root = findNearestNode(root, key);
	if (root->key == key)
	{
		setParent(root->leftChild, nullptr);
		setParent(root->rightChild, nullptr);
		return{ root->leftChild, root->rightChild };
	}
	if (root->key < key)
	{
		TreeElement *temp = root->rightChild;
		root->rightChild = nullptr;
		setParent(temp, nullptr);
		return{ root, temp };
	}
	else
	{
		TreeElement *temp = root->leftChild;
		root->leftChild = nullptr;
		setParent(temp, nullptr);
		return{ temp, root };
	}
}

void insert(SplayTree *tree, int key, string value)
{
	auto twoTrees = split(tree, key);
	TreeElement *root = new TreeElement{ twoTrees.node1, twoTrees.node2, nullptr, key, value };
	//update root's children
	setParent(root->leftChild, root);
	setParent(root->rightChild, root);
	tree->root = root;
}

void changeValue(SplayTree *tree, int key, string value)
{
	insert(tree, key, value);
}

string getValue(SplayTree *tree, int key)
{
	auto node = findNode(tree->root, key);
	if (node)
	{
		insert(tree, key, node->value);
		return node->value;
	}
	return "";
}

bool isHere(SplayTree *tree, int key)
{
	auto node = findNode(tree->root, key);
	if (node)
	{
		insert(tree, key, node->value);
		return true;
	}
	return false;
}

TreeElement* mergeTree(TreeElement *left, TreeElement *right)
{
	if (!right)
	{
		return left;
	}
	if (!left)
	{
		return right;
	}
	right = findNearestNode(right, left->key);
	right->leftChild = left;
	left->parent = right;
	return right;
}

void remove(SplayTree *tree, int key)
{
	TreeElement *root = tree->root;
	root = findNode(root, key);
	if (!root)
	{
		return;
	}
	setParent(root->leftChild, nullptr);
	setParent(root->rightChild, nullptr);
	tree->root = mergeTree(root->leftChild, root->rightChild);
}

void preorder(TreeElement *root)
{
	if (root)
	{
		cout << root->key << " " << root->value << endl;
	}
	else
	{
		return;
	}
	preorder(root->leftChild);
	preorder(root->rightChild);
}

void preorder(SplayTree *tree)
{
	preorder(tree->root);
}
