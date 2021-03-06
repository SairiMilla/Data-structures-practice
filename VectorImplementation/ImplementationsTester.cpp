// VectorImplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SMVector.h"
#include "SMList.h"
#include "SMStack.h"
#include "SMDynamicQueue.h"
#include "SMFixedQueue.h"
#include "SMStaticHashMap.h"
#include <vector>
#include <algorithm>  
#include "SMBinarySearchTree.h"
#include "SMMaxHeap.h"

using namespace std;

string parenthesisBalance(string s) {
    SMStack stack;
    vector<int> v;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '(') {
            stack.push(i);
        }
        else if (s.at(i) == ')' && stack.isEmpty()) {
            v.push_back(i);
        }
        else if (s.at(i) == ')' && !stack.isEmpty()) {
            stack.pop();
        }
    }

    while(!stack.isEmpty())
    {
        v.push_back(stack.pop());
    }

    sort(v.begin(), v.end());

    int reductions = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        
        s.replace(*it - reductions, 1, "");
        reductions++;
    }

    return s;
}

void printArray(int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void testVector() {
    SMVector vector;

    cout << "isEmpty: " << vector.isEmpty() << endl;

    vector.printContents();

    vector.push(3);
    vector.push(4);
    vector.push(6);
    vector.push(7);
    vector.push(8);
    vector.push(2);

    vector.printContents();

    vector.push(1);
    vector.push(5);
    vector.push(9);
    vector.push(10);
    vector.push(11);
    vector.push(12);
    vector.push(13);
    vector.push(14);
    vector.push(15);
    vector.push(16);
    vector.push(17);
    vector.push(18);
    vector.printContents();

    vector.insert(10, 300);

    vector.printContents();

    cout << "getSize: " << vector.getSize() << endl;

    cout << "getCapacity: " << vector.getCapacity() << endl;

    cout << "isEmpty: " << vector.isEmpty() << endl;

    vector.prepend(300);
    vector.printContents();

    vector.pop();
    vector.printContents();

    cout << "Element at index 6: " << vector.get(6) << endl;

    vector.set(6, 300);

    cout << "Element at index 6: " << vector.get(6) << endl;

    vector.printContents();
    vector.remove(7);

    vector.printContents();

    cout << "First appearance of 15: " << vector.firstIndexOf(15) << endl;

    vector.printContents();
}

void testList() {
    SMList list;

    cout << "isEmpty: " << list.isEmpty() << endl;


    list.printContents();

    list.push(3);
    list.push(4);
    list.push(6);
    list.push(7);
    list.push(8);
    list.push(2);

    list.printContents();

    list.push(1);
    list.push(5);
    list.push(9);
    list.push(10);
    list.push(11);
    list.push(12);
    list.push(13);
    list.push(14);
    list.push(15);
    list.push(16);
    list.push(17);
    list.push(18);
    list.printContents();

    list.insert(10, 300);

    list.printContents();

    cout << "getSize: " << list.getSize() << endl;


    cout << "isEmpty: " << list.isEmpty() << endl;

    list.prepend(300);
    list.printContents();

    cout << "Popped front: " << list.popFront();
    list.printContents();

    cout << "Popped back: " << list.popBack();
    list.printContents();

    cout << "Element at index 6: " << list.get(6) << endl;

    list.set(6, 300);

    cout << "Element at index 6: " << list.get(6) << endl;

    list.printContents();
    list.remove(7);

    list.printContents();

    cout << "First appearance of 15: " << list.firstIndexOf(15) << endl;

    list.printContents();

    list.deleteAll(300);
    list.printContents();
}

void testStack() {
    SMStack stack;

    cout << "isEmpty: " << stack.isEmpty() << endl;

    stack.push(3);
    stack.push(4);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(2);

    stack.printContents();

    cout << "Pop: " << stack.pop();

    stack.printContents();

    cout << "Top: " << stack.top();

    stack.printContents();
}

void testDynamicQueue() {
    SMDynamicQueue queue;

    cout << "isEmpty: " << queue.isEmpty() << endl;

    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(2);

    queue.printContents();

    cout << "Pop: " << queue.dequeue();

    queue.printContents();

    cout << "Top: " << queue.front();

    queue.printContents();
}

void testFixedQueue() {

    SMFixedQueue queue(5);

    cout << "isEmpty: " << queue.isEmpty() << endl;

    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(2);

    queue.printContents();

    cout << "Pop: " << queue.dequeue() <<  endl;

    queue.printContents();

    cout << "Top: " << queue.front() << endl;

    queue.printContents();
    
    queue.enqueue(2);

    cout << "Top: " << queue.front() << endl;

    queue.printContents();
}


void testHashMap() {

    SMStaticHashMap map(10);

    map.printContents();

    map.add(4, 8);
    map.add(26, 1);
    map.add(420, 63);
    map.add(45, 18);
    map.add(346, 83);
    map.add(901, 45);


    map.printContents();

    cout << "Exists 45: " << map.exists(45) << endl;

    cout << "Exists 9: " << map.exists(9) << endl;

    map.remove(45);

    cout << "Exists 45: " << map.exists(45) << endl;

    cout << "Value for 346: " << map.get(346) <<  endl;
}

void testBinarySearchTree() {

    SMBinarySearchTree bst(10);
 
    bst.printOrdered();

    bst.insert(8);
    bst.insert(1);
    bst.insert(63);
    bst.insert(18);
    bst.insert(83);
    bst.insert(45);

    cout << "Total number of nodes: " << bst.getNodeCount() << endl;

    bst.printOrdered();

    bst.printPostOrder();
    bst.printPreOrder();
    bst.printLevelOrder();

    cout << "Exists 45: " << bst.isInTree(45) << endl;

    cout << "Exists 9: " << bst.isInTree(9) << endl;

    bst.deleteValue(45); //no child
    bst.deleteValue(8); // one child left
    bst.deleteValue(63); // two children

    bst.insert(2);

    bst.deleteValue(1);//one child right

    cout << "Exists 45: " << bst.isInTree(45) << endl;

    bst.printOrdered();

    cout << "Height of tree: " << bst.getHeight() << endl;

    cout << "Minimum value: " << bst.getMin() << endl; 

    cout << "Maximum value: " << bst.getMax() << endl;

    bst.insert(5);
    bst.insert(8);
    bst.insert(15);
    bst.insert(13);

    cout << "Successor of 8: " << bst.getSuccessor(8) << endl;
    cout << "Successor of 10: " << bst.getSuccessor(10) << endl;

    bst.printOrdered();

}

void testMaxHeap() {
    SMMaxHeap heap(10);

    cout << "Is it empty? " << heap.isEmpty() << endl;
    cout << "Size: " << heap.getSize() << endl;

    heap.insert(6);
    heap.insert(8);
    heap.insert(1);
    heap.insert(23);
    heap.insert(10);
    heap.insert(4);
    heap.insert(45);

    cout << "Is it empty? " << heap.isEmpty() << endl;
    cout << "Size: " << heap.getSize() << endl;

    heap.printContents();

    cout << "Max Value" << heap.getMax() << endl;

    heap.printContents();

    cout << "Max extract: " << heap.extractMax() << endl;

    heap.printContents();

    heap.remove(4);

    heap.printContents();

    int arr[] = {8, 20, 18, 3, 2, 21, 15, 6};

   printArray(arr, 8);

   heap.heapify(arr, 8);

   printArray(arr, 8);

   int arr2[] = {7, 26, 12, 19, 3, 8, 10, 20, 11};

   heap.heapSort(arr2, 9);

   printArray(arr2, 9);

    int arr3[] = { 10, 28, 34, 17, 23, 9 };

    SMMaxHeap heap2(arr3, 6);

    heap2.printContents();

    heap2.changePriority(2, 3);

    heap2.printContents();

    cout << "Max extract: " << heap2.extractMax() << endl;

    heap2.printContents();

    cout << "Max extract: " << heap2.extractMax() << endl;

    heap2.printContents();

    cout << "Max extract: " << heap2.extractMax() << endl;

    heap2.printContents();

    cout << "Max extract: " << heap2.extractMax() << endl;

    heap2.printContents();
}

int main()
{
    testMaxHeap();
}



