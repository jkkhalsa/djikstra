//define functions used in the heap and element classes
//both heap and element classes defined in heap.cpp

#ifndef HEAP_H
#define HEAP_H
#include "adjacency.h"

#include <string>
using namespace std;

class Vertex{

    private:
    int color; //1 for white, 2 for grey, 3 for black
    Vertex* pi;     //predecessor
    float distance;    //distance from source
    int position;    //index in the heap array
    int node;       //identifier for what node it is in the chart

    public:
    Vertex();
    //distance first, color second - 1 is white, 2 is grey, 3 is black
    Vertex(int n);

    int getColor();
    void setColor(int c);

    Vertex* getPi();
    void setPi(Vertex* predecessor);

    float getDistance();
    void setDistance(float d);

    int getPosition();
    void setPosition(int pos);

    int getNode();


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

    void setVertex(Vertex* v);
    Vertex* getVertex();
};

class Heap
{
    private:
    int capacity;   //max size of the heap
    int size;       //current size of the heap
    Element * H;    //the actual heap, I think?
    bool writeFlag;

    public:
    Heap();
    Heap(int n, bool writeFlag);
    int getCapacity();
    int getSize();
    Element* getElement(int index);
    std::string toString(bool choice);
    void setElement(int index, int key);
    bool setSize(int s);
    int getParentIndex(int index);
    int getRightIndex(int index);
    int getLeftIndex(int index);
    void minHeapify(int index);
    bool insert(Vertex* v);
    Element* extractMin();
    int decreaseKey(int index, int value);
    void movingUp(int position);

    bool isEmpty();

    
};


#endif