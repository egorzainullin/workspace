// Listfirst.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void add(ListElement *&head, int value)
{
	auto newElement = new ListElement{ value , head };
	head = newElement;
}

void sort(ListElement *head)

{
	ListElement *sortingElement = head;
	while ((sortingElement->next != nullptr) && (sortingElement->value > sortingElement->next->value))
	{
		int special = sortingElement->value;
		sortingElement->value = sortingElement->next->value;
		sortingElement->next->value = special;
		sortingElement = sortingElement->next;
	}
}

void deleteFromHead(ListElement *&head)
{
	if (head != nullptr)
	{
		ListElement *oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		deleteFromHead(head);
	}
}

void remove(ListElement *&head, int value)
{
	if (head != nullptr)
	{
		while ((head !=nullptr) && (head->value == value))
		{
			deleteFromHead(head);
		}
	}
	while ((head != nullptr) && (head->next != nullptr))
	{
		if (head->next->value == value)
		{
			ListElement *old = head->next;
			head->next = head->next->next;
			delete old;
		}
		else
		{
			break;
		}
	}
}

bool test1()
{
	ListElement *head = nullptr;
	add(head, 1);
	add(head, 2);
	add(head, 3);
	add(head, 5);
	remove(head, 5);
	remove(head, 1);
	return ((head->next->value == 2) && (head->value == 3)) ? true : false;
}

void print(ListElement *head)
{
	cout << "===" << endl;
	ListElement *iterator = head;
	while (iterator != nullptr)
	{
		cout << iterator->value << endl;
		iterator = iterator->next;
	}
	cout << "===" << endl;
}

void menu(ListElement *&head)
{
	char c = ' ';
	int value = 0;
	while (c != '0')
	{
		cout << "0 to exit" << endl;
		cout << "1 to add" << endl;
		cout << "2 to delete" << endl;
		cout << "3 to print" << endl;
		cout << "===" << endl;
		cin >> c;
		switch (c)
		{
		case '0':
			break;
		case '1':
			cin >> value;
			add(head, value);
			sort(head);
			break;
		case '2':
			cin >> value;
			remove(head, value);
			break;
		case '3':
			print(head);
			break;
		default:
			break;
		}
	}
}

int main()
{
	cout << "Test accepted: " << test1() << endl;
	ListElement *head = nullptr;
	menu(head);
	deleteList(head);
	return 0;
}