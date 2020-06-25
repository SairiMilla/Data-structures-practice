#include "SMVector.h"
#include "SMDataStructure.h"
#include <iostream>
#include <cmath>

SMVector::SMVector()
{
	this->array = new int[BASE_SIZE];
	this->capacity = BASE_SIZE;
	this->size = 0;
}

SMVector::SMVector(int capacity)
{
	this->array = new int[capacity];
	this->capacity = capacity;
	this->size = 0;
}

SMVector::SMVector(int startingArray[], int startingArraySize)
{
	this->array = new int[startingArraySize * 2];
	this->capacity = startingArraySize * 2;
	this->size = startingArraySize;

	for (int i = 0; i < size; i++) {
		array[i] = startingArray[i];
	}
}

SMVector::~SMVector()
{
	delete array;
}

void SMVector::resize(int newCapacity)
{
	int* aux = array;
	this->array = new int[newCapacity];
	
	for (int i = 0; i < size; i++) {
		array[i] = aux[i];
	}

	capacity = newCapacity;
	delete aux;
}



int SMVector::getCapacity()
{
	return capacity;
}

int SMVector::getSize()
{
	return size;
}

bool SMVector::isEmpty()
{
	return size ==  0;
}

void SMVector::push(int element)
{
	if (size == capacity){
		resize(capacity * 2);
	}
	array[size] = element;
	size++;
}

void SMVector::prepend(int element)
{
	insert(0, element);
}

int SMVector::pop()
{
	int lastValue = array[size - 1];
	remove(size - 1);
	if (size <= ceil(size / 4)) {
		resize(size / 2);
	}
	return lastValue;
}

int SMVector::get(int index)
{

	return array[index];
}

void SMVector::set(int index, int element)
{
	array[index] = element;
}

void SMVector::insert(int index, int element)
{
	if (size == capacity) {
		resize(capacity * 2);
	}

	for (int i = size; i > index; i--)
	{
			array[i] = array[i - 1];
	}

	array[index] = element;
	size++;
}

void SMVector::remove(int index)
{
	if (index >= size) {
		std::cout << "Out of bounds!";
	}
	else if(index == size - 1) {
		size--;
	}
	else {
		for (int i = index; i < size - 1; i++)
		{
			array[i] = array[i + 1];
		}

		size--;
	}

	if (size <= ceil(size / 4)) {
		resize(size / 2);
	}
}

void SMVector::deleteAll(int element)
{
	int* aux = new int[capacity];

	int i = 0;

	for (int j = 0; j < size; j++)
	{
		if (array[j] != element) {
			aux[i] = array[j];
			i++;
		}
	}

	size = i;

	delete array;

	array = aux;

	if (size <= ceil(capacity / 4)) {
		resize(capacity / 2);
	}
}

int SMVector::firstIndexOf(int element)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == element) {
			return i;
		}
	}

	return -1;
}

void SMVector::printContents()
{
	std::cout << "Vector size: " << size << ". Capacity: " << capacity << ". Contents:";

	if (size > 0) {
		std::cout << "[";
		for (int i = 0; i < size; i++)
		{
			if (i == 0) {
				std::cout << array[i];
			}
			else
			{
				std::cout << "," << array[i];
			}
		}

		std::cout << "]" << std::endl;
	}
	else
	{
		std::cout << "The vector is empty" << std::endl;

	}
}

int SMVector::getFront()
{
	return array[0];
}

int SMVector::getBack()
{
	return array[size - 1];
}
