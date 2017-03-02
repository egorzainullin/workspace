#include "graphqueue.h"
#include <iostream>

using namespace std;

struct ListElement
{
	Value value;
	ListElement *next;
};

struct Queue
{
	ListElement *head;
	ListElement *tail;
};

Queue* createQueue()
{
	return new Queue{ nullptr, nullptr };
}

Value dequeue(Queue *queue)
{
	if (!queue || !queue->head)
	{
		return{ 0, 0, 0 };
	}
	auto oldElement = queue->head;
	auto oldValue = queue->head->value;
	if (queue->head == queue->tail)
	{
		delete queue->head;
		queue->head = nullptr;
		queue->tail = nullptr;
		return oldValue;
	}
	queue->head = queue->head->next;
	delete oldElement;
	return oldValue;
}

void enequeue(Queue *queue, Value value)
{
	if (!queue->head)
	{
		auto newElement = new ListElement{ value, nullptr };
		queue->head = newElement;
		queue->tail = newElement;
		return;
	}
	auto newElement = new ListElement{ value, nullptr };
	queue->tail->next = newElement;
	queue->tail = newElement;
}

ListElement* next(ListElement *element)
{
	return element->next;
}

Value getValue(ListElement *element)
{
	return element->value;
}

ListElement* getHead(Queue *queue)
{
	return queue->head;
}

void addToHead(Queue *queue, Value value)
{
	if (!queue->head)
	{
		auto newElement = new ListElement{ value, nullptr };
		queue->head = newElement;
		queue->tail = newElement;
		return;
	}
	auto newElement = new ListElement{ value, queue->head };
	queue->head = newElement;
}

void addAndSort(Queue *queue, Value value)
{
	addToHead(queue, value);
	auto iterator = queue->head;
	while (iterator->next && iterator->value.weight > iterator->next->value.weight)
	{
		swap(iterator->value, iterator->next->value);
		iterator = iterator->next;
	}
}

void deleteQueue(Queue *&queue)
{
	while (queue->head)
	{
		dequeue(queue);
	}
	delete queue;
	queue = nullptr;
}

void print(Queue *queue)
{
	auto head = queue->head;
	while (head)
	{
		cout << head->value.weight << " ";
		head = head->next;
	}
	cout << endl;
}

void printWithNode(Queue *queue)
{
	auto head = queue->head;
	while (head)
	{
		cout << head->value.node1 << " ";
		head = head->next;
	}
	cout << endl;
}

void printWithPath(Queue *queue)
{
	cout << "===" << endl;
	auto head = queue->head;
	while (head)
	{
		cout << head->value.node1 << " " << head->value.node2 << " (" << head->value.weight << ")";
		cout << endl;
		head = head->next;
	}
	cout << endl;
}
