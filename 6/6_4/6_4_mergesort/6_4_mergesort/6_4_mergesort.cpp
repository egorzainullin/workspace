#include <iostream>
#include <fstream>
#include <string>
#include "simplelist.h"

using namespace std;

typedef PhoneNumbers Contact;

int length(List *list)
{
	ListElement *head = getHead(list);
	if (!head)
	{
		return 0;
	}
	int i = 0;
	while (head)
	{
		++i;
		head = next(head);
	}
	return i;
}

//replace addtohead to push

List* getDataFromFile()
{
	List *list = createList();
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "error" << endl;
		return nullptr;
	}
	string name = "";
	string phone = "";
	while (!file.eof())
	{
		Contact contact;
		getline(file, name);
		contact.name = name;
		if (file.eof())
		{
			break;
		}
		getline(file, phone);
		contact.phone = phone;
		push(list, contact);
		if (file.eof())
		{
			break;
		}
	}
	file.close();
	return list;
}

void printContacts(List *list)
{
	cout << "===" << endl;
	ListElement *head = getHead(list);
	while (head)
	{
		string name = getValue(head).name;
		string phone = getValue(head).phone;
		cout << name << " " << phone << endl;
		head = next(head);
	}
	cout << "===" << endl;
}

void printContacts(List *list, bool key)
{
	if (!key)
	{
		printContacts(list);
	}
	else
	{
		cout << "===" << endl;
		ListElement *head = getHead(list);
		while (head)
		{
			string phone = getValue(head).phone;
			string name = getValue(head).name;
			cout << phone << " " << name << endl;
			head = next(head);
		}
		cout << "===" << endl;
	}
}

List* merge(List *&list1, List *&list2, bool key)
{
	List *list = createList();
	ListElement *listElement1 = getHead(list1);
	ListElement *listElement2 = getHead(list2);
	if (key)
	{
		while (listElement1 || listElement2)
		{
			while (listElement1 && listElement2 && getValue(listElement1).name < getValue(listElement2).name || listElement1 && !listElement2)
			{
				push(list, getValue(listElement1));
				listElement1 = next(listElement1);
			}
			while (listElement1 && listElement2 && getValue(listElement1).name >= getValue(listElement2).name || listElement2 && !listElement1)
			{
				push(list, getValue(listElement2));
				listElement2 = next(listElement2);
			}
		}
	}
	else
	{
		while (listElement1 || listElement2)
		{
			while (listElement1 && listElement2 && getValue(listElement1).phone < getValue(listElement2).phone || listElement1 && !listElement2)
			{
				push(list, getValue(listElement1));
				listElement1 = next(listElement1);
			}
			while (listElement1 && listElement2 && getValue(listElement1).phone >= getValue(listElement2).phone || listElement2 && !listElement1)
			{
				push(list, getValue(listElement2));
				listElement2 = next(listElement2);
			}
		}
	}
	deleteList(list1);
	deleteList(list2);
	return list;
}

List* copyListReversed(List *list)
{
	List *tempList = createList();
	ListElement *head = getHead(list);
	while (head)
	{
		push(tempList, getValue(head));
		head = next(head);
	}
	return tempList;
}

ListElement *findHalf(ListElement *left, int size)
{
	if (!left)
	{
		return nullptr;
	}
	int i = 1;
	while (i != (size + 1) / 2)
	{
		left = next(left);
		++i;
	}
	return left;
}

List* mergesort(List *&list, bool key)
{
	ListElement *head = getHead(list);
	if (!head)
	{
		return nullptr;
	}
	if (!next(head))
	{
		return list;
	}
	if (!next(next(head)))
	{
		if (key)
		{
			if (getValue(head).name > getValue(next(head)).name)
			{
				swapValues(head, next(head));
			}
		}
		else
		{
			
			if (getValue(head).phone > getValue(next(head)).phone)
			{
				swapValues(head, next(head));
			}
		}
		return list;
	}
	int size = length(list);
	ListElement *edge = findHalf(head, size);
	List *list1 = createList();
	List *list2 = createList();
	while (head != next(edge))
	{
		push(list1, getValue(head));
		head = next(head);
	}
	while (head)
	{
		push(list2, getValue(head));
		head = next(head);
	}
	mergesort(list1, key);
	mergesort(list2, key);
	List *newList = merge(list1, list2, key);
	deleteList(list);
	list = copyListReversed(newList);
	deleteList(newList);
	return list;
}

bool isSorted(List *list, bool key)
{
	ListElement *head = getHead(list);
	if (key)
	{
		while (head && next(head))
		{
			if (getValue(next(head)).name < getValue(head).name)
			{
				return false;
			}
			head = next(head);
		}
	}
	else
	{
		while (head && next(head))
		{
			if (getValue(next(head)).phone < getValue(head).phone)
			{
				return false;
			}
			head = next(head);
		}
	}
	return true;
}

bool test1()
{
	auto list = getDataFromFile();
	mergesort(list, 0);
	cout << "IsSorted by phone " << isSorted(list, 0) << endl;
	mergesort(list, 1);
	cout << "IsSorted by name " << isSorted(list, 1) << endl;
	ListElement *head = getHead(list);
	bool b = getValue(head).name == "alice" && getValue(next(head)).name == "egor" && getValue(next(next(head))).name == "max";
	deleteList(list);
	return b;
}

int main()
{
	cout << test1() << endl;
	List* phoneList = getDataFromFile();
	cout << "Type 0 if you want to sort by phone, 1 - by name" << endl;
	bool key = false;
	cin >> key;
	printContacts(phoneList);
	mergesort(phoneList, key);
	printContacts(phoneList);
	deleteList(phoneList);
	return 0;
}