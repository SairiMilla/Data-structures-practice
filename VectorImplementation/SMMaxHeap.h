#pragma once
class SMMaxHeap
{
private:
	const int LEFT_CHILD = 1;
	const int RIGHT_CHILD = 2;

	int* heapArr;
	int size;
	int capacity;

	void siftUp(int elementIndex);
	void siftDown(int elementIndex);
	int getParent(int elementIndex);
	int getChild(int elementIndex, int leftRight);
	void siftDown(int* array, int elementIndex, int heapSize);

public:
	SMMaxHeap(int* array, int arraySize);
	SMMaxHeap(int capacity);
	~SMMaxHeap();

	void insert(int element);
	int getMax();
	int getSize();
	int extractMax();
	bool isEmpty();
	void remove(int elementIndex);
	void heapify(int* array, int size);
	void heapSort(int* array, int size);
	void changePriority(int elementIndex, int newPriority);

	void printContents();
};

