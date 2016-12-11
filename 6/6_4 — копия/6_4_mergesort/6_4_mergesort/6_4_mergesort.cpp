#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Contact
{
	string name = "";
	string phone = "";
};

struct ListElement
{
	Contact value;
	ListElement *next;
};

void deleteList(ListElement *&head)
{
	while (head)
	{
		auto oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

int length(ListElement *list)
{
	if (!list)
	{
		return 0;
	}
	int i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return i;
}

void addToHead(ListElement *&head, Contact value)
{
	auto newElement = new ListElement{ value, head };
	head = newElement;
}

ListElement* getDataFromFile()
{
	ListElement *head = nullptr;
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
		addToHead(head, contact);
		if (file.eof())
		{
			break;
		}
	}
	file.close();
	return head;
}

void print(ListElement *head)
{
	cout << "===" << endl;
	while (head)
	{
		cout << head->value.name << " " << head->value.phone << endl;
		head = head->next;
	}
	cout << "===" << endl;
}

void print(ListElement *head, bool key)
{
	if (!key)
	{
		print(head);
	}
	else
	{
		cout << "===" << endl;
		while (head)
		{
			cout << head->value.phone << " " << head->value.name << endl;
			head = head->next;
		}
		cout << "===" << endl;
	}
}

ListElement* merge(ListElement *&list1, ListElement *&list2, bool key)
{
	ListElement *list = nullptr;
	if (key)
	{
		while (list1 || list2)
		{
			while (list1 && list2 && list1->value.name < list2->value.name || list1 && !list2)
			{
				addToHead(list, list1->value);
				list1 = list1->next;
			}
			while (list1 && list2 && list1->value.name >= list2->value.name || list2 && !list1)
			{
				addToHead(list, list2->value);
				list2 = list2->next;
			}
		}
	}
	else
	{
		while (list1 || list2)
		{
			while (list1 && list2 && list1->value.phone < list2->value.phone || list1 && !list2)
			{
				addToHead(list, list1->value);
				list1 = list1->next;
			}
			while (list1 && list2 && list1->value.phone >= list2->value.phone || list2 && !list1)
			{
				addToHead(list, list2->value);
				list2 = list2->next;
			}
		}
	}
	deleteList(list1);
	deleteList(list2);
	return list;
}

ListElement* copyListReversed(ListElement *list)
{
	ListElement *tempList = nullptr;
	while (list)
	{
		addToHead(tempList, list->value);
		list = list->next;
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
		left = left->next;
		++i;
	}
	return left;
}

ListElement* mergesort(ListElement *&list, bool key)
{
	if (!list)
	{
		return nullptr;
	}
	if (!list->next)
	{
		return list;
	}
	if (!list->next->next)
	{
		if (key)
		{
			if (list->value.name > list->next->value.name)
			{
				swap(list->value, list->next->value);
			}
		}
		else
		{
			
			if (list->value.phone > list->next->value.phone)
			{
				swap(list->value, list->next->value);
			}
		}
		return list;
	}
	int size = length(list);
	auto edge = findHalf(list, size);
	ListElement *list1 = nullptr;
	ListElement *list2 = nullptr;
	while (list != edge->next)
	{
		addToHead(list1, list->value);
		list = list->next;
	}
	while (list)
	{
		addToHead(list2, list->value);
		list = list->next;
	}
	mergesort(list1, key);
	mergesort(list2, key);
	auto newList = merge(list1, list2, key);
	deleteList(list);
	list = copyListReversed(newList);
	deleteList(newList);
	return list;
}

bool isSorted(ListElement *list, bool key)
{
	if (key)
	{
		while (list && list->next)
		{
			if (list->next->value.name < list->value.name)
			{
				return false;
			}
			list = list->next;
		}
	}
	else
	{
		while (list && list->next)
		{
			if (list->next->value.phone < list->value.phone)
			{
				return false;
			}
			list = list->next;
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
	bool b = list->value.name == "alice" && list->next->value.name == "egor" && list->next->next->value.name == "max";
	deleteList(list);
	return b;
}

int main()
{
	cout << test1() << endl;
	auto phoneList = getDataFromFile();
	cout << "Type 0 if you want to sort by phone, 1 - by name" << endl;
	bool key = false;
	cin >> key;
	print(phoneList);
	mergesort(phoneList, key);
	print(phoneList);
	deleteList(phoneList);
	return 0;
}