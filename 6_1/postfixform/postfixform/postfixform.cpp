// postfixform.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
#include "simplestack.h"

using namespace std;

int charToInt(char c)
{
	return static_cast<int>(c) - static_cast<int>('0');
}

int countThis(int a, int b, char op)
{
	int res = 0;
	if (op == '+')
	{
		res = a + b;
	}
	else if (op == '-')
	{
		res = a - b;
	}
	else if (op ==  '*')
	{
		res = a * b;
	}
	else if (op == '/')
	{
		res = a / b;
	}
	return res;
}

int solvePostfixForm(string str)
{
	auto stack = createStack();
	int length = str.size();
	for (int i = 0; i < length; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			push(stack, charToInt(str[i]));
		}
		else
		{
			int b = pop(stack);
			int a = pop(stack);
			int newValue = countThis(a, b, str[i]);
			push(stack, newValue);
		}
	}
	return getHead(stack) ? pop(stack) : 0;
	deleteStack(stack);
}

bool test1()
{
	string str = "96-21+*";
	return solvePostfixForm(str) == 9;
}

int main()
{
	string str = "";
	cout << "Type expression in postfix form" << endl;
	cin >> str;
	cout << solvePostfixForm(str) << endl;
	cout << "test accepted: " << test1() << endl;
	return 0;
}

