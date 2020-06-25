#include "SMDynamicQueue.h"

SMDynamicQueue::SMDynamicQueue()
{
	queue = new SMList();
}

SMDynamicQueue::~SMDynamicQueue()
{
	delete queue;
}

void SMDynamicQueue::enqueue(int element)
{
	queue->push(element);
}

bool SMDynamicQueue::isEmpty()
{
	return queue->isEmpty();
}

int SMDynamicQueue::front()
{
	return queue->getFront();
}

int SMDynamicQueue::dequeue()
{
	return queue->popFront();
}

void SMDynamicQueue::printContents()
{
	queue->printContents();
}
