#pragma once
class SMTreeNode
{
private:
	SMTreeNode* right;
	SMTreeNode* left;
	int value;
public:
	SMTreeNode(int value);
	void setRight(SMTreeNode* right);
	void setLeft(SMTreeNode* left);
	SMTreeNode* getLeft();
	SMTreeNode* getRight();
	int getValue();
	void setValue(int value);
};

