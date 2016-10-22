#include <iostream>
#include <string>
#include "simplestack.h"

using namespace std;

bool isPair(StackElement *position)
{
	if (position && next(position) && getValue(position) == ')' && getValue(next(position)) == '(')
	{
		return true;
	}
	if (position && next(position) && getValue(position) == '}' && getValue(next(position)) == '{')
	{
		return true;
	}
	if (position && next(position) && getValue(position) == ']' && getValue(next(position)) == '[')
	{
		return true;
	}
	return false;
}

bool removePair(StackElement *position)
{
	if (position && (isPair(next(position))))
	{
		remove(position);
		remove(position);
		return true;
	}
	return false;
}

bool lastCheck(StackElement *head)
{
	if (!head)
	{
		return true;
	}
	if (!next(head))
	{
		return false;
	}
	if (getValue(head) == ')' && getValue(next(head)) == '(')
	{
		return true;
	}
	if (getValue(head) == '}' && getValue(next(head)) == '{')
	{
		return true;
	}
	if (getValue(head) == ']' && getValue(next(head)) == '[')
	{
		return true;
	}
	return false;
}

bool searchForPairs(Stack *stack)
{
	auto head = getHead(stack);
	printReversed_r(stack);
	auto iterator = head;
	if ((!head) || (!next(head)) || (!next(next(head))))
	{
		return lastCheck(head);
	}
	while (iterator && (!isPair(next(iterator))))
	{
		if (iterator)
		{
			iterator = next(iterator);
		}
	}
	if (removePair(iterator))
	{
		return searchForPairs(stack);
	}
	return false;
}

Stack* stringToStack(string str)
{
	auto stack = createStack();
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			pushback(stack, '(');
		}
		if (str[i] == ')')
		{
			pushback(stack, ')');
		}
		if (str[i] == '{')
		{
			pushback(stack, '{');
		}
		if (str[i] == '}')
		{
			pushback(stack, '}');
		}
		if (str[i] == '[')
		{
			pushback(stack, '[');
		}
		if (str[i] == ']')
		{
			pushback(stack, ']');
		}
	}
	return stack;
}

bool test1()
{
	string str1 = "{{[]}}()";
	string str2 = "((}}";
	auto stack1 = stringToStack(str1);
	auto stack2 = stringToStack(str2);
	bool testResult = searchForPairs(stack1) && !searchForPairs(stack2);
	deleteStack(stack1);
	deleteStack(stack2);
	return testResult;
}

int main()
{
	string str = "";
	cin >> str;
	auto stack = stringToStack(str);
	printReversed_r(stack);
	cout << searchForPairs(stack) << endl;
	deleteStack(stack);
	cout << endl;
	cout << "launching test: " << test1() << endl;
	return 0;
}