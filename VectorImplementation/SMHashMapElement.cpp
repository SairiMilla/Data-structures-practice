#include "SMHashMapElement.h"

SMHashMapElement::SMHashMapElement(int key, int value)
{
	this->key = key;
	this->value = value;
	this->present = true;
}

SMHashMapElement::SMHashMapElement()
{
	this->present = false;
	this->key = 0;
	this->value = 0;
}

int SMHashMapElement::getKey()
{
	return this->key;
}

int SMHashMapElement::getValue()
{
	return this->value;
}

void SMHashMapElement::setValue(int value)
{
	this->value = value;
}

bool SMHashMapElement::isPresent()
{
	return this->present;
}

void SMHashMapElement::setPresent(bool present)
{
	this->present = present;
}


