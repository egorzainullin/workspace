#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct TreeElement
{
	string value;
	TreeElement *leftChild;
	TreeElement *rightChild;
};

int toInt(const string str)
{
	int length = static_cast<int>(str.size());
	int sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum = sum * 10 + static_cast<int>(str[i]) - static_cast<int>('0');
	}
	return sum;
}

TreeElement* createTree(const string str)
{
	int length = str.size();
	if (str[0] != '(')
	{
		return new TreeElement{ str, nullptr, nullptr };
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
	return new TreeElement{ op, createTree(leftOperand), createTree(rightOperand) };
}

int calculate(TreeElement *root)
{
	if (root->value == "+")
	{
		return calculate(root->leftChild) + calculate(root->rightChild);
	}
	if (root->value == "-")
	{
		return calculate(root->leftChild) - calculate(root->rightChild);
	}
	if (root->value == "*")
	{
		return calculate(root->leftChild) * calculate(root->rightChild);
	}
	if (root->value == "/")
	{
		return calculate(root->leftChild) / calculate(root->rightChild);
	}
	return toInt(root->value);
}

void deleteTree(TreeElement *&root)
{
	if (root)
	{
		deleteTree(root->leftChild);
		deleteTree(root->rightChild);
		delete root;
	}
}

void preorder(TreeElement *root)
{
	if (root)
	{
		bool isOperator = root->value == "+" || root->value == "-" || root->value == "*" || root->value == "/";
		if (isOperator)
		{
			cout << "(";
		}
		cout << root->value << " ";
		preorder(root->leftChild);
		preorder(root->rightChild);
		if (isOperator)
		{
			cout << ") ";
		}
	}
}

void print(TreeElement *tree)
{
	preorder(tree);
	cout << endl;
}

TreeElement *createTreeFromFile()
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
