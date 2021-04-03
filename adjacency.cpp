#include "adjacency.h"


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
}

AdjacencyNode* AdjacencyNode :: returnNext(){
    return next;
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
}

void AdjacencyList :: insertEdge(AdjacencyNode* h){
    h->setNext(head);
    head = h;
}


//adjacency graph methods

AdjacencyGraph :: AdjacencyGraph(int numVertices){
    graph = new AdjacencyList*[numVertices];
}

void AdjacencyGraph :: setList(int index, AdjacencyList* list){
    graph[index] = list;
}

AdjacencyList* AdjacencyGraph :: getList(int index){
    return graph[index];
}