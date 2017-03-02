#pragma once

struct Value
{
	int weight;
	int node1;
	int node2;
};

struct ListElement;

struct Queue;

//creates queue
Queue* createQueue();

//remove from queue from head
Value dequeue(Queue *queue);

//add to tail 
void enequeue(Queue *queue, Value value);

//get next element
ListElement* next(ListElement *element);

//gets head of queue
ListElement* getHead(Queue *queue);

//gets value
Value getValue(ListElement *element);

//adds to head
void addToHead(Queue *queue, Value value);

//adds with sort
void addAndSort(Queue *queue, Value value);

//deletes queue
void deleteQueue(Queue *&queue);

//print queue
void print(Queue *queue);

//prints node1
void printWithNode(Queue *queue);

//prints all nodes
void printWithPath(Queue *queue);