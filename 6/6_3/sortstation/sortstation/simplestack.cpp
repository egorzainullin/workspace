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

StackElement* next(StackElement *element)
{
	
	return (element) ? element->next : nullptr;
}

StackElement* getHead(Stack *stack)
{
	return stack->head;
}

ElementType getValue(StackElement *element)
{
	return element->value;
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

void pushback(Stack *stack, ElementType value)
{
	auto newElement = new StackElement{ value, stack->head };
	stack->head = newElement;
}

void insert(StackElement *position, ElementType value)
{
	auto newElement = new StackElement{ value, position };
	position->next = newElement;
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

ElementType remove(StackElement *position)
{
	if ((!position) || (!position->next))
	{
		return ' ';
	}
	auto oldElement = position->next;
	auto oldValue = oldElement->value;
	position->next = position->next->next;
	delete oldElement;
	return oldValue;
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
		pushback(temporaryStack, iterator->value);
		iterator = iterator->next;
	}
	print(temporaryStack);
	deleteStack(temporaryStack);
}

void print_r(Stack *stack)
{
	auto iterator = stack->head;
	while (iterator)
	{
		cout << iterator->value;
		iterator = iterator->next;
	}
	cout << endl << "===" << endl;
}

void printReversed_r(Stack *stack)
{
	auto temporaryStack = createStack();
	auto iterator = stack->head;
	while (iterator)
	{
		pushback(temporaryStack, iterator->value);
		iterator = iterator->next;
	}
	print_r(temporaryStack);
	deleteStack(temporaryStack);
}

