#include "adjacency.h"
#include "util.h"

#include <iostream>
#include <iomanip>

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

    cout << setprecision(4) << fixed;

    if(argc == 3){
        if(argv[2][0] != 'u'){
            isDirected = true;
        }
        string fileName(argv[1]);
        graph = createGraph(fileName, isDirected);
    }

    while(query != "stop"){
        cin >> query;
        if(query == "find"){
            cin >> source;
            cin >> destination;
            cin >> flag;
            cout << "Query: find " << source << " " << destination << " " << flag << "\n";
            if(source < graph->getGraphLength() && source != destination && (flag == 0 || flag == 1)){
                if(flag == 1){
                    writeFlag = true;
                }
                else{
                    writeFlag = false;
                }
                recentFind = Dijkstra(graph, source, destination, writeFlag);
                hasSearched = true;
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
            cout << "Query: write path " << s << " " << d << "\n";
            if(!hasSearched){
                cout << "Error: no path computation done\n";
            }
            else if(source != s || d > graph->getGraphLength()-1){
                cout << "Error: invalid source destination pair\n";
                //cout << "DEBUG: source is " << source << ", s is " << s << ", d is " << d << ", and the length of the graph is " << graph->getGraphLength() << "\n";
            }
            else if(recentFind[d]->getColor() == 3){
                cout << "Shortest path: <";
                findShortestPath(recentFind, s, d);
                cout << ">\n";
                cout << "The path weight is:\t" << recentFind[d]->getDistance() << "\n";
            }
            else if(recentFind[d]->getColor() == 2){
                cout << "Path not known to be shortest: <";
                findShortestPath(recentFind, s, d);
                cout << ">\n";
                cout << "The path weight is:\t" << recentFind[d]->getDistance() << "\n";
            }

        }
    }
    cout << "Query: stop\n";
    //gotta free memory here

    
}