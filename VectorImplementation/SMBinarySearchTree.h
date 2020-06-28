#pragma once
#include "SMTreeNode.h"
#include <queue> 
using namespace std;

class SMBinarySearchTree
{
private:
	SMTreeNode* root;
	int size;

	SMTreeNode* insert(SMTreeNode* root, int value);
	void inorder(SMTreeNode* root);
	void postorder(SMTreeNode* root);
	void preorder(SMTreeNode* root);
	SMTreeNode* findValue(SMTreeNode* root, int value);
	SMTreeNode* findMin(SMTreeNode* root);
	SMTreeNode* deleteValue(SMTreeNode* root, int value);
	int findHeight(SMTreeNode* root);

public:
	SMBinarySearchTree(int value);
	void insert(int value);
	int getNodeCount();
	void printOrdered();
	void printPostOrder();
	void printPreOrder();
	void printLevelOrder();
	bool isInTree(int value);
	int getHeight();
	int getMin();
	int getMax();
	void deleteValue(int value);
	int getSuccessor(int value);
};

