#pragma once

struct Value
{
	int weight;
	int node1;
	int node2;
};

struct ListElement;

struct Queue;

Queue* createQueue();

Value dequeue(Queue *queue);

void enequeue(Queue *queue, Value value);

ListElement* next(ListElement *element);

ListElement* getHead(Queue *queue);

Value getValue(ListElement *element);

void addToHead(Queue *queue, Value value);

void addAndSort(Queue *queue, Value value);

void deleteQueue(Queue *&queue);

void print(Queue *queue);

void printWithNode(Queue *queue);

void printWithPath(Queue *queue);