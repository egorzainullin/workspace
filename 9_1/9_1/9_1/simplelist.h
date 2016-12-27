#pragma once
#include <string>

typedef std::string ElementType;

//Structures:

// structure of pointer
struct ListElement;

//list 
struct List;

//Functions & Procedures:

// list constructor
List* createList();

//list destructor;
void deleteList(List *&list);

//check for having elements
bool isEmpty(List *list);

//get element count
int getCount(ListElement *element);

// get head of stack
ListElement* getHead(List *list);

//get value by pointer
ElementType getValue(ListElement *element);

// change value
void changeValue(ListElement *element, ElementType value);

//swap values element1 element2
void swapValues(ListElement *element1, ListElement *element2);

//get next element of list
ListElement* next(ListElement *element);

//delete from head
void deleteFromHead(List *list);

//add element to head
void push(List *list, ElementType value);

//insert value
void insert(ListElement *position, ElementType value);

//delete from head and return value
ElementType pop(List *list);

// remove from stack
ElementType remove(ListElement *position);

//increase count
void increaseCount(ListElement *element);

//counting length of list
int listLength(List* list);

//print list
void print(List *list);