#include "adjacency.h"
#include "util.h"

using namespace std;


int main(int argc, char* argv[]){
    bool isDirected = false;

    if(argc = 3){
        if(argv[2] = "directed"){
            isDirected = true;
        }
        string fileName(argv[1]);
        AdjacencyGraph* graph = createGraph(fileName, isDirected);

    }
    
}