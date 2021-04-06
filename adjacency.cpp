#include "adjacency.h"

using namespace std;

#include <iostream>


//adjacency node methods

AdjacencyNode :: AdjacencyNode(){
    vertex = -1;
    weight = 1;
    next = nullptr;
}

AdjacencyNode :: AdjacencyNode(int v){
    vertex = v;
    weight = 1;
    next = nullptr;
}

AdjacencyNode :: AdjacencyNode(int v, float w){
    vertex = v;
    weight = w;
    next = nullptr;
}

void AdjacencyNode :: setNext(AdjacencyNode* n){
    next = n;
    cout << "\nnext on " << vertex << " is set to " << n->getVertex();
}

AdjacencyNode* AdjacencyNode :: returnNext(){
    return next;
}

bool AdjacencyNode :: isTail(){
    if(next == nullptr){
        return true;
    }
    return false;
}

void AdjacencyNode :: setVertex(int v){
    vertex = v;
}

int AdjacencyNode :: getVertex(){
    return vertex;
}


//adjacency list methods

AdjacencyList :: AdjacencyList(AdjacencyNode* h){
    head = h;
    cout << "\ncreated adjacency list";
}

void AdjacencyList :: insertEdge(AdjacencyNode* h){
    cout << "\ninsert edge called";
    h->setNext(head);
    head = h;
}

AdjacencyNode* AdjacencyList :: getHead(){
    return head;
}


//adjacency graph methods

AdjacencyGraph :: AdjacencyGraph(int numVertices){
    graph = new AdjacencyList*[numVertices+1];
    graphLength = numVertices+1;
}

void AdjacencyGraph :: setList(int index, AdjacencyList* list){
    graph[index] = list;
}

AdjacencyList* AdjacencyGraph :: getList(int index){
    return graph[index];
}

string AdjacencyGraph :: printGraph(){
    cout << "printGraph called\n";
    cout << "Current List:";
    AdjacencyNode* current;
    //mostly for debug purposes to see what's in the graph
    for(int i = 1; i < graphLength; i++){
        cout << "\n" << i;
        current = graph[i]->getHead();
        cout << " -> " << current->getVertex();
            while(!(current->isTail())){
                current = current->returnNext();
                cout << " > " << current->getVertex();
            }
    }
    return "\n";
}