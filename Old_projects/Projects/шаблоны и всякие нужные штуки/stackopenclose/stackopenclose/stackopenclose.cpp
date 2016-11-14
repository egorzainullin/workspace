#include <iostream>
#include <string>

using namespace std;

struct StackElement
{
	bool value;
	StackElement *next;
};

void deleteFromHead(StackElement *&head)
{
	auto oldHead = head;
	if (head)
	{
		head = head->next;
	}
	delete oldHead;
}

void deleteStack(StackElement *&head)
{
	while (head)
	{
		deleteFromHead(head);
	}
	delete head;
}

void add(StackElement *&head, bool value)
{
	auto newElement = new StackElement{ value, head };
	head = newElement;
}

void remove(StackElement *position)
{
	auto oldElement = position->next;
	position->next = position->next->next;
	delete oldElement;
}

void print(StackElement *head)
{
	StackElement *output = nullptr;
	while (head)
	{
		add(output, head->value);
		head = head->next;
	}
	while (output)
	{
		switch (output->value)
		{
		case 0:
			cout << "(";
			break;
		case 1:
			cout << ")";
			break;
		}
		output = output->next;
	}
	cout << endl << "====" << endl;
	deleteStack(output);
}

bool isPair(StackElement *position)
{
	if ((position) && position->next && (position->value) && (!position->next->value))
	{
		return true;
	}
	return false;
}

bool removePair(StackElement *position)
{
	if (position && (isPair(position->next)))
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
	if (!head->next)
	{
		return false;
	}
	if ((head->value) && (!head->next->value))
	{
		return true;
	}
	return false;
}

bool searchForPairs(StackElement *head)
{
	print(head);
	auto iterator = head;
	if ((!head) || (!head->next) || (!head->next->next))
	{
		return lastCheck(head);
	}
	while (iterator && (!isPair(iterator->next)))
	{
		if (iterator)
		{
			iterator = iterator->next;
		}
	}
	if (removePair(iterator))
	{
		return searchForPairs(head);
	}
	return false;
}

int main()
{
	StackElement *head = nullptr;
	string str = "";
	cin >> str;
	for(int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			add(head, false);
		}
		if (str[i] == ')')
		{
			add(head, true);
		}
	}
	print(head);
	cout << searchForPairs(head) << endl;
	deleteStack(head);
	return 0;
}
