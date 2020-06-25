#pragma once
#include "SMHashMapElement.h"

class SMStaticHashMap
{
private:
	SMHashMapElement* array;
	int r;
	int size;
	int capacity;

	const long long int PARAMETER_S = 2654435769L;
	const long long int TWO_TO_W = 4294967296L;
	int hash(int key);

public:
	SMStaticHashMap(int size);
	~SMStaticHashMap();
	void add(int key, int element);
	bool exists(int key);
	int get(int key);
	void remove(int key);
	void printContents();
};

