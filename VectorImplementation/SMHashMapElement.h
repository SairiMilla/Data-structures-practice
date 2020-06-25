#pragma once
class SMHashMapElement
{
private:
	int key;
	int value;
	bool present;

public:
	SMHashMapElement(int key, int value);
	SMHashMapElement();
	int getKey();
	int getValue();
	void setValue(int value);
	bool isPresent();
	void setPresent(bool present);
};

