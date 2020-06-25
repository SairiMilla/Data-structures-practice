#include "SMList.h"
#include <iostream>

void SMList::printContents()
{
	std::cout << "List size: " << size << ". Contents:";

	if (size > 0) {
		std::cout << "[";
		for (SMListNode* currentNode = this->head; currentNode != nullptr; currentNode = currentNode->getNext())
		{
			if (currentNode == this->head) {
				std::cout << currentNode->getElement();
			}
			else {
				std::cout << "," << currentNode->getElement();
			}

		}

		std::cout << "]" << std::endl;
	}
	else
	{
		std::cout << "The list is empty." << std::endl;

	}
}

int SMList::getFront()
{
	return this->head->getElement();
}

int SMList::getBack()
{
	return this->tail->getElement();
}

SMList::SMList()
{
	this->head = nullptr;
	this->tail = nullptr;
	size = 0;
}

SMList::~SMList()
{
	SMListNode* nextNode = this->head;
	while (nextNode != nullptr) {
		SMListNode* currentNode = nextNode;
		nextNode = currentNode->getNext();
		delete currentNode;
	}
}

int SMList::getSize()
{
	return this->size;
}

bool SMList::isEmpty()
{
	return this->size == 0;
}

void SMList::push(int element)
{
	SMListNode* newNode = new SMListNode(element, nullptr);
	if (size == 0) {
		this->head = newNode;
	}
	else {
		this->tail->setNext(newNode);
	}

	this->tail = newNode;

	size++;
}

void SMList::prepend(int element)
{
	SMListNode* newNode = new SMListNode(element, this->head);
	this->head = newNode;

	if (size == 0) {
		this->tail = newNode;
	}

	size++;
}

int SMList::popFront()
{
	SMListNode* headAux = this->head;
	int value = headAux->getElement();

	this->head = headAux->getNext();

	if (size == 1) {
		this->tail = nullptr;
	}

	size--;
	delete headAux;
	return value;
}

int SMList::popBack()
{
	int value;
	value = this->tail->getElement();
	if (size == 1) {
		this->head == nullptr;
		this->tail = nullptr;
	}
	else {
		SMListNode* penultimateNode = this->head;
		while(penultimateNode->getNext() != this->tail)
		{
			penultimateNode = penultimateNode->getNext();
		}
		penultimateNode->setNext(nullptr);
		delete tail;
		this->tail = penultimateNode;
	}
	size--;
	return value;
}

int SMList::get(int index)
{
	int i = 0, value = 0;
	for (SMListNode* currentNode = this->head; currentNode != nullptr; currentNode = currentNode->getNext())
	{
		if (index == i) {
			value = currentNode->getElement();
			break;
		}

		i++;
	}
	return value;
}

void SMList::set(int index, int element)
{
	int i = 0;
	for (SMListNode* currentNode = this->head; currentNode != nullptr; currentNode = currentNode->getNext())
	{
		if (index == i) {
			currentNode->setElement(element);
			break;
		}

		i++;
	}
}

void SMList::insert(int index, int element)
{
	if (index == 0) {
		prepend(element);
	}
	else {
		int i = 0;

		for (SMListNode* currentNode = this->head, *previousNode = nullptr; currentNode != nullptr; currentNode = currentNode->getNext())
		{
			if (index == i) {
				SMListNode* newNode = new SMListNode(element, currentNode);
				previousNode->setNext(newNode);
				break;
			}

			previousNode = currentNode;

			i++;
		}
	}

	size++;
}

void SMList::remove(int index)
{
	if (index == 0) {
		popFront();
	}
	else {
		int i = 0;
		for (SMListNode* currentNode = this->head, *previousNode = nullptr; currentNode != nullptr; currentNode = currentNode->getNext())
		{
			if (index == i) {
				previousNode->setNext(currentNode->getNext());

				delete currentNode;
				break;
			}
			previousNode = currentNode;
			i++;
		}
	}

	size--;
}

void SMList::deleteAll(int element)
{
	for (SMListNode* currentNode = this->head, *previousNode = nullptr; currentNode != nullptr; currentNode = currentNode->getNext())
	{
		if (currentNode->getElement() == element) {
			previousNode->setNext(currentNode->getNext());

			delete currentNode;

			currentNode = previousNode->getNext();

			size--;
		}
		previousNode = currentNode;
	}
}

int SMList::firstIndexOf(int element)
{
	int i = 0;
	SMListNode* currentNode = this->head; 
	while(currentNode != nullptr) 
	{
		if (element == currentNode->getElement()) {
			return i;
		}

		i++;
		currentNode = currentNode->getNext();
	}
	return -1;

}
