//define functions used in the heap and element classes
//both heap and element classes defined in heap.cpp

#ifndef HEAP_H
#define HEAP_H

#include <string>
using namespace std;

class Vertex{

    private:
    int color; //1 for white, 2 for grey, 3 for black
    Vertex* pi;     //predecessor
    float distance;    //distance from source
    int position;    //index in the heap array

    public:
    Vertex();

    int getColor();
    void setColor(int c);

    Vertex* getPi();
    void setPi(Vertex* predecessor);

    float getDistance();
    void setDistance(float d);

    int getPosition();
    void setPosition(int pos);

};

class Element
{
    private:
    Vertex* vertex;
    float key;

    public:
    Element();
    Element(int k);
    Element(int k, Vertex* v);

    int getKey();
    void setKey(int k);
};

class Heap
{
    private:
    int capacity;   //max size of the heap
    int size;       //current size of the heap
    Element * H;    //the actual heap, I think?

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
    void buildHeap();
    void minHeapify(int index);
    bool insert(int element);
    void extractMin();
    int decreaseKey(int index, int value);
     
    
};


#endif