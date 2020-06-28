#include "SMTreeNode.h"

SMTreeNode::SMTreeNode(int value)
{
	this->value = value;
	left = nullptr;
	right = nullptr;
}

void SMTreeNode::setRight(SMTreeNode* right)
{
	this->right = right;
}

void SMTreeNode::setLeft(SMTreeNode* left)
{
	this->left = left;
}

SMTreeNode* SMTreeNode::getLeft()
{
	return left;
}

SMTreeNode* SMTreeNode::getRight()
{
	return right;
}

int SMTreeNode::getValue()
{
	return value;
}

void SMTreeNode::setValue(int value)
{
	this->value = value;
}
