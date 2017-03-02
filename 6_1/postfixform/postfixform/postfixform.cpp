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
	int i = 0;
	while (i < length)
	{
		bool isNumber = false;
		int operand = 0;
		while (i < length && str[i] >= '0' && str[i] <= '9')
		{
			isNumber = true;
			int a = charToInt(str[i]);
			operand = operand * 10 + a;
			++i;
		}
		if (isNumber)
		{
			push(stack, operand);
			continue;
		}
		if (i < length && str[i] == ' ')
		{
			++i;
			continue;
		}
		int b = pop(stack);
		int a = pop(stack);
		int newValue = countThis(a, b, str[i]);
		push(stack, newValue);
		++i;
	}
	int answer = 0;
	if (!isEmpty(stack))
	{
		answer = pop(stack);
	}
	return answer;
}

bool test1()
{
	string str = "9 6 - 2 1 + *";
	return solvePostfixForm(str) == 9;
}

int main()
{
	string str = "";
	cout << "Type expression in postfix form" << endl;
	getline(cin, str);
	cout << solvePostfixForm(str) << endl;
	cout << "test accepted: " << test1() << endl;
	return 0;
}

