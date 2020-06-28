#include "SMBinarySearchTree.h"
#include <iostream>

SMTreeNode* SMBinarySearchTree::insert(SMTreeNode* root, int value)
{
	if (root == nullptr) {
		root = new SMTreeNode(value);
	}
	else if (value < root->getValue()) {
		root->setLeft(insert(root->getLeft(), value));
	}
	else if (value > root->getValue()) {
		root->setRight(insert(root->getRight(), value));
	}

	return root;
}

void SMBinarySearchTree::inorder(SMTreeNode* root)
{

		if (root != nullptr) {
			inorder(root->getLeft());
			cout << root->getValue() << ", ";
			inorder(root->getRight());
		}
	
}

void SMBinarySearchTree::postorder(SMTreeNode* root)
{
	if (root != nullptr) {
		postorder(root->getLeft());
		postorder(root->getRight());
		cout << root->getValue() << ", ";
	}
}

void SMBinarySearchTree::preorder(SMTreeNode* root)
{
	if (root != nullptr) {
		cout << root->getValue() << ", ";
		preorder(root->getLeft());
		preorder(root->getRight());
	}
}

SMTreeNode* SMBinarySearchTree::findValue(SMTreeNode* root, int value)
{
	if (root) {
		if (root->getValue() == value) {
			return root;
		}
		else if (value < root->getValue()) {
			return findValue(root->getLeft(), value);
		}
		else {
			return findValue(root->getRight(), value);
		}
	}
	return nullptr;
}

SMTreeNode* SMBinarySearchTree::findMin(SMTreeNode* root)
{
	if (root) {
		while (root->getLeft())
		{
			root = root->getLeft();
		}
	}
	return root;
}

SMTreeNode* SMBinarySearchTree::deleteValue(SMTreeNode* root, int value)
{
	if (root) {
		if (value < root->getValue())
			root->setLeft(deleteValue(root->getLeft(), value));
		else if (value > root->getValue())
			root->setRight(deleteValue(root->getRight(), value));
		else {
			if (!root->getRight() && !root->getLeft()) {
				delete root;
				root = nullptr;
			}
			else if (!root->getLeft()) {
				SMTreeNode* temp = root;
				root = temp->getRight();
				delete temp;
			}
			else if (!root->getRight()) {
				SMTreeNode* temp = root;
				root = temp->getLeft();
				delete temp;
			}
			else {
				SMTreeNode* temp = findMin(root->getRight());
				root->setValue(temp->getValue());
				root->setRight(deleteValue(root->getRight(), temp->getValue()));
			}
		}
	}
	return root;
}

int SMBinarySearchTree::findHeight(SMTreeNode* root)
{
	if (!root) {
		return -1;
	}

	int leftHeigt = findHeight(root->getLeft());
	int rightHeight = findHeight(root->getRight());

	return 1 + max(leftHeigt, rightHeight);
}

SMBinarySearchTree::SMBinarySearchTree(int value)
{
	root = new SMTreeNode(value);
	size = 1;
}

void SMBinarySearchTree::insert(int value)
{
	insert(root, value);
	size++;
}

int SMBinarySearchTree::getNodeCount()
{
	return size;
}

void SMBinarySearchTree::printOrdered()
{
	inorder(root);
	cout << endl;
}

void SMBinarySearchTree::printPostOrder()
{
	postorder(root);
	cout << endl;
}

void SMBinarySearchTree::printPreOrder()
{
	preorder(root);
	cout << endl;
}

void SMBinarySearchTree::printLevelOrder()
{
	if (root) {
		queue<SMTreeNode*> nodesToVisit;
		nodesToVisit.push(root);

		while (!nodesToVisit.empty())
		{
			SMTreeNode* current = nodesToVisit.front();
			cout << current->getValue() << ", ";

			if (current->getLeft()) {
				nodesToVisit.push(current->getLeft());
			}

			if (current->getRight()) {
				nodesToVisit.push(current->getRight());
			}

			nodesToVisit.pop();
		}
		cout << endl;
	}
}

bool SMBinarySearchTree::isInTree(int value)
{
	return findValue(root, value) != nullptr;
}

int SMBinarySearchTree::getHeight()
{
	return findHeight(root);
}

int SMBinarySearchTree::getMin()
{
	if (root) {
		return findMin(root)->getValue();
	}
	return -1;
}

int SMBinarySearchTree::getMax()
{
	if (root) {
		SMTreeNode* current = root;

		while (current->getRight() != nullptr)
		{
			current = current->getRight();
		}
		return current->getValue();
	}
	return -1;
}

void SMBinarySearchTree::deleteValue(int value)
{
	deleteValue(root, value);
	size--;
}

int SMBinarySearchTree::getSuccessor(int value)
{
	SMTreeNode* valueNode = findValue(root, value);

	if (valueNode) {
		if (valueNode->getRight()) {
			return findMin(valueNode->getRight())->getValue();
		}
		else {
			SMTreeNode* succesorNode = nullptr;
			SMTreeNode* temp = root;
			while (temp != valueNode) {
				if (valueNode->getValue() < temp->getValue()) {
					succesorNode = temp;
					temp = temp->getLeft();
				}
				else {
					temp = temp->getRight();
				}
			}
			if (succesorNode)
				return succesorNode->getValue();
			else
				return -1;

		}
	}
	return -1;
}

