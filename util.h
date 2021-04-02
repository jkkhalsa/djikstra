#ifndef UTIL_H
#define UTIL_H

#include <string>
using namespace std;

class AdjacencyList;
class AdjacencyGraph;
class AdjacencyNode;

//make SURE this passes a char* - should do so with the command line arguments
AdjacencyList** createGraph(char* fileName);

#endif