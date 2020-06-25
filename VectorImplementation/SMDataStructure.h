#pragma once

class SMDataStructure
{
protected:
	int size;

public:
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void push(int index) = 0;
	virtual void prepend(int element) = 0;
	virtual int get(int index) = 0;
	virtual void set(int index, int element) = 0;
	virtual void insert(int index, int element) = 0;
	virtual void remove(int index) = 0;
	virtual void deleteAll(int element) = 0;
	virtual int firstIndexOf(int element) = 0;
	virtual void printContents() = 0;
	virtual int getFront() = 0;
	virtual int getBack() = 0;

};

