#include "SMListNode.h"

SMListNode::SMListNode(int element, SMListNode* next)
{
	this->element = element;
	this->next = next;
}

SMListNode* SMListNode::getNext()
{
	return next;
}

void SMListNode::setNext(SMListNode* newNext)
{
	this->next = newNext;
}

int SMListNode::getElement()
{
	return this->element;
}

void SMListNode::setElement(int element)
{
	this->element = element;
}
