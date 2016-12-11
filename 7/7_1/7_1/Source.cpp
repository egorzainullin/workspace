#include <iostream>

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
	auto tree = new Tree{ nullptr };
	return tree;
}

void deleteTree(TreeElement *&root)
{
	if (!root)
	{
		return;
	}
	if (root && !root->leftChild && !root->rightChild)
	{
		delete root;
		root = nullptr;
	}
	else
	{
		deleteTree(root->leftChild);
		deleteTree(root->rightChild);
	}
}

void deleteTree(Tree *&tree)
{
	deleteTree(tree->root);
	delete tree;
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

TreeElement* searchForElement(TreeElement *root, int value)
{
	while (root)
	{
		if (value > root->value)
		{
			root = root->rightChild;
		}
		if (value < root->value)
		{
			root = root->leftChild;
		}
		if (value == root->value)
		{
			return root;
		}
	}
	return nullptr;
}

bool isThere(Tree *tree, int value)
{
	return searchForElement(tree->root, value);
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
		if  (!node->rightChild)
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
		if (node->value < value)
		{
			remove(node->rightChild, value);
		}
	}
}

void remove(Tree *tree, int value)
{
	remove(tree->root, value);
}

int main()
{
	auto tree = createTree();
	insert(tree, 1);
	insert(tree, 2);
	insert(tree, 0);
	insert(tree, 1);
	insert(tree, 6);
	insert(tree, 7);
	insert(tree, 7);
	insert(tree, 5);
	preorder(tree);
	cout << searchForElement(tree->root, 1) << endl;
	remove(tree, 2);
	preorder(tree);
	deleteTree(tree);
	return 0;
}