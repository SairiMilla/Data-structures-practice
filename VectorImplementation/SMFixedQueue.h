#pragma once
#include <iostream>

class SMFixedQueue
{
private:
	int* array;
	int readIndex;
	int writeIndex;
	int size;
	int capacity;
public:
	SMFixedQueue(int size);
	~SMFixedQueue();
	void enqueue(int element);
	bool isEmpty();
	int front();
	int dequeue();
	void printContents();
};

