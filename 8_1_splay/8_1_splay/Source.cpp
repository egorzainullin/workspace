#include <iostream>
#include <string>
#include "splaytree.h"

using namespace std;

bool test1()
{
	auto tree = createSplay();
	insert(tree, 1, "1");
	insert(tree, 6, "2");
	cout << isHere(tree, 1) << endl;
	insert(tree, 77, "3");
	insert(tree, 8, "4");
	insert(tree, 9, "5");
	insert(tree, 10, "6");
	insert(tree, 11, "7");
	remove(tree, 5);
	cout << getValue(tree, 9) << endl;
	cout << endl;
	preorder(tree);
	bool b = isHere(tree, 1) && !isHere(tree, 5);
	deleteTree(tree);
	return b;
}

int main()
{
	cout << test1() << endl;
	return 0;
}