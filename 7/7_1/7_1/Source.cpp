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

bool test1()
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
	remove(tree, 6);
	auto root = tree->root;
	bool b = isThere(tree, 1) && root->value == 1 && root->leftChild->value == 0;
	bool a = root->rightChild->value == 2 && root->rightChild->rightChild->value == 5 && root->rightChild->rightChild->rightChild->value == 7;
	deleteTree(tree);
	return a && b;
}

int main()
{
	cout << test1() << endl;
	auto tree = createTree();
	char c = ' ';
	int value = 0;
	while (c != '0')
	{
		cout << "0 to exit" << endl;
		cout << "1 to add" << endl;
		cout << "2 to delete" << endl;
		cout << "3 to print in increasing order" << endl;
		cout << "4 to print in decreasing order" << endl;
		cout << "5 to check is element in tree" << endl;
		cout << "===" << endl;
		cin >> c;
		switch (c)
		{
		case '0':
			break;
		case '1':
			cin >> value;
			insert(tree, value);
			break;
		case '2':
			cin >> value;
			remove(tree, value);
			break;
		case '3':
			printInIncreasingOrder(tree);
			break;
		case '4':
			printInDecreasingOrder(tree);
		case '5':
			cin >> value;
			cout << isThere(tree, value) << endl;
			break;
		default:
			break;
		}
	}
	deleteTree(tree);
	return 0;
}