#include "ariphmetictree.h"
#include <string>

using std::string;

struct TreeElement
{
	string value;
	TreeElement *leftChild;
	TreeElement *rightChild;
};

struct Tree
{
	TreeElement *root;
};

TreeElement* createTreeElement()
{
	return new TreeElement{ "", nullptr, nullptr };
}

TreeElement* createTreeElement(const string &str)
{
	return new TreeElement{ str, nullptr, nullptr };
}

Tree* createTree()
{
	return new Tree{ nullptr };
}

void setRoot(Tree *tree, TreeElement *root)
{
	tree->root = root;
}

void setValue(TreeElement *element, string value)
{
	element->value = value;
}

void deleteTree(TreeElement *&root)
{
	if (root)
	{
		deleteTree(root->leftChild);
		deleteTree(root->rightChild);
		delete root;
		root = nullptr;
	}
}

void deleteTree(Tree *&tree)
{
	deleteTree(tree->root);
	tree = nullptr;
}

TreeElement* getRoot(Tree *tree)
{
	return tree->root;
}

string getValue(TreeElement *root)
{
	return root ? root->value : "";
}

TreeElement* getLeftChild(TreeElement *node)
{
	return node->leftChild;
}

TreeElement* getRightChild(TreeElement *node)
{
	return node->rightChild;
}

void setLeftChild(TreeElement *parent, TreeElement *child)
{
	parent->leftChild = child;
}

void setRightChild(TreeElement *parent, TreeElement *child)
{
	parent->rightChild = child;
}