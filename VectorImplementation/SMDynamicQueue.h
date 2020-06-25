#pragma once
#include "SMList.h"
class SMDynamicQueue
{
private:
	SMList* queue;

public:
	SMDynamicQueue();
	~SMDynamicQueue();
	void enqueue(int element);
	bool isEmpty();
	int front();
	int dequeue();
	void printContents();
};

