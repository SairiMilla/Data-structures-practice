#include "SMStack.h"

SMStack::SMStack()
{
	stack = new SMList();
}

SMStack::~SMStack()
{
	delete stack;
}

void SMStack::push(int element)
{
	stack->push(element);
}

int SMStack::pop()
{
	return stack->popBack();
}

int SMStack::top()
{
	return stack->getBack();
}

bool SMStack::isEmpty()
{
	return stack->isEmpty();
}

void SMStack::printContents()
{
	stack->printContents();
}
