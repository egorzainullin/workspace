#pragma once

typedef int ElementType;

//Structures:
// structure of pointer
struct StackElement;
// stack
struct Stack;

//Functions & Procedures:
// stack constructor
Stack* createStack();
//stack destructor;
void deleteStack(Stack *&stack);
// get head of stack
StackElement* getHead(Stack *stack);
//get value by pointer
ElementType getValue(StackElement *element);
//get next element of stack
StackElement* next(StackElement *element);
//delete from head
void deleteFromHead(Stack *stack);
//add element to head
void pushback(Stack *stack, ElementType value);
//insert value
void insert(StackElement *position, ElementType value);
//delete from head and return value
ElementType pop(Stack *stack);
// remove from stack
ElementType remove(StackElement *position);
// print each element on his own line
void print(Stack *stack);
//print int natural order
void printReversed(Stack *stack);
//the same that print but in the row
void print_r(Stack *stack);
//the same that printReversed but in row
void printReversed_r(Stack *stack);


