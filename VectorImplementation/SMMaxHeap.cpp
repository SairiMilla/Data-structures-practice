#include "SMMaxHeap.h"
#include <algorithm> 
#include <iostream>

using namespace std;

void SMMaxHeap::siftUp(int elementIndex)
{
	int parent;
	while (elementIndex > 0 && heapArr[parent = getParent(elementIndex)] < heapArr[elementIndex]) {
		swap(heapArr[parent], heapArr[elementIndex]);
		elementIndex = parent;
	}
}

void SMMaxHeap::siftDown(int elementIndex)
{
	siftDown(heapArr, elementIndex, size);
}

int SMMaxHeap::getParent(int elementIndex)
{
	return (elementIndex - 1) / 2;
}

int SMMaxHeap::getChild(int elementIndex, int leftRight)
{
	return (2 * elementIndex) + leftRight;
}

void SMMaxHeap::siftDown(int* array, int elementIndex, int heapSize)
{
	int maxIndex = elementIndex;
	int currentIndex = 0;
	do {
		currentIndex = maxIndex;
		int leftChild = getChild(currentIndex, LEFT_CHILD);

		if (leftChild < heapSize && array[leftChild] > array[maxIndex]) {
			maxIndex = leftChild;
		}

		int rightChild = getChild(currentIndex, RIGHT_CHILD);

		if (rightChild < heapSize && array[rightChild] > array[maxIndex]) {
			maxIndex = rightChild;
		}

		if (currentIndex != maxIndex) {
			swap(array[currentIndex], array[maxIndex]);
		}
	} while (currentIndex != maxIndex);
}

SMMaxHeap::SMMaxHeap(int* array, int arraySize)
{
	heapArr = new int[arraySize];
	size = arraySize;
	capacity = arraySize;

	for (int i = 0; i < arraySize; i++)
	{
		heapArr[i] = array[i];
	}

	heapify(heapArr, size);
}

SMMaxHeap::SMMaxHeap(int capacity)
{
	heapArr = new int[capacity];
	size = 0;
	this->capacity = capacity;
}

SMMaxHeap::~SMMaxHeap()
{
	delete heapArr;
}

void SMMaxHeap::insert(int element)
{
	if (size < capacity) {
		heapArr[size] = element;
		siftUp(size);
		size++;
	}
}

int SMMaxHeap::getMax()
{
	return heapArr[0];
}

int SMMaxHeap::getSize()
{
	return size;
}

int SMMaxHeap::extractMax()
{
	int maxValue = heapArr[0];
	heapArr[0] = heapArr[size - 1];
	size--;
	siftDown(0);
	return maxValue;
}

bool SMMaxHeap::isEmpty()
{
	return size == 0;
}

void SMMaxHeap::remove(int elementIndex)
{
	heapArr[elementIndex] = INT_MAX;
	siftUp(elementIndex);
	extractMax();
}

void SMMaxHeap::heapify(int* array, int size)
{
	int firstNonLeaf = (size / 2) - 1;

	for (int i = firstNonLeaf; i >= 0; i--) {
		siftDown(array, i, size);
	}
}

void SMMaxHeap::heapSort(int* array, int size)
{
	heapify(array, size);

	while (size > 0) {
		swap(array[0], array[--size]);
		siftDown(array, 0, size);
	}

}

void SMMaxHeap::changePriority(int elementIndex, int newPriority)
{
	int currentPriority = heapArr[elementIndex];
	heapArr[elementIndex] = newPriority;
	if (newPriority > currentPriority) {
		siftUp(elementIndex);
	}
	else {
		siftDown(elementIndex);
	}
}

void SMMaxHeap::printContents()
{
	std::cout << "Heap size: " << size << ". Capacity: " << capacity << ". Contents:";

	if (size > 0) {
		std::cout << "[";
		for (int i = 0; i < size; i++)
		{
			if (i == 0) {
				std::cout << heapArr[i];
			}
			else
			{
				std::cout << "," << heapArr[i];
			}
		}

		std::cout << "]" << std::endl;
	}
	else
	{
		std::cout << "The heap is empty" << std::endl;

	}
}
