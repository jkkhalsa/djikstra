#include "adjacency.h"
#include "util.h"

#include<iostream>
#include<fstream>

using std::cout;

AdjacencyGraph* createGraph(string fileName, bool d){
    string processing;
    bool isDirected = d;
    int numEdges;
    int vertexU;
    int vertexV;
    int weight;
    AdjacencyList* adjList;


    //open file
    ifstream infile;
    infile.open(fileName);
    if(infile.is_open()){

        //create the graph
        getline(infile, processing);
        AdjacencyGraph* graph = new AdjacencyGraph(processing[0] - '0');
        numEdges = processing[2] - '0';
        //TODO: DEBUG: make sure that actually worked lmao

        //read the contents into the graph
        for(int i = 1; i <= numEdges; i++){
            getline(infile, processing);
            vertexU = processing[2] - '0';
            vertexV = processing[4] - '0';
            weight = processing[6] - '0';

            //DEBUG PRINT STATEMENTS
            cout << "\nvertexU is " << vertexU << "\nvertexV is " << vertexV << "\nweight is " << weight;

            //graph starts from 0, but nodes start from one, so -1 to every vertex U we put in
            //insert vertex V into U's adjacency list
            AdjacencyList* adjList = graph->getList(vertexU - 1);
            adjList->insertEdge(new AdjacencyNode(vertexV, weight));

            //if undirected, insert vertex U into V's adjacency list
            if(isDirected){
                AdjacencyList* adjList = graph->getList(vertexV - 1);
                adjList->insertEdge(new AdjacencyNode(vertexU, weight));
            }
        }
        infile.close();
    }
    else{
        //error: file can't be opened
    }

    
    
}