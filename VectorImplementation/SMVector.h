#pragma once
#include "SMDataStructure.h"

class SMVector : public SMDataStructure
{
private:
	const int BASE_SIZE = 16;
	int* array;
	int capacity;

	void resize(int newCapacity);

public:
	SMVector();
	SMVector(int capacity);
	SMVector(int startingArray[], int startingArraySize);
	~SMVector();

	int getCapacity();

	int getSize();
	bool isEmpty();
	void push(int element);
	void prepend(int element);
	int pop();
	int get(int index);
	void set(int index, int element);
	void insert(int index, int element);
	void remove(int index);
	void deleteAll(int element);
	int firstIndexOf(int element);
	void printContents();
	int getFront();
	int getBack();
};

