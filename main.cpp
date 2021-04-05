#include "adjacency.h"
#include "util.h"

#include <iostream>

using namespace std;


int main(int argc, char* argv[]){
    bool isDirected = false;

    if(argc == 3){
        if(argv[2][0] != 'u'){
            isDirected = true;
            cout << "isDirected is true\n";
        }
        string fileName(argv[1]);
        AdjacencyGraph* graph = createGraph(fileName, isDirected);
        cout << "got out of graph building\n";
        cout << graph->printGraph();
    }
    
}