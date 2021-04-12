#include "heap.h"
#include <iostream>

using namespace std;


//implementing the VERTEX class
Vertex :: Vertex(){
    color = 1;
    pi = nullptr;
    distance = 0;
    node = -1;
}

Vertex :: Vertex(int n){
    distance = 0;
    color = 1;
    pi = nullptr;
    node = n;
}

//1 is white, 2 is gray, 3 is black
int Vertex :: getColor(){
    return color;
}
//1 is white, 2 is gray, 3 is black
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

int Vertex :: getNode(){
    return node;
}
void Vertex :: setNode(int n){
    node = n;
}

void Vertex :: printVertex(){
    cout << "called printVertex\n";
    cout << "Vertex " << node << ":\tColor -> ";
    if(color == 1){
        cout << "white";
    }
    else if(color == 2){
        cout << "gray";
    }
    else if(color == 3){
        cout << "black";
    }
    cout << "\tDistance -> " << distance << "\tPredecessor -> " << pi->getNode();
    return;
}

Vertex :: ~Vertex(){
    //delete pi;
}



//implementations of the Element class
Element :: Element(){
    key = 0;
}

Element :: Element(int k){
    key = k;
    return;
}

Element :: Element(float k, Vertex* v){
    key = k;
    vertex = v;
}

float Element :: getKey(){
    return key;
}

void Element :: setKey(float k){
    key = k;
    return;
}

Vertex* Element :: getVertex(){
    return vertex;
}

void Element :: setVertex(Vertex* v){
    vertex = v;
}

Element :: ~Element(){
    //delete vertex;
}



//implementing the HEAP class
Heap :: Heap(){
    capacity = 0;
    size = 0;
    H = new Element[capacity + 1];
}

Heap :: Heap(int n, bool w){
    capacity = n;
    size = 0;
    H = new Element[capacity + 1];
    writeFlag = w;
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
    //cout << "in min heapify\n";
    int leftIndex = getLeftIndex(parentIndex);
    int rightIndex = getRightIndex(parentIndex);
    int smallest = parentIndex;
    //cout << "all indexes in min heapify gotten\n";
    Element temp;
    //cout << "size is " << size << ", left index is " << leftIndex << ", right index is " << rightIndex << ", and parentIndex is "<< parentIndex << "\n";
    if(leftIndex <= size && H[leftIndex].getKey() < H[parentIndex].getKey()){
        //cout << "left child is the smallest";
        smallest = leftIndex;
    }
    if(rightIndex <= size && H[rightIndex].getKey() < H[smallest].getKey()){
        //cout << "right child is the smallest";
        smallest = rightIndex;
    }
    if(smallest != parentIndex){
        //cout << "swapping " << H[smallest].getVertex()->getNode() << " with its parent " << H[parentIndex].getVertex()->getNode() << "\n";
        //swap the two
        temp = H[smallest];
        H[smallest] = H[parentIndex];
        H[parentIndex] = temp;

        //NEW - update position in vertex
        H[smallest].getVertex()->setPosition(smallest);
        H[parentIndex].getVertex()->setPosition(parentIndex);

        minHeapify(smallest);
    }
    return;
}

Vertex* Heap :: extractMin(){
    //cout << "start of extract min, size of heap is" << size << "\n";
    //swap keys for 0 and end of heap
    Element temp = H[0];
    H[0].setKey(H[size-1].getKey());
    H[0].setVertex(H[size-1].getVertex());
    //cout << "set the key and vertex to their new values\n";
    //remake heap
    size--;
    minHeapify(0);
    //cout << "Delete vertex " << temp.getVertex()->getNode() << ", key=" << temp.getKey() << "\n";
    if(writeFlag){
        printf("Delete vertex %d, key=%12.4f\n", temp.getVertex()->getNode(), temp.getKey());
    }
    return temp.getVertex();
}


int Heap :: decreaseKey(int index, float value){
    if(index < 0 || index > size || value >= H[index].getKey()){
        cout << "Error in DecreaseKey\n";
        //cout << "DEBUG DecreaseKey - index is " << index << ", size is " << size << ", value is " << value << ", and the key is " << H[index].getKey() << "\n";
        return 1;
    }
    else{
        //cout << "Decrease key of vertex " << H[index].getVertex()->getNode() << ", from\t" << H[index].getKey() << " to\t" << value << "\n";
        if(writeFlag){
            printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", H[index].getVertex()->getNode(), H[index].getKey(), value);
        }
        H[index].setKey(value);
        //heapify this shit
        movingUp(index);
    }
    return 0;
}

void Heap :: movingUp(int position){
    //cout << "moving up position " << position << " with vertex of " << H[position].getVertex()->getNode() << "\n";
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


//returns true if it's overflowing, false if it won't
bool Heap :: insert(Vertex* v, float k){
    if(size+1 > capacity){
        cout << "error: heap overflow\n";
        return true;
    }
    else{
        //add the new element to the heap
        H[size].setKey(k);
        H[size].setVertex(v);
        //cout << "Insert vertex " << H[size].getVertex()->getNode() << ", key=\t" << H[size].getKey() << "\n";
        if(writeFlag){
            printf("Insert vertex %d, key=%12.4f\n", H[size].getVertex()->getNode(), H[size].getKey());
        }
        H[size].getVertex()->setPosition(size);
        size++;
        //put it in its proper place
        movingUp(H[size-1].getVertex()->getPosition());
    }
    return false;
}

bool Heap :: isEmpty(){
    if(size == 0){
        return true;
    }
    return false;
}

Heap :: ~Heap(){
    //delete H;
}