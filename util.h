#ifndef UTIL_H
#define UTIL_H

#include <string>
#include "heap.h"
#include "adjacency.h"
using namespace std;

class AdjacencyList;
class AdjacencyGraph;
class AdjacencyNode;

//creates a pointer to an adjacency graph created by reading the given file
AdjacencyGraph* createGraph(string fileName, bool d);

Vertex** Dijkstra(AdjacencyGraph* graph, int start, int target, bool writeFlag);

Vertex** createNodeList(AdjacencyGraph* graph);

void findShortestPath(Vertex** nodeList, int source, int destination);

#endif