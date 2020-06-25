#pragma once
#include "SMDataStructure.h"
#include "SMListNode.h"
class SMList :
	public SMDataStructure
{
private:
	SMListNode* head;
	SMListNode* tail;
	int size;

public:
	SMList();
	~SMList();
	int getSize();
	bool isEmpty();
	void push(int element);
	void prepend(int element);
	int popFront();
	int popBack();
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

