#ifndef UTIL_H
#define UTIL_H

#include <string>
using namespace std;

class AdjacencyList;
class AdjacencyGraph;
class AdjacencyNode;

//creates a pointer to an adjacency graph created by reading the given file
AdjacencyGraph* createGraph(string fileName, bool d);

void testFunction();

#endif