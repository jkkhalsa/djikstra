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

void AdjacencyList :: insertEdge(AdjacencyNode* h){
    h->setNext(head);
    head = h;
}