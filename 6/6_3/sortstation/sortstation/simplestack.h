#pragma once

typedef char ElementType;

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

//check for having elements
bool isEmpty(Stack *stack);

//gets value from head
ElementType getValueFromHead(Stack *stack);

//delete value from head and return
ElementType pop(Stack *stack);

//delete from head
void deleteFromHead(Stack *stack);

//add element to head
void push(Stack *stack, ElementType value);

// print each element on his own line
void print(Stack *stack);

//print int natural order
void printReversed(Stack *stack);

//the same that print but in the row
void printRow(Stack *stack);

//the same that printReversed but in row
void printReversedRow(Stack *stack);


