// sortstation.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <string>
#include "simplestack.h"

using namespace std;

int operatorPriority(char operatorType)
{
	if (operatorType == '+' || operatorType == '-')
	{
		return 0;
	}
	if (operatorType == '*' || operatorType == '/')
	{
		return 1;
	}
	return -1;
}

Stack* InfixToPostfix(string str)
{
	auto opStack = createStack();
	auto stackOut = createStack();
	int length = static_cast<int>(str.size());
	for (int i = 0; i < length; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			push(stackOut, str[i]);
		}
		else if (str[i] == '(')
		{
			push(opStack, '(');
		}
		else if (str[i] == ')')
		{
			while (getValue(getHead(opStack)) != '(')
			{
				push(stackOut, pop(opStack));
			}
			deleteFromHead(opStack);
		}
		else 
		{
			while (getHead(opStack) && operatorPriority(str[i]) <= operatorPriority(getValue(getHead(opStack))))
			{
				push(stackOut, pop(opStack));
			}
			push(opStack, str[i]);
		}
	}
	while (getHead(opStack))
	{
		push(stackOut, pop(opStack));
	}
	deleteStack(opStack);
	return stackOut;
}

string InfixToPostfixString(string str)
{
	auto stack = InfixToPostfix(str);
	reverseStack(stack);
	string temporaryString = "";
	while (!isEmpty(stack))
	{
		temporaryString = temporaryString + pop(stack);
	}
	return temporaryString;
}

bool test1()
{
	string str = "(1+1)*2";
	str = InfixToPostfixString(str);
	return str == "11+2*";
}

int main()
{
	cout << test1() << endl;
	string str = "";
	cin >> str;
	str = InfixToPostfixString(str);
	cout << str << endl;
	return 0;
}

