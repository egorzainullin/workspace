#include <iostream>
#include <string>
#include "splaytree.h"

using namespace std;

bool test1()
{
	auto tree = createSplay();
	insert(tree, "egor", "18");
	insert(tree, "max", "99");
	cout << getValue(tree, "max") << endl;
	cout << endl;
	insert(tree, "what", "123");
	insert(tree, "free", "651");
	remove(tree, "max");
	preorder(tree);
	bool b = isHere(tree, "egor") && !isHere(tree, "max");
	deleteTree(tree);
	return b;
}

int main()
{
	cout << test1() << endl;
	return 0;
}