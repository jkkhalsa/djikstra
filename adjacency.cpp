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

float AdjacencyNode :: getWeight(){
    return weight;
}

AdjacencyNode :: ~AdjacencyNode(){
    delete next;
}


//adjacency list methods

AdjacencyList :: AdjacencyList(AdjacencyNode* h){
    head = h;
}

void AdjacencyList :: insertEdge(AdjacencyNode* h){
    h->setNext(head);
    head = h;
}

AdjacencyNode* AdjacencyList :: getHead(){
    return head;
}

AdjacencyList :: ~AdjacencyList(){
    delete head;
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

int AdjacencyGraph :: getGraphLength(){
    return graphLength;
}

string AdjacencyGraph :: printGraph(){
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
    delete current;
    return "\n";
}

AdjacencyGraph :: ~AdjacencyGraph(){
    for(int i = 0; i < graphLength; i++){
        delete graph[i];
    }
    delete graph;
}