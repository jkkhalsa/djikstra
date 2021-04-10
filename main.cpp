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
    bool hasSearched = false;

    int source;
    int s;
    int destination;
    int d;
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
                recentFind = Dijkstra(graph, source, destination, writeFlag);
                hasSearched = true;
                cout << "returned from dijkstra\n";
                /*//debug
                cout << "printing results of graph\n";
                cout << "recent find's first node is " << recentFind[1]->getNode();
                for(int i = 1; i < graph->getGraphLength(); i++){
                    recentFind[i]->printVertex();
                }*/
            }
            else{
                cout << "Error: invalid find query\n";
            }  
        }
        if(query == "write"){
            cin >> query; //to get rid of "path"
            cin >> s;
            cin >> d;
            if(!hasSearched){
                cout << "Error: no path computation done\n";
            }
            else if(source != s || d > graph->getGraphLength()-1){
                cout << "Errror: invalid source destination pair\n";
                //cout << "DEBUG: source is " << source << ", s is " << s << ", d is " << d << ", and the length of the graph is " << graph->getGraphLength() << "\n";
            }
            else if(recentFind[d]->getColor() == 3){
                cout << "Shortest path: <";
                cout << findShortestPath(recentFind, s, d);
            }

        }
    }
    cout << "Query: stop\n";
    //gotta free memory here

    
}