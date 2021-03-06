#include "simplelist.h"
#include <iostream>

using namespace std;

struct ListElement
{
	ElementType value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List* createList()
{
	return new List{ nullptr };
}

ListElement* next(ListElement *element)
{

	return (element) ? element->next : nullptr;
}

ListElement* getHead(List *list)
{
	return list->head;
}

ElementType getValue(ListElement *element)
{
	return element->value;
}

void changeValue(ListElement *element, ElementType value)
{
	element->value = value;
}

void swapValues(ListElement *element1, ListElement *element2)
{
	swap(element1->value, element2->value);
}

void deleteFromHead(List *list)
{
	if (list->head)
	{
		auto oldHead = list->head;
		list->head = list->head->next;
		delete oldHead;
	}
}

void deleteList(List *&list)
{
	while (list->head)
	{
		deleteFromHead(list);
	}
	delete list;
	list = nullptr;
}

bool isEmpty(List *list)
{
	return !list->head;
}

void push(List *list, ElementType value)
{
	auto newElement = new ListElement{ value, list->head };
	list->head = newElement;
}

void insert(ListElement *position, ElementType value)
{
	auto newElement = new ListElement{ value, position };
	position->next = newElement;
}

ElementType pop(List *list)
{
	if (list->head)
	{
		auto oldElement = list->head;
		auto oldValue = oldElement->value;
		list->head = list->head->next;
		delete oldElement;
		return oldValue;
	}
	return{ "", "" };
}

ElementType remove(ListElement *position)
{
	if ((!position) || (!position->next))
	{
		return{ "", "" };
	}
	auto oldElement = position->next;
	auto oldValue = oldElement->value;
	position->next = position->next->next;
	delete oldElement;
	return oldValue;
}
