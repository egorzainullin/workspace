#include <iostream>
#include "binarytree.h"

using namespace std;

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
	bool b = isThere(tree, 1) && !isThere(tree, 6);
	deleteTree(tree);
	return b;
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
			break;
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