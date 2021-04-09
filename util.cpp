#include "adjacency.h"
#include "util.h"
#include "heap.h"

#include<iostream>
#include<fstream>

using std::cout;

AdjacencyGraph* createGraph(string fileName, bool d){
    int numVertices;
    int numEdges;
    int loop;
    bool isDirected = d;
    int vertexU;
    int vertexV;
    int weight;

    //open file
    ifstream infile;
    infile.open(fileName);
    if(infile.is_open()){

        //create the graph
        infile >> numVertices;
        AdjacencyGraph* graph = new AdjacencyGraph(numVertices);
        infile >> numEdges;
        cout << "\n numEdges is " << numEdges;
        infile >> loop;
        //TODO: DEBUG: make sure that actually worked lmao

        //read the contents into the graph
        for(int i = 1; i <= numEdges; i++){
            //cout << "\ntime for loop " << i;
            infile >> vertexU;
            infile >> vertexV;
            infile >> weight;

            //DEBUG PRINT STATEMENTS
            //cout << "\nvertexU is " << vertexU << "\nvertexV is " << vertexV << "\nweight is " << weight;

            //graph starts from 0, but nodes start from one, so let's just ignore the zero index lmao
            //insert vertex V into U's adjacency list
            if(graph->getList(vertexU) != NULL){
                graph->getList(vertexU)->insertEdge(new AdjacencyNode(vertexV, weight));
                //cout << "\nedge inserted: " << vertexU << " -> " << vertexV;
            }
            else{
                graph->setList(vertexU, new AdjacencyList(new AdjacencyNode(vertexV, weight)));
            }
            

            //if undirected, insert vertex U into V's adjacency list
            if(!isDirected){
                if(graph->getList(vertexV) != NULL){
                    graph->getList(vertexV)->insertEdge(new AdjacencyNode(vertexU, weight));
                    //cout << "\nedge "<< vertexU <<  " inserted successfully on " << vertexV;
                }
                else{
                    graph->setList(vertexV, new AdjacencyList(new AdjacencyNode(vertexU, weight)));
                }
            }
            infile >> loop; //get that out of the way
        }
        infile.close();
        return graph;
    }
    else{
        cout << "error, error, file fucked up\n";
        return nullptr;
    }
}

Vertex** Dijkstra(AdjacencyGraph* graph, int start, int target, bool writeFlag){
    int graphLength = graph->getGraphLength();
    Vertex** nodeList = createNodeList(graph);
    Heap* heap = new Heap(graphLength, writeFlag);
    Vertex* u;
    Vertex* end = nodeList[target];

    AdjacencyList* workingList;
    AdjacencyNode* workingEdge;
    Vertex* currentVertex;
    bool isEnd;

    //insert the first node into the heap
    nodeList[start]->setColor(2);
    heap->insert(nodeList[start]);
    //loop - while there remains things in the heap, run dijkstra
    while(!(heap->isEmpty())){
        //extract the current vertex and set it to black
        u = heap->extractMin()->getVertex();
        u->setColor(3);
        //if the extracted vertex is the same as the target, return the list
        if(u == end){
            //actually just pop down to the end of the loop so we can clean up our shit lol
            break;
        }
        //for each of u's adjacent vertices, make them grey, update their distances, and queue them up
        workingList = graph->getList(u->getNode());
        workingEdge = workingList->getHead();
        currentVertex = nodeList[workingEdge->getVertex()];
        isEnd = false;
        while(!(isEnd)){
            //if this hasn't been discovered, color in the edge
            if(currentVertex->getColor() == 1){
                currentVertex->setDistance(u->getDistance() + workingEdge->getWeight());
                currentVertex->setPi(u);
                currentVertex->setColor(2);
                heap->insert(currentVertex);
            }
            //if it has been discovered and this is a shorter path, update the edge
            else if(currentVertex->getDistance() > (u->getDistance() + workingEdge->getWeight())){
                currentVertex->setDistance(u->getDistance() + workingEdge->getWeight());
                currentVertex->setPi(u);
                heap->decreaseKey(currentVertex->getPosition(), currentVertex->getDistance());
            }

            //set up the next iteration
            isEnd = workingEdge->isTail();
            if(!isEnd){
                workingEdge = workingEdge->returnNext();
            }
        }

    }
    /*delete heap;
    delete u;
    delete end;
    delete workingList;
    delete workingEdge;
    delete currentVertex;*/
    return nodeList;
    
}



//index in the node list tells you what node it is
Vertex** createNodeList(AdjacencyGraph* graph){
    int graphLength = graph->getGraphLength();
    Vertex** nodeList = new Vertex*[graphLength];
    for(int i = 1; i < graphLength; i++){
        nodeList[i] = new Vertex(i);
    }
    return nodeList;
}