#include <iostream>
#include <string>
#include <fstream>
#include "ariphmetictree.h"

using namespace std;

int toInt(const string &str)
{
	int length = static_cast<int>(str.size());
	int sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum = sum * 10 + static_cast<int>(str[i]) - static_cast<int>('0');
	}
	return sum;
}

Tree* createTree(const string &str)
{
	int length = str.size();
	auto tree = createTree();
	if (str[0] != '(')
	{
		auto root = createTreeElement(str);
		setRoot(tree, root);
		return tree;
	}
	string op = "";
	op += str[1];
	string leftOperand = "";
	string rightOperand = "";
	if (str[3] != '(')
	{
		int i = 3;
		while (str[i] != ' ')
		{
			leftOperand += str[i];
			++i;
		}
		for (auto j = i + 1; j < length - 1; ++j)
		{
			rightOperand += str[j];
		}
	}
	if (str[3] == '(')
	{
		leftOperand = "(";
		int i = 4;
		int openingBracketsCount = 1;
		int closingBracketsCount = 0;
		while (openingBracketsCount > closingBracketsCount)
		{
			if (str[i] == '(')
			{
				++openingBracketsCount;
			}
			else if (str[i] == ')')
			{
				++closingBracketsCount;
			}
			leftOperand += str[i];
			++i;
		}
		for (auto j = i + 1; j < length - 1; ++j)
		{
			rightOperand += str[j];
		}
	}
	auto root = createTreeElement(op);
	setLeftChild(root, getRoot(createTree(leftOperand)));
	setRightChild(root, getRoot(createTree(leftOperand)));
	setRoot(tree, root);
	return tree;
}

int calculate(TreeElement *root)
{
	if (getValue(root) == "+")
	{
		return calculate(getLeftChild(root)) + calculate(getRightChild(root));
	}
	if (getValue(root) == "-")
	{
		return calculate(getLeftChild(root)) - calculate(getRightChild(root));
	}
	if (getValue(root) == "*")
	{
		return calculate(getLeftChild(root)) * calculate(getRightChild(root));
	}
	if (getValue(root) == "/")
	{
		return calculate(getLeftChild(root)) / calculate(getRightChild(root));
	}
	return toInt(getValue(root));
}

int calculate(Tree *tree)
{
	return calculate(getRoot(tree));
}


void preorder(TreeElement *root)
{
	if (root)
	{
		bool isOperator = getValue(root) == "+" || getValue(root) == "-" || getValue(root) == "*" || getValue(root) == "/";
		if (isOperator)
		{
			cout << "(";
		}
		cout << getValue(root) << " ";
		preorder(getLeftChild(root));
		preorder(getRightChild(root));
		if (isOperator)
		{
			cout << ") ";
		}
	}
}

void preorder(Tree *tree)
{
	preorder(getRoot(tree));
}

void print(Tree *tree)
{
	preorder(tree);
	cout << endl;
}

Tree *createTreeFromFile()
{
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "error" << endl;
		return nullptr;
	}
	string str = "";
	getline(file, str);
	file.close();
	auto tree = createTree(str);
	return tree;
}

bool test1()
{
	auto tree = createTreeFromFile();
	print(tree);
	cout << endl;
	int b = calculate(tree);
	cout << b << endl;
	deleteTree(tree);
	return b == 4;
}

int main()
{
	cout << test1() << endl;
	return 0;
}
