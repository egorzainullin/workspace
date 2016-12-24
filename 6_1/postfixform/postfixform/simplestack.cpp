#include "simplestack.h"
#include <iostream>

using namespace std;

struct StackElement
{
	ElementType value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

Stack* createStack()
{
	return new Stack{ nullptr };
}

ElementType getValueFromHead(Stack *stack)
{
	return stack->head->value;
}

void deleteFromHead(Stack *stack)
{
	if (stack->head)
	{
		auto oldHead = stack->head;
		stack->head = stack->head->next;
		delete oldHead;
	}
}

void deleteStack(Stack *&stack)
{
	while (stack->head)
	{
		deleteFromHead(stack);
	}
	delete stack;
}

bool isEmpty(Stack *stack)
{
	return !stack->head;
}

void push(Stack *stack, ElementType value)
{
	auto newElement = new StackElement{ value, stack->head };
	stack->head = newElement;
}

ElementType pop(Stack *stack)
{
	if (stack->head)
	{
		auto oldElement = stack->head;
		auto oldValue = oldElement->value;
		stack->head = stack->head->next;
		delete oldElement;
		return oldValue;
	}
	return ' ';
}

void print(Stack *stack)
{
	auto iterator = stack->head;
	while (iterator)
	{
		cout << iterator->value << endl;
		iterator = iterator->next;
	}
	cout << "===" << endl;
}

void printReversed(Stack *stack)
{
	auto temporaryStack = createStack();
	auto iterator = stack->head;
	while (iterator)
	{
		push(temporaryStack, iterator->value);
		iterator = iterator->next;
	}
	print(temporaryStack);
	deleteStack(temporaryStack);
}

void printRow(Stack *stack)
{
	auto iterator = stack->head;
	while (iterator)
	{
		cout << iterator->value;
		iterator = iterator->next;
	}
	cout << endl << "===" << endl;
}

void printReversedRow(Stack *stack)
{
	auto temporaryStack = createStack();
	auto iterator = stack->head;
	while (iterator)
	{
		push(temporaryStack, iterator->value);
		iterator = iterator->next;
	}
	printRow(temporaryStack);
	deleteStack(temporaryStack);
}

