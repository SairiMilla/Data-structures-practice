#include "SMFixedQueue.h"

SMFixedQueue::SMFixedQueue(int capacity)
{
	array = new int[capacity];
	readIndex = 0;
	writeIndex = 0;
	size = 0;
	this->capacity = capacity;
}

SMFixedQueue::~SMFixedQueue()
{
	delete array;
}

void SMFixedQueue::enqueue(int element)
{
	if (size < capacity) {
		array[writeIndex] = element;
		size++;
		writeIndex = (writeIndex + 1) % capacity;
	}
	else {
		std::cout << "Queue has reached full capacity!!";
	}
}

bool SMFixedQueue::isEmpty()
{
	return size == 0;
}

int SMFixedQueue::front()
{
	return array[readIndex];
}

int SMFixedQueue::dequeue()
{
	int frontElement = array[readIndex];
	readIndex = (readIndex + 1) % capacity;
	size--;
	return frontElement;
}

void SMFixedQueue::printContents()
{
	std::cout << "Size: " << size << ". Capacity: " << capacity << " Contents:";

	if (size > 0) {
		std::cout << "[";
		for (int i = readIndex, j = 0; j < size; i = (i + 1) % capacity)
		{
			if (j == 0) {
				std::cout << array[i];
			}
			else
			{
				std::cout << "," << array[i];
			}

			j++;
		}

		std::cout << "]" << std::endl;
	}
	else
	{
		std::cout << "The vector is empty" << std::endl;

	}
}
