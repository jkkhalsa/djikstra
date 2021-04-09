#include "adjacency.h"
#include "util.h"

#include <iostream>

using namespace std;


int main(int argc, char* argv[]){
    bool isDirected = false;
    bool writeFlag = false;
    string query = "this is a test";
    string word;
    AdjacencyGraph* graph;

    Vertex** recentFind;

    int source;
    int destination;
    int flag;

    if(argc == 3){
        if(argv[2][0] != 'u'){
            isDirected = true;
            cout << "isDirected is true\n";
        }
        string fileName(argv[1]);
        graph = createGraph(fileName, isDirected);
        cout << "got out of graph building\n";
        cout << graph->printGraph();
    }

    while(query != "stop"){
        cin >> query;
        if(query == "find"){
            cin >> source;
            cin >> destination;
            cin >> flag;
            if(source < graph->getGraphLength() && source != destination && (flag == 0 || flag == 1)){
                if(flag == 1){
                    writeFlag = true;
                }
                else{
                    writeFlag = false;
                }
                recentFind = Dijkstra(graph, source, destination, flag);
            }
            else{
                cout << "Error: invalid find query\n";
            }  
        }
    }
    //gotta free memory here

    
}