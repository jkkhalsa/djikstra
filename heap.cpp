#include "heap.h"
#include <iostream>

using namespace std;

Vertex :: Vertex(){
    color = 1;
    pi = NULL;
    d = -1;
}

//implementations of the Element class
Element :: Element(){
    key = 0;
}

Element :: Element(int k){
    key = k;
    return;
}

int Element :: getKey(){
    return key;
}

void Element :: setKey(int k){
    key = k;
    return;
}



//DYNAMIC ALLOCATION used with "new" keyword
Heap :: Heap(){
    capacity = 0;
    size = 0;
    H = new Element[capacity + 1];
}

//DYNAMIC ALLOCATION used with "new" keyword
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

int Heap :: getElement(int index){
    return H[index].getKey();
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


//functions now required for project 2

//gets index of left child
int Heap :: getLeftIndex(int index){
    return index*2 + 1;
}

//gets index of right child
int Heap :: getRightIndex(int index){
    return index*2 + 2;
}

int Heap :: getParentIndex(int index){
    return (index-1)/2;
}


void Heap :: minHeapify(int parentIndex, bool flag){
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
        if(flag){
            callCount++;
        }
        minHeapify(smallest, flag);
    }
    return;
}

int Heap :: buildHeap(bool flag){
    callCount = 0;
    for(int i = (size/2)-1; i >= 0; i--){
        minHeapify(i, flag);
        callCount++;
    }
    return callCount;
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
}

void Heap :: extractMin(bool printFlag){
    //swap keys for 0 and end of heap
    int temp = H[0].getKey();
    cout << "Deleted key: " << temp << "\n";
    H[0].setKey(H[size-1].getKey());
    //remake heap
    size--;
    callCount = 1;
    minHeapify(0, printFlag);
    if(printFlag){
        cout << "Number of Heapify calls: " << callCount << "\n";
    }
    return;
}

string Heap :: decreaseKey(int index, int value){
    int swap;
    index--; //illegal move to make the index match the array
    if(index < 0 || index >= size || value >= H[index].getKey()){
        return "Error: invalid call to DecreaseKey\n";
    }
    else{
        H[index].setKey(value);
        //heapify this shit
        while(index > 0 && H[getParentIndex(index)].getKey() > H[index].getKey()){
            swap = H[getParentIndex(index)].getKey();
            H[getParentIndex(index)].setKey(H[index].getKey());
            H[index].setKey(swap);
            index = getParentIndex(index);
        }
    }
    return "";
}