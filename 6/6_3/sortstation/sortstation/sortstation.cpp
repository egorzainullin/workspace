// sortstation.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	int length = str.size();
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

int main()
{
	string str = "";
	cin >> str;
	auto stack = InfixToPostfix(str);
	printReversedRow(stack);
	return 0;
}

