#pragma once
class SMListNode
{
private:
	SMListNode* next;
	int element;

public:
	SMListNode(int element, SMListNode* next);

	SMListNode* getNext();
	void setNext(SMListNode* newNext);
	int getElement();
	void setElement(int element);
};

