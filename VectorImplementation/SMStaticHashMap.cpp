#include "SMStaticHashMap.h"
#include "SMHashMapElement.h"
#include <math.h>   
#include <iostream>


SMStaticHashMap::SMStaticHashMap(int size)
{
	r = log2(size);
	this->capacity = 1 << (r + 1);

	array = new SMHashMapElement[capacity];
	this->size = 0;
}

SMStaticHashMap::~SMStaticHashMap()
{
	delete array;
}

void SMStaticHashMap::add(int key, int element)
{
	int hashValue = hash(key);

	std::cout << "adding " << key <<  std::endl;

	for (int i = 0; i < capacity; i++)
	{
		int probe = ((hashValue + i) % capacity);
		std::cout << "probe " << probe << std::endl;

		if (array[probe].isPresent()) {
			if (array[probe].getKey() == key) {
				array[probe].setValue(element);
				array[probe].setPresent(true);
				size++;
				break;
			}
		}
		else {
			SMHashMapElement element(key, element);
			array[probe] = element;
			size++;
			break;
		}
	}
}

bool SMStaticHashMap::exists(int key)
{
	int hashValue = hash(key);
	for (size_t i = 0; i < capacity; i++)
	{
		int probe = (hashValue + i) % capacity;
		if (array[probe].getKey() == key && array[probe].isPresent()) {
			return true;
		}
	}

	return false;
}

int SMStaticHashMap::get(int key)
{
	int hashValue = hash(key);
	for (size_t i = 0; i < capacity; i++)
	{
		int probe = (hashValue + i) % capacity;
		if (array[probe].getKey() == key && array[probe].isPresent()) {
			return array[probe].getValue();
		}
	}
	return 0;
}

void SMStaticHashMap::remove(int key)
{
	int hashValue = hash(key);
	for (size_t i = 0; i < capacity; i++)
	{
		int probe = (hashValue + i) % capacity;
		if (array[probe].getKey() == key) {
			array[probe].setPresent(false);
			size--;
		}
	}
}

void SMStaticHashMap::printContents()
{
	std::cout << "Map size: " << size << " Contents:";
	bool first = true;
	if (size > 0) {
		std::cout << "{";
		for (int i = 0; i < size; i++)
		{
			if (array[i].isPresent()) {
				if (first) {
					std::cout << "[" << array[i].getKey() << "," << array[i].getValue() << "]";
					first = false;
				}
				else
				{
					std::cout << ", [" << array[i].getKey() << "," << array[i].getValue() << "]";
				}
			}
		}

		std::cout << "}" << std::endl;
	}
	else
	{
		std::cout << "The vector is empty" << std::endl;

	}
}


int SMStaticHashMap::hash(int key)
{
	int hashValue = (PARAMETER_S * key) >> (32 - r);

	std::cout << "Hash: " << hashValue << ". index: " << hashValue % capacity << std::endl;

	return hashValue % capacity;
}
