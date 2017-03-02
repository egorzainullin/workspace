#include <iostream>
#include "binarytree.h"

using namespace std;

struct TreeElement
{
	int value;
	TreeElement *leftChild;
	TreeElement *rightChild;
};

struct Tree
{
	TreeElement *root;
};

Tree* createTree()
{
	return new Tree{ nullptr };
}

void deleteTree(TreeElement *&root)
{
	if (!root)
	{
		return;
	}
	delete(root->leftChild);
	delete(root->rightChild);
	delete root;
}

void deleteTree(Tree *&tree)
{
	deleteTree(tree->root);
	delete tree;
	tree = nullptr;
}

void preorder(TreeElement *root)
{
	if (root)
	{
		cout << root->value << " ";
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void preorder(Tree *tree)
{
	preorder(tree->root);
	cout << endl << "===" << endl;
}

void printInIncreasingOrder(TreeElement *root)
{
	if (root)
	{
		printInIncreasingOrder(root->leftChild);
		cout << root->value << " ";
		printInIncreasingOrder(root->rightChild);
	}
}

void printInIncreasingOrder(Tree *tree)
{
	printInIncreasingOrder(tree->root);
	cout << endl << "===" << endl;
}

void printInDecreasingOrder(TreeElement *root)
{
	if (root)
	{
		printInDecreasingOrder(root->rightChild);
		cout << root->value << " ";
		printInDecreasingOrder(root->leftChild);
	}
}

void printInDecreasingOrder(Tree *tree)
{
	printInDecreasingOrder(tree->root);
	cout << endl << "===" << endl;
}

TreeElement* searchForElement(TreeElement *root, int value)
{
	while (root)
	{
		if (value > root->value)
		{
			root = root->rightChild;
		}
		else if (value < root->value)
		{
			root = root->leftChild;
		}
		else if (value == root->value)
		{
			return root;
		}
	}
	return nullptr;
}

bool isThere(Tree *tree, int value)
{
	return searchForElement(tree->root, value) != nullptr;
}

void insert(Tree *tree, int value)
{
	if (!tree->root)
	{
		tree->root = new TreeElement{ value, nullptr, nullptr };
		return;
	}
	auto root = tree->root;
	while (root)
	{
		if (value > root->value)
		{
			if (!root->rightChild)
			{
				auto newElement = new TreeElement{ value, nullptr, nullptr };
				root->rightChild = newElement;
				return;
			}
			root = root->rightChild;
		}
		else if (value < root->value)
		{
			if (!root->leftChild)
			{
				auto newElement = new TreeElement{ value, nullptr, nullptr };
				root->leftChild = newElement;
				return;
			}
			root = root->leftChild;
		}
		else if (value == root->value)
		{
			return;
		}
	}
}

TreeElement* findNearest(TreeElement* node)
{
	if (node)
	{
		node = node->leftChild;
	}
	while (node->rightChild)
	{
		node = node->rightChild;
	}
	return node;
}

void remove(TreeElement *&node, int value)
{
	if (node && node->value == value)
	{
		if (!node->leftChild && !node->rightChild)
		{
			delete node;
			node = nullptr;
			return;
		}
		if (!node->leftChild)
		{
			auto oldElement = node;
			node = node->rightChild;
			delete oldElement;
			return;
		}
		if (!node->rightChild)
		{
			auto oldElement = node;
			node = node->leftChild;
			delete oldElement;
			return;
		}
		auto replaced = findNearest(node);
		node->value = replaced->value;
		remove(node->leftChild, replaced->value);
	}
	else if (node)
	{
		if (node->value > value)
		{
			remove(node->leftChild, value);
		}
		else if (node->value < value)
		{
			remove(node->rightChild, value);
		}
	}
}

void remove(Tree *tree, int value)
{
	remove(tree->root, value);
}