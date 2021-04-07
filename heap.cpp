#include "heap.h"
#include <iostream>

using namespace std;


//implementing the VERTEX class
Vertex :: Vertex(){
    color = 1;
    pi = nullptr;
    distance = -1;
}

int Vertex :: getColor(){
    return color;
}
void Vertex :: setColor(int c){
    color = c;
}

Vertex* Vertex :: getPi(){
    return pi;
}
void Vertex :: setPi(Vertex* predecessor){
    pi = predecessor;
}

float Vertex :: getDistance(){
    return distance;
}
void Vertex :: setDistance(float d){
    distance = d;
}

int Vertex :: getPosition(){
    return position;
}
void Vertex :: setPosition(int pos){
    position = pos;
}



//implementations of the Element class
Element :: Element(){
    key = 0;
}

Element :: Element(int k){
    key = k;
    return;
}

Element :: Element(int k, Vertex* v){
    key = k;
    vertex = v;
}

int Element :: getKey(){
    return key;
}

void Element :: setKey(int k){
    key = k;
    return;
}

Vertex* Element :: getVertex(){
    return vertex;
}




//implementing the HEAP class
Heap :: Heap(){
    capacity = 0;
    size = 0;
    H = new Element[capacity + 1];
}

Heap :: Heap(int n){
    capacity = n;
    size = 0;
    H = new Element[capacity + 1];
}

int Heap :: getCapacity(){
    return capacity;
}

int Heap :: getSize(){
    return size;
}

//returns true if it's overflowing, false if it won't
bool Heap :: setSize(int s){
    if(s > capacity){
        return true;
    }
    size = s;
    return false;
    
}

Element* Heap :: getElement(int index){
    return &H[index];
}

//send true in choice for writing to file, false for writing to console
string Heap :: toString(bool choice){
    string result;
    if(choice){
        result = to_string(size) + "\n";
        for(int i = 0; i < size; i++){
            result += to_string(H[i].getKey()) + "\n";
        }
    }
    else{
        result = "capacity=" + to_string(capacity) + ", size=" + to_string(size) + "\n";
        if(size == 0){
            return result;
        }
        for(int i = 0; i < size; i++){
            result += to_string(H[i].getKey());
            if(i != size-1){
                result += ", ";
            }
        }
        result += "\n";

    }
    return result;
}

void Heap :: setElement(int index, int key){
    H[index].setKey(key);
    return;
}

int Heap :: getParentIndex(int index){
    return (index-1)/2;
}


//gets index of right child
int Heap :: getRightIndex(int index){
    return index*2 + 2;
}

//gets index of left child
int Heap :: getLeftIndex(int index){
    return index*2 + 1;
}


void Heap :: minHeapify(int parentIndex){
    int leftIndex = getLeftIndex(parentIndex);
    int rightIndex = getRightIndex(parentIndex);
    int smallest = parentIndex;
    int temp;
    if(leftIndex <= size && H[leftIndex].getKey() < H[parentIndex].getKey()){
        smallest = leftIndex;
    }
    if(leftIndex <= size && H[rightIndex].getKey() < H[smallest].getKey()){
        smallest = rightIndex;
    }
    if(smallest != parentIndex){
        //swap the two
        temp = H[smallest].getKey();
        H[smallest].setKey(H[parentIndex].getKey());
        H[parentIndex].setKey(temp);

        //NEW - update position in vertex
        H[smallest].getVertex()->setPosition(smallest);
        H[parentIndex].getVertex()->setPosition(parentIndex);

        minHeapify(smallest);
    }
    return;
}

Element* Heap :: extractMin(){
    //swap keys for 0 and end of heap
    Element* temp = &H[0];
    H[0].setKey(H[size-1].getKey());
    //remake heap
    size--;
    minHeapify(0);
    return temp;
}


int Heap :: decreaseKey(int index, int value){
    index--; //illegal move to make the index match the array
    if(index < 0 || index >= size || value >= H[index].getKey()){
        cout << "Error in DecreaseKey\n";
        return 1;
    }
    else{
        H[index].setKey(value);
        //heapify this shit
        movingUp(index);
    }
    return 0;
}

void Heap :: movingUp(int position){
    int parent;
    Element temp;
    parent = getParentIndex(position);
    if(position > 0 && H[position].getKey() < H[parent].getKey()){
        temp = H[position];
        H[position] = H[parent];
        H[parent] = temp;
        //swapped now - so update the position in vertex
        H[position].getVertex()->setPosition(position);
        H[parent].getVertex()->setPosition(parent);
        //do this again
        movingUp(parent);
    }

}

/*void Heap :: buildHeap(){
    for(int i = (size/2)-1; i >= 0; i--){
        minHeapify(i);
    }
    return;
}

//returns true if it's overflowing, false if it won't
bool Heap :: insert(int element){
    if(size+1 > capacity){
        return true;
    }
    else{
        int swap;
        H[size].setKey(element);
        int index = size;
        size++;
        //heapify this shit
        while(index > 0 && H[getParentIndex(index)].getKey() > H[index].getKey()){
            swap = H[getParentIndex(index)].getKey();
            H[getParentIndex(index)].setKey(H[index].getKey());
            H[index].setKey(swap);
            index = getParentIndex(index);
        }
    }
    return false;
}*/