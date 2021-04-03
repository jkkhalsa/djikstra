//define functions used in the heap and element classes
//both heap and element classes defined in heap.cpp

#ifndef HEAP_H
#define HEAP_H

#include <string>
using namespace std;

class Element
{
    private:
    int key;

public:
    Element();
    Element(int k);
    int getKey();
    void setKey(int k);
};

class Heap
{
    private:
    int capacity;   //max size of the heap
    int size;       //current size of the heap
    Element * H;    //the actual heap, I think?
    int callCount;  //ok this is super goddamn illegal but we're gonna count the number of minHeapify calls in a global variable

    public:
    Heap();
    Heap(int n);
    int getCapacity();
    int getSize();
    int getElement(int index);
    std::string toString(bool choice);
    void setElement(int index, int key);
    bool setSize(int s);
    //new functions for project 2
    int getRightIndex(int index);
    int getLeftIndex(int index);
    int getParentIndex(int index);
    int buildHeap(bool flag);
    void minHeapify(int index, bool flag);
    bool insert(int element);
    void extractMin(bool printFlag);
    string decreaseKey(int index, int value);
     
    
};


#endif