#include <iostream>

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
	TreeElement* root;
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
	if (!child)
	{
		child->parent = parent;
	}
}

void updateParent(TreeElement *parent)
{
	setParent(parent->leftChild, parent);
	setParent(parent->rightChild, parent);
}

void rotate(TreeElement *child, TreeElement *parent)
{
	auto grandparent = parent->parent;
	if (!grandparent)
	{
		if (grandparent->leftChild == parent)
		{
			grandparent->leftChild = child;
		}
		else
		{
			grandparent->rightChild = child;
		}
	}
	if (parent->leftChild == child)
	{
		child->rightChild = parent;
		parent->leftChild = child->rightChild;
	}
	else
	{
		parent->rightChild = child->leftChild;
		child->leftChild = parent;
	}
	updateParent(child);
	updateParent(parent);
}

void splay(TreeElement *node)
{
	if (!node->parent)
	{
		return;
	}
	auto child = node;
	auto parent = node->parent;
	auto grandparent = parent->parent;
	if (!grandparent)
	{
		rotate(child, parent);
		return;
	}
	if ((parent->leftChild == child) == (grandparent->leftChild == parent))
	{
		rotate(parent, grandparent);
		rotate(child, parent);
	}
	else
	{
		rotate(child, parent);
		rotate(parent, grandparent);
	}
	splay(node);
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
	if (root->key > key)
	{
		return findNode(root->rightChild, key);
	}
	else
	{
		return findNode(root->leftChild, key);
	}
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
	if (root->key > key && root->rightChild)
	{
		return findNode(root->rightChild, key);
	}
	if (root->key < key && root->leftChild)
	{
		return findNode(root->leftChild, key);
	}
	splay(root);
	return root;
}

string getValue(SplayTree *tree, int key)
{
	auto node = findNode(tree->root, key);
	if (node)
	{
		return node->value;
	}
	else return "";
}

bool isHere(SplayTree *tree)
{
	return nullptr == findNode(tree->root);
}

TwoTrees split(SplayTree *tree, int key)
{
	auto root = tree->root;
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
		auto temp = root->rightChild;
		root->rightChild = nullptr;
		setParent(temp, nullptr);
		return{ root, temp };
	}
	else
	{
		auto temp = root->leftChild;
		root->leftChild = nullptr;
		setParent(temp, nullptr);
		return{ temp, root };
	}
}