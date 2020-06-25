#pragma once
#include "SMList.h"
class SMStack
{
private:
	SMList* stack;

public:
	SMStack();
	~SMStack();
	void push(int element);
	int pop();
	int top();
	bool isEmpty();
	void printContents();
};

