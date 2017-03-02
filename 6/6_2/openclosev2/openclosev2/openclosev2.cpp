#include <iostream>
#include <string>
#include "simplestack.h"

using namespace std;

bool checkPairs(string str)
{
	auto stack = createStack();
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			push(stack, str[i]);
		}
		if (str[i] == ')')
		{
			if (pop(stack) != '(')
			{
				return false;

			}
		}
		if (str[i] == '}')
		{
			if (pop(stack) != '{')
			{
				return false;
			}
		}
		if (str[i] == ']')
		{
			if (pop(stack) != '[')
			{
				return false;
			}
		}
	}
	return isEmpty(stack);
}

bool test1()
{
	string str1 = "{{}}[]()";
	string str2 = "[[)";
	return checkPairs(str1) && !checkPairs(str2);
}

int main()
{
	string str = "";
	cin >> str;
	cout << checkPairs(str) << endl;
	cout << "Test: " << test1() << endl;
	return 0;
}